#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>
#include <locale>

using namespace std;

struct patient
{
    string patName, patEmail, patDocdecision, patGender;
    string patMedicine[100];
    unsigned long long int patIC;
    double patMedQuantity[100], patMedPrice[100], patTotal;
    int patCount;

    patient *patNext;

}*patientH;

struct nurse
{
    string nurName, nurPhone, nurGender, nurPosition;
    unsigned long long nurIC;
    nurse *nurNext;

}*nurH;

struct doctor
{
    string docName, docPhone, docSpecialty, docGender;
    unsigned long long docIC;
    doctor *docNext;

}*docH;

struct medicine
{
    string medName;
    double medPrice, medQuantity;
    medicine *medNext;

}*medH;

class clinic
{
private:
    unsigned long long int ic;
    double price, quantity;
    string name, email, gender, position, phoneNumber, specialty, nameOfMedicine;

public:
    void patientTitle();
    void staffTitle();
    void load();
    void addEditRemove();
    void addData();
    void editData();
    void removeData();

    //FUNCTION DECLARATION FOR PATIENT
    void displayPatient();
    void displayPatient2nd();
    void patientBill(string docdecision, string medicine[], double quantityy[], double medPrice[], double docAppoint, int count);
    void savePatientHistory(string docdecision, string medicine[], double quantityy[], double medPrice[], double docAppoint, int count);
    string readPatientHistory(int k);
    void storePatientHistoryInLinkedList();
    void addPatientHistoryInLinkedList(string b);
    void displayPatientHistory();

    //FUNCTION DECLARATION FOR NURSE
    string readNurseData(int k);
    void saveNurseData();
    void storeNurseDataInLinkedList();
    void addNurseDataInLinkedList(string );
    void nurseAddingDisplay();
    void editNurseData();
    void saveEditNurseData(string b);
    void displayNurseInformation();
    void removeNurseInformation();


    //FUNCTION DECLARATION FOR DOCTOR

    string readDoctorData(int k);
    void saveDoctorData();
    void storeDoctorDataInLinkedList();
    void addDoctorDataInLinkedList(string );
    void doctorAddingDisplay();
    void editDoctorData();
    void saveEditDoctorData(string b);
    void displayDoctorInformation();
    void removeDoctorInformation();

    //FUNCTION DECLARATION FOR MEDICINE

    string readMedicineData(int k);
    void saveMedicineData();
    void storeMedicineDataInLinkedList();
    void addMedicineDataInLinkedList(string );
    void editMedicineData();
    void saveEditMedicineData(string b);
    void displayMedicineInformation();
};

int main()
{
    int select1, select2;
    clinic cli;
    cli.storePatientHistoryInLinkedList();
    cli.storeNurseDataInLinkedList();
    cli.storeMedicineDataInLinkedList();

    while(1)
    {
        cout << "\n\n     =====================================================================\n\n\n";
        cout << "                        CLINIC BIJAN INFORMATION SYSTEM                   \n\n\n";
        cout << "     =====================================================================\n\n\n";

        cout << "\n\n\t\t\t      1. PATIENT\n\t\t\t      2. STAFF\n\t\t\t      3. EXIT\n\t\t\t      SELECTION: ";
        cin >> select1;

        switch(select1)
        {
        case 1:
            cli.load();
            cli.displayPatient();
            patientH = 0;
            cli.storePatientHistoryInLinkedList();


            cli.load();
            break;

        case 2:
            cli.load();

            while(1)
            {
                cout << "\n\n     =====================================================================\n\n\n";
                cout << "                    CLINIC BIJAN STAFF INFORMATION SYSTEM                   \n\n\n";
                cout << "     =====================================================================\n\n\n";
                cout << "\n\n\n\n\t\t\t1. PATIENT'S HISTORY";
                cout << "\n\t\t\t2. DOCTOR'S INFORMATION";
                cout << "\n\t\t\t3. NURSE'S INFORMATION";
                cout << "\n\t\t\t4. MEDICINE'S INFORMATION";
                cout << "\n\t\t\t5. ADD, EDIT & REMOVE DATA";
                cout << "\n\t\t\t6. EXIT";
                cout << "\n\t\t\tSELECTION: ";
                cin >> select2;

                switch(select2)
                {
                case 1:
                    patientH = 0;
                    cli.storePatientHistoryInLinkedList();
                    cli.displayPatientHistory();
                    cli.load();
                    break;

                case 2:
                    docH = 0;
                    cli.storeDoctorDataInLinkedList();
                    cli.displayDoctorInformation();
                    cli.load();
                    break;

                case 3:
                    nurH = 0;
                    cli.storeNurseDataInLinkedList();
                    cli.displayNurseInformation();
                    cli.load();
                    break;

                case 4:
                    medH = 0;
                    cli.storeMedicineDataInLinkedList();
                    //cout << "kakaka:" << medH->medName;
                    cli.displayMedicineInformation();
                    cli.load();
                    break;

                case 5:
                    cli.addEditRemove();
                    cli.load();
                    break;

                case 6:
                    cli.load();
                    break;

                default:
                    cout << "\n\n\t\tWrong Selection. Please try again.";
                    cli.load();
                    break;
                }

                if(select2 == 6)
                {
                    break;
                }
            }

            //cli.load();
            break;

        case 3:

            return 0;

        default:
            cout << "\n\n\t\tWrong Selection. Please Try Again.";
            cli.load();
            break;
        }




    }
}

//==================================================FUNCTION DEFINITION====================================================================================

void clinic :: patientTitle()
{
    cout << "\n\n     =====================================================================\n\n\n";
    cout << "                  CLINIC BIJAN PATIENT'S INFORMATION SYSTEM                   \n\n\n";
    cout << "     =====================================================================\n\n\n";
}

void clinic :: staffTitle()
{
    cout << "\n\n     =====================================================================\n\n\n";
    cout << "                    CLINIC BIJAN STAFF INFORMATION SYSTEM                   \n\n\n";
    cout << "     =====================================================================\n\n\n";
}

void clinic :: load()
{
    cout << "\n\n\t\t";
    system("pause");
    system("cls");
}

void clinic :: addEditRemove()
{
    int select;
    load();
    while(1)
    {
        staffTitle();

        cout << "\t\t\t1. ADD DATA\n\t\t\t2. EDIT DATA\n\t\t\t3. REMOVE DATA\n\t\t\t4. EXIT\n\t\t\tSELECTION: ";
        cin >> select;

        switch(select)
        {
        case 1:
            addData();
            load();
            break;

        case 2:
            editData();
            load();
            break;

        case 3:
            removeData();
            load();
            break;

        case 4:

            break;
        }

        if(select == 4)
        {
            break;
        }
    }
}

//=======================================FUNCTION DEFINITION FOR PATIENT==================================================================================

void clinic :: displayPatient()
{
    string decision;
    int selection;
    bool success = false;

    while(1)
    {
        patientTitle();

        cout << "\tDoes the patient already came to the clinic?(y/n): ";
        cin >> std::ws;
        getline(cin, decision);

        if(decision == "y" || decision == "Y")
        {
            while(1)
            {
                load();
                patientTitle();

                cout << "\t\t  1. ENTER THE PATIENT I/C NUMBER\n\t\t  2. EXIT\n\t\t  SELECTION: ";
                cin >> selection;

                switch(selection)
                {
                case 1:
                    cout << "\n\n\t\tPLEASE ENTER THE PATIENT I/C NUMBER: ";
                    cin >> ic;

                    patient *temp;
                    temp = patientH;

                    while(temp)
                    {
                        if(temp->patIC == ic)
                        {
                            name = temp->patName;
                            gender = temp->patGender;
                            email = temp->patEmail;
                            success = true;
                            break;
                        }
                        temp = temp->patNext;
                    }

                    if(success == false)
                    {
                        cout << "\n\n\t\tPATIENT'S I/C NUMBER WAS NOT FOUND! PLEASE TRY AGAIN.";
                    }

                    break;

                case 2:
                    break;

                default:
                    cout << "\n\n\t\t\tWRONG INPUT! PLEASE TRY AGAIN.";
                    //load();
                    break;
                }

                if(success == true)
                {
                    load();
                    displayPatient2nd();
                    break;
                }
                else if(selection == 2)
                {
                    break;
                }

            }

            break;

        }

        else if(decision == "n" || decision == "N")
        {
            load();
            patientTitle();

            cout << "\t\tPATIENT'S NAME: ";
            //cin >> std::ws;
            getline(cin, name);
            cout << "\t\tI/C NUMBER: ";
            cin >> ic;
            cout << "\t\tGENDER: ";
            cin >> std::ws;
            getline(cin, gender);
            cout << "\t\tEMAIL: ";
            cin >> std::ws;
            getline(cin, email);
            load();
            displayPatient2nd();

            break;
        }

        else
        {
            cout << "\n\n\n\t\t\tWRONG INPUT! PLEASE TRY AGAIN\n";
            load();
        }
    }
    //end of while loop




}

void clinic :: displayPatient2nd()
{
    string docdecision, medicinee[100];
    int selection, selection2;
    double quantityy[100], askQuantity, medPrice[100], docAppoint;
    char a[33];
    string c;
    medicine *temp;

    //while loop for asking either the patient sees the doctor or not
    while(1)
    {
        patientTitle();

        cout << "\t\tPATIENT'S NAME: ";
        for(int i=0; i<name.length(); i++)
        cout << toupper(name[i], locale());
        cout << "\n\t\tI/C NUMBER: " << ic;
        cout << "\n\t\tGENDER: ";
        for(int i=0; i<gender.length(); i++)
        cout << toupper(gender[i], locale());
        cout << "\n\t\tEMAIL: " << email;
        cout << "\n\t\tDOES THE PATIENT MEET THE DOCTOR?(Y/N): ";
        cin >> std::ws;
        getline(cin, docdecision);

        if(docdecision == "y" || docdecision == "Y")
        {
            docAppoint = 10.00;
            load();
            break;
        }

        else if(docdecision == "n" || docdecision == "N")
        {
            docAppoint = 0;
            load();
            break;
        }

        else
        {
            cout << "\n\n\n\t\t\tWRONG INPUT! PLEASE TRY AGAIN\n";
            load();
        }
    }


    // for medicine section
    int count=0;
    while(1)
    {
        int k=0;
        patientTitle();

        if(count > 0)
        {
            cout << "\t   ===========================================================\n";
            cout << "\t                     LIST OF MEDICINE TAKEN\n";
            cout << "\t   ===========================================================\n";
            cout << "\t      NAME OF MEDICINE                              QUANTITY\n";
            for(int i= 0; i<count; i++)
            {
                cout << "\t    " << medicinee[i] << "     " << quantityy[i] << endl;
            }
            cout << "\n\n\n";
        }

        cout << "\t\tTYPE OF MEDICINE TAKEN\n";
        cout << "\t\t1. Cough and cold medicines (RM 10.00)\n";
        cout << "\t\t2. Aspirin for pain and fever (RM 12.00)\n";
        cout << "\t\t3. Paracetamol (Pain Killer) (RM 5.00)\n";
        cout << "\t\t4. Antibiotics (RM 15.00)\n";
        cout << "\t\t5. Antiviral flu medicines (oseltamivir (Tamiflu)) (RM 13.00)\n";
        cout << "\t\t6. Exit\n";
        cout << "\t\tSELECTION: ";
        cin >> selection2;



        switch (selection2)
        {
        case 1:
            cout << "\t\tQUANTITY OF THE MEDICINE: ";
            cin >> askQuantity;

            nameOfMedicine = "Cough and cold medicines";
            price = 10.00;
            c = itoa(selection2, a, 10);
            temp = medH;
            while(temp)
            {
                if(temp->medName == nameOfMedicine)
                {
                    break;
                }
                temp = temp->medNext;
            }

            quantity = temp->medQuantity - askQuantity;
            if(quantity < 0)
            {
                cout << "\n\n\t\t\tOUT OF STOCK!";
                load();
                break;
            }

            saveEditMedicineData(c);

            for(int i=0; i<count; i++)
            {

                if(medicinee[i] == "Cough and cold medicines                       ")
                {
                    quantityy[i]+= askQuantity;
                    k = i;
                    break;
                }
            }
            if(medicinee[k] == "Cough and cold medicines                       ")
            {
                load();
                break;
            }
            else
            {
                medicinee[count] = "Cough and cold medicines                       ";
                quantityy[count] = askQuantity;
                medPrice[count] = 10.00;
                count++;
                load();
            }

            break;

        case 2:
            cout << "\t\tQUANTITY OF THE MEDICINE: ";
            cin >> askQuantity;

            nameOfMedicine = "Aspirin for pain and fever";
            price = 12.00;
            c = itoa(selection2, a, 10);
            temp = medH;
            while(temp)
            {
                if(temp->medName == nameOfMedicine)
                {
                    break;
                }
                temp = temp->medNext;
            }

            quantity = temp->medQuantity - askQuantity;
            if(quantity < 0)
            {
                cout << "\n\n\t\t\tOUT OF STOCK!";
                load();
                break;
            }

            saveEditMedicineData(c);

            for(int i=0; i<count; i++)
            {
                if(medicinee[i] == "Aspirin for pain and fever                     ")
                {
                    quantityy[i]+= askQuantity;
                    k=i;
                    break;
                }
            }
            if(medicinee[k] == "Aspirin for pain and fever                     ")
            {
                load();
                break;
            }
            else
            {
                medicinee[count] = "Aspirin for pain and fever                     ";
                quantityy[count] = askQuantity;
                medPrice[count] = 12.00;
                count++;
                load();
            }


            break;

        case 3:
            cout << "\t\tQUANTITY OF THE MEDICINE: ";
            cin >> askQuantity;

            nameOfMedicine = "Paracetamol (Pain Killer)";
            price = 5.00;
            c = itoa(selection2, a, 10);
            temp = medH;
            while(temp)
            {
                if(temp->medName == nameOfMedicine)
                {
                    break;
                }
                temp = temp->medNext;
            }

            quantity = temp->medQuantity - askQuantity;
            if(quantity < 0)
            {
                cout << "\n\n\t\t\tOUT OF STOCK!";
                load();
                break;
            }

            saveEditMedicineData(c);

            for(int i=0; i<count; i++)
            {
                if(medicinee[i] == "Paracetamol (Pain Killer)                      ")
                {
                    quantityy[i]+= askQuantity;
                    k=i;
                    break;
                }
            }
            if(medicinee[k] == "Paracetamol (Pain Killer)                      ")
            {
                load();
                break;
            }
            else
            {
                medicinee[count] = "Paracetamol (Pain Killer)                      ";
                quantityy[count] = askQuantity;
                medPrice[count] = 5.00;
                count++;
                load();
                break;
            }

        case 4:
            cout << "\t\tQUANTITY OF THE MEDICINE: ";
            cin >> askQuantity;

            nameOfMedicine = "Antibiotics";
            price = 15.00;
            c = itoa(selection2, a, 10);
            temp = medH;
            while(temp)
            {
                if(temp->medName == nameOfMedicine)
                {
                    break;
                }
                temp = temp->medNext;
            }

            quantity = temp->medQuantity - askQuantity;
            if(quantity < 0)
            {
                cout << "\n\n\t\t\tOUT OF STOCK!";
                load();
                break;
            }

            saveEditMedicineData(c);

            for(int i=0; i<count; i++)
            {
                if(medicinee[i] == "Antibiotics                                    ")
                {
                    quantityy[i]+= askQuantity;
                    k=i;
                    break;
                }
            }
            if(medicinee[k] == "Antibiotics                                    ")
            {
                load();
                break;
            }
            else
            {
                medicinee[count] = "Antibiotics                                    ";
                quantityy[count] = askQuantity;
                medPrice[count] = 15.00;
                count++;
                load();
                break;
            }

        case 5:
            cout << "\t\tQUANTITY OF THE MEDICINE: ";
            cin >> askQuantity;

            nameOfMedicine = "Antiviral flu medicines (oseltamivir (Tamiflu))";
            price = 13.00;
            c = itoa(selection2, a, 10);
            temp = medH;
            while(temp)
            {
                if(temp->medName == nameOfMedicine)
                {
                    break;
                }
                temp = temp->medNext;
            }

            quantity = temp->medQuantity - askQuantity;
            if(quantity < 0)
            {
                cout << "\n\n\t\t\tOUT OF STOCK!";
                load();
                break;
            }

            saveEditMedicineData(c);

            for(int i=0; i<count; i++)
            {
                if(medicinee[i] == "Antiviral flu medicines (oseltamivir (Tamiflu))")
                {
                    quantityy[i]+= askQuantity;
                    k=i;
                    break;
                }
            }
            if(medicinee[k] == "Antiviral flu medicines (oseltamivir (Tamiflu))")
            {
                load();
                break;
            }
            else
            {
                medicinee[count] = "Antiviral flu medicines (oseltamivir (Tamiflu))";
                quantityy[count] = askQuantity;
                medPrice[count] = 13.00;
                count++;
                load();
                break;
            }


        case 6:
            load();
            break;
        }

        if(selection2 == 6)
        {
            break;
        }

    }

    patientTitle();
    patientBill(docdecision, medicinee, quantityy, medPrice, docAppoint, count);


}

void clinic :: patientBill(string docdecision, string medicine[], double quantityy[], double medPrice[], double docAppoint, int count)
{
    cout << "\t**********************************************************\n";
    cout << "\t                           BILL\n";
    cout << "\t**********************************************************\n";
    cout << "\n\t          PATIENT'S NAME: ";
    for(int i=0; i<name.length(); i++)
        cout << toupper(name[i], locale());//<< name;
    cout << "\n\t              I/C NUMBER: " << ic;
    cout << "\n\t                  GENDER: ";
    for(int i=0; i<gender.length(); i++)
        cout << toupper(gender[i], locale());//<< gender;
    cout << "\n\t                   EMAIL: " << email;
    cout << "\n\t APPOINTMENT WITH DOCTOR: ";
    if(docdecision == "y" || docdecision == "Y")
        cout << "YES\n\n";
    else if(docdecision == "n" || docdecision == "N")
        cout << "NO\n\n";

    double total=0;
    cout << "\t**********************************************************\n";
    cout << "\t                  LIST OF MEDICINE TAKEN\n";
    cout << "\t**********************************************************\n";
    cout << "\t      NAME OF MEDICINE                              QUANTITY\n";
    for(int i= 0; i<count; i++)
    {
        cout << "\t    " << medicine[i] << "     " << quantityy[i] << endl;
        total = total +(medPrice[i]*quantityy[i]);
    }
    cout << "\n\n";
    cout << fixed << showpoint << setprecision(2);
    cout << "\t                                           TOTAL: RM " << total+docAppoint;

    savePatientHistory(docdecision, medicine, quantityy, medPrice, docAppoint, count);

}

void clinic :: savePatientHistory(string docdecision, string medicine[], double quantityy[], double medPrice[], double docAppoint, int count)
{
    ofstream file;
    string b = readPatientHistory(1);
    double total=0;

    file.open(("Patient Database/patient"+b+".txt").c_str());


    /*string patName, patEmail, patDocdecision, ;
    string patMedicine[100];
    unsigned long long int patIC;
    double patMedQuantity[100], patMedPrice[100];
    int patCount;*/

    if(patientH == 0)
    {
        patientH = new patient;
        patientH->patName = name;
        patientH->patIC = ic;
        patientH->patGender = gender;
        patientH->patEmail = email;
        patientH->patDocdecision = docdecision;
        patientH->patCount = count;

        for(int i=0; i<count; i++)
        {
            patientH->patMedicine[i] = medicine[i];
            patientH->patMedQuantity[i] = quantityy[i];
            patientH->patMedPrice[i]= medPrice[i];
            total = total +(medPrice[i]*quantityy[i]);
        }
        patientH->patTotal = total*docAppoint;
        patientH->patNext = NULL;

    }

    else
    {
        patient *temp, *newAccDb;

        newAccDb = new patient;
        temp = patientH;

        while(temp -> patNext != NULL)
        {
            temp = temp -> patNext;
        }

        newAccDb->patName = name;
        newAccDb->patIC = ic;
        newAccDb->patGender = gender;
        newAccDb->patEmail = email;
        newAccDb->patDocdecision = docdecision;
        newAccDb->patCount = count;

        for(int i=0; i<count; i++)
        {
            newAccDb->patMedicine[i] = medicine[i];
            newAccDb->patMedQuantity[i] = quantityy[i];
            newAccDb->patMedPrice[i]= medPrice[i];
            total = total +(medPrice[i]*quantityy[i]);
        }
        newAccDb->patTotal = total*docAppoint;


        temp->patNext = newAccDb;
        newAccDb->patNext= NULL;
    }

    total=0;
    for(int i=0; i<name.length(); i++)
        file << toupper(name[i], locale());
    file << endl;
    file << ic << endl;
    for(int i=0; i<gender.length(); i++)
        file << toupper(gender[i], locale());
    file << endl;
    file << email << endl;
    file << docdecision << endl;
    file << count << endl;
    for(int i=0; i<count; i++)
    {
        file << medicine[i] << "\n" << medPrice[i] << "\n" << quantityy[i] << endl;
        total = total +(medPrice[i]*quantityy[i]);
    }
    file << total+docAppoint;
    file.close();


}

string clinic :: readPatientHistory(int k)
{
    ifstream file;
    char a[33];
    string b;

      b = itoa(k, a, 10);
      file.open(("Patient Database/patient" + b +".txt").c_str());

      if(file.is_open())
      {
          file.close();
          return readPatientHistory(k+1);

      }
      else
      {
          return itoa(k, a, 10);
      }


}

void clinic :: storePatientHistoryInLinkedList()
{
    ifstream file;
    int k = 1;
    char a[33];
    string b;

    while(1)
    {
      b = itoa(k, a, 10);
      file.open(("Patient Database/patient" + b +".txt").c_str());

      if(file.is_open())
      {
          addPatientHistoryInLinkedList(b);
          file.close();
      }
      else
      {
          break;
      }
      k++;

    }
}

void clinic :: addPatientHistoryInLinkedList(string b)
{
    ifstream file;

    file.open(("Patient Database/patient"+b+".txt").c_str());


    /*string patName, patEmail, patDocdecision, ;
    string patMedicine[100];
    unsigned long long int patIC;
    double patMedQuantity[100], patMedPrice[100];
    int patCount;*/

    if(patientH == 0)
    {
        patientH = new patient;

        file >> std::ws;
        getline(file, patientH->patName);
        file >> patientH->patIC;
        file >> patientH->patGender;
        file >> patientH->patEmail;
        file >> patientH->patDocdecision;
        file >> patientH->patCount;

        for(int i=0; i<patientH->patCount; i++)
        {
            file >> std::ws;
            getline(file, patientH->patMedicine[i]);
            file >> patientH->patMedPrice[i];
            file >> patientH->patMedQuantity[i];

        }
        file >> patientH->patTotal;
        patientH->patNext = NULL;

    }

    else
    {
        patient *temp, *newAccDb;

        newAccDb = new patient;
        temp = patientH;

        while(temp -> patNext != NULL)
        {
            temp = temp -> patNext;
        }
        file >> std::ws;
        getline(file, newAccDb->patName);
        file >> newAccDb->patIC;
        file >> newAccDb->patGender;
        file >> newAccDb->patEmail;
        file >> newAccDb->patDocdecision;
        file >> newAccDb->patCount;

        for(int i=0; i<newAccDb->patCount; i++)
        {
            file >> std::ws;
            getline(file, newAccDb->patMedicine[i]);
            file >> newAccDb->patMedPrice[i];
            file >> newAccDb->patMedQuantity[i];
        }
        file >> newAccDb->patTotal;


        temp->patNext = newAccDb;
        newAccDb->patNext= NULL;
    }
}

void clinic :: displayPatientHistory()
{
    patient *temp;
    int select, selectPat;
    load();
    while(1)
    {
        staffTitle();
        temp = patientH;
        int count=1;

        cout << "\t\tLIST OF PATIENT HISTORY:\n\n";

        while(temp)
        {
            if(temp != 0)
            {
                cout << "\t\t" << count << ". " << temp->patName << "\n";
                count++;
            }
            temp = temp->patNext;

        }


        cout << "\n\n\t\t1. SELECT WHICH PATIENT'S HISTORY TO DISPLAY\n\t\t2. EXIT\n\t\tSELECT: ";
        cin >> select;

        switch (select)
        {
        case 1:
            patient *moreTemp;
            moreTemp = patientH;
            cout << "\n\n\t\tPATIENT NUMBER: ";
            cin >> selectPat;

            if(selectPat <= count)
            {
                for(int i=0; i<selectPat; i++)
                {
                    if(moreTemp->patNext != NULL)
                    {
                        if(i!=selectPat-1)
                        {
                            moreTemp = moreTemp->patNext;
                        }

                    }
                }
            }

            cout << "\n\n\t\tSELECTED PATIENT NUMBER: " << selectPat;
            cout << "\n**************************************************************************";
            cout << "\n\n\t\t\t       NAME: " << moreTemp->patName;
            cout << "\n\t\t\t I/C NUMBER: " << moreTemp->patIC;
            cout << "\n\t\t\t     GENDER: " <<  moreTemp->patGender;
            cout << "\n\t\t\t      EMAIL: " << moreTemp->patEmail;
            cout << "\n\tAPPOINTMENT WITH THE DOCTOR: ";
            if(moreTemp->patDocdecision == "y" || moreTemp->patDocdecision == "Y")
            {
                cout << "YES";
            }
            else if(moreTemp->patDocdecision == "n" || moreTemp->patDocdecision == "N")
            {
                cout << "NO";
            }
            cout << "\n\n\tTYPE OF MEDICINE TAKEN\t\t\t\tQUANTITY\n";
            for(int i=0; i<moreTemp->patCount; i++)
            {
                cout << "\t" << moreTemp->patMedicine[i] << "\t " << moreTemp->patMedQuantity[i] << endl;
            }
            cout << "\n\t\t\tTOTAL BILL: RM " << moreTemp->patTotal;
            load();
            break;

        case 2:

            break;

        default:
            cout << "\n\n\t\tWRONG INPUT PLEASE TRY AGAIN!\n";
            load();
            break;
        }

        if(select == 2)
        {
            break;
        }

    }

}

//======================================================FUNCTION DEFINITION FOR NURSE===================================================================

string clinic :: readNurseData(int k)
{
    ifstream file;
    char a[33];
    string b;

      b = itoa(k, a, 10);
      file.open(("Nurse Database/nurse" + b +".txt").c_str());

      if(file.is_open())
      {
          file.close();
          return readNurseData(k+1);

      }
      else
      {
          return itoa(k, a, 10);
      }


}

void clinic :: saveNurseData()
{
    ofstream file;
    string b = readNurseData(1);

    file.open(("Nurse Database/nurse"+b+".txt").c_str());

    if(nurH == 0)
    {
        nurH = new nurse;
        nurH->nurName = name;
        nurH->nurIC = ic;
        nurH->nurGender = gender;
        nurH->nurPhone = phoneNumber;
        nurH->nurPosition = position;

        nurH->nurNext = NULL;

    }

    else
    {
        nurse *temp, *newAccDb;

        newAccDb = new nurse;
        temp = nurH;

        while(temp -> nurNext != NULL)
        {
            temp = temp -> nurNext;
        }

        newAccDb->nurName = name;
        newAccDb->nurIC = ic;
        newAccDb->nurGender = gender;
        newAccDb->nurPhone = phoneNumber;
        newAccDb->nurPosition = position;

        temp->nurNext = newAccDb;
        newAccDb->nurNext= NULL;
    }

    for(int i=0; i<name.length(); i++)
        file << toupper(name[i], locale());
    file << endl;
    file << ic << endl;
    for(int i=0; i<gender.length(); i++)
        file << toupper(gender[i], locale());
    file << endl;
    file << phoneNumber << endl;
    file << position;
    file.close();

}

void clinic :: addNurseDataInLinkedList(string b)
{
    ifstream file;

    file.open(("Nurse Database/nurse"+b+".txt").c_str());

    if(nurH == 0)
    {
        nurH = new nurse;

        file >> std::ws;
        getline(file, nurH->nurName);
        file >> nurH->nurIC;
        file >> std::ws;
        file >> nurH->nurGender;
        file >> std::ws;
        file >> nurH->nurPhone;
        file >> std::ws;
        getline(file, nurH->nurPosition);

        nurH->nurNext = NULL;

    }

    else
    {
        nurse *temp, *newAccDb;

        newAccDb = new nurse;
        temp = nurH;

        while(temp->nurNext != NULL)
        {
            temp = temp->nurNext;
        }

        file >> std::ws;
        getline(file, newAccDb->nurName);
        file >> newAccDb->nurIC;
        file >> newAccDb->nurGender;
        file >> newAccDb->nurPhone;
        file >> std::ws;
        getline(file, newAccDb->nurPosition);

        temp->nurNext = newAccDb;
        newAccDb->nurNext= NULL;
    }
}

void clinic :: storeNurseDataInLinkedList()
{
    ifstream file;
    int k = 1;
    char a[33];
    string b;

    while(1)
    {
      b = itoa(k, a, 10);
      file.open(("Nurse Database/nurse" + b +".txt").c_str());

      if(file.is_open())
      {
          addNurseDataInLinkedList(b);
          file.close();
      }
      else
      {
          break;
      }
      k++;

    }
}

void clinic :: nurseAddingDisplay()
{
    load();
    staffTitle();
    int pick;

    cout << "\t\t\t        NAME: ";
    cin >> std::ws;
    getline(cin, name);
    cout << "\t\t\t  I/C NUMBER: ";
    cin >> ic;
    cout << "\t\t\t      GENDER: ";
    cin >> gender;
    cout << "\t\t\tPHONE NUMBER: ";
    cin >> phoneNumber;
    while(1)
    {
        load();
        staffTitle();


        cout << "\t\t\t        NAME: ";
        for(int i=0; i<name.length(); i++)
            cout << toupper(name[i], locale());
        cout << "\n\t\t\t  I/C NUMBER: " << ic;
        cout << "\n\t\t\t      GENDER: ";
        for(int i=0; i<gender.length(); i++)
            cout << toupper(gender[i], locale());
        cout << "\n\t\t\tPHONE NUMBER: " << phoneNumber;
        cout << "\n\t\t\tPOSITION:\n\t\t\t1. RECEIPTIONIST\n\t\t\t2. DOCTOR'S HELPER\n\t\t\t3. PHARMACIES\n\t\t\tSELECTION: ";
        cin >> pick;

        switch(pick)
        {
        case 1:
            position = "RECEIPTIONIST";
            break;
        case 2:
            position = "DOCTOR'S HELPER";
            break;
        case 3:
            position = "PHARMACIES";
            break;
        default:
            cout << "\n\n\t\t\tWRONG INPUT! PLEASE TRY AGAIN.";
            break;
        }

        if(pick == 1 || pick == 2 || pick == 3)
        {
            break;
        }
    }

    nurH = 0;
    saveNurseData();
    storeNurseDataInLinkedList();
}

void clinic :: saveEditNurseData(string b)
{
    ofstream file;

    file.open(("Nurse Database/nurse"+b+".txt").c_str());

    for(int i=0; i<name.length(); i++)
        file << toupper(name[i], locale());
    file << endl;
    file << ic << endl;
    for(int i=0; i<gender.length(); i++)
        file << toupper(gender[i], locale());
    file << endl;
    file << phoneNumber << endl;
    file << position;

    file.close();
}

void clinic :: editNurseData()
{
    nurse *temp;
    int select, selectPat, pick;
    int editselect;
    string c;
    char a[33];

    load();

    while(1)
    {
        staffTitle();
        nurH = 0;
        storeNurseDataInLinkedList();
        temp = nurH;
        int count=1;

        cout << "\t\tLIST OF NURSE'S INFORMATION:\n\n";

        while(temp)
        {
            if(temp != NULL)
            {
                    cout << "\t\t" << count << ". " << temp->nurName << "\n";
                    count++;
            }
            temp = temp->nurNext;
        }


        cout << "\n\n\t\t1. SELECT WHICH NURSE'S INFORMATION TO DISPLAY\n\t\t2. EXIT\n\t\tSELECT: ";
        cin >> select;

        switch (select)
        {
        case 1:
            nurse *moreTemp;
            moreTemp = nurH;
            cout << "\n\n\t\tPATIENT NUMBER: ";
            cin >> selectPat;

            if(selectPat <= count)
            {
                for(int i=0; i<selectPat; i++)
                {
                    if(moreTemp->nurNext != NULL)
                    {
                        if(i!=selectPat-1)
                        {
                            moreTemp = moreTemp->nurNext;
                        }

                    }
                }
            }

            load();
            c = itoa(selectPat, a, 10);
            while(1)
            {
                staffTitle();
                cout << "\n\n\t\tSELECTED PATIENT NUMBER: " << selectPat;
                cout << "\n**************************************************************************";
                cout << "\n\n\t\t      NAME: " << moreTemp->nurName;
                cout << "\n\t\t  I/C NUMBER: " << moreTemp->nurIC;
                cout << "\n\t\t      GENDER: " << moreTemp->nurGender;
                cout << "\n\t\tPHONE NUMBER: " << moreTemp->nurPhone;
                cout << "\n\t\t    POSITION: " << moreTemp->nurPosition;


                cout << "\n\n\n\t\tPLEASE SELECT WHICH THING TO EDIT\n\t\t\t1. NAME\n\t\t\t2. I/C NUMBER\n\t\t\t3. GENDER\n\t\t\t4. PHONE NUMBER";
                cout << "\n\t\t\t5. POSITION\n\t\t\t6. EXIT\n\t\t\tSELECTION: ";
                cin >> editselect;
                switch(editselect)
                {
                case 1:
                    cout << "\n\n\t\tPLEASE ENTER THE NEW NAME: ";
                    cin >> std::ws;
                    getline(cin, name);
                    ic = moreTemp->nurIC;
                    gender = moreTemp->nurGender;
                    phoneNumber = moreTemp->nurPhone;
                    position = moreTemp->nurPosition;
                    cout << "\n\n\t\t\tEDITED...";
                    saveEditNurseData(c);
                    break;

                case 2:
                    cout << "\n\n\t\tPLEASE ENTER THE NEW I/C NUMBER: ";
                    cin >> ic;
                    name = moreTemp->nurName;
                    gender = moreTemp->nurGender;
                    phoneNumber = moreTemp->nurPhone;
                    position = moreTemp->nurPosition;
                    cout << "\n\n\t\t\tEDITED...";
                    saveEditNurseData(c);
                    break;

                case 3:
                    cout << "\n\n\t\tPLEASE ENTER THE NEW GENDER: ";
                    cin >> gender;
                    ic = moreTemp->nurIC;
                    name = moreTemp->nurName;
                    phoneNumber = moreTemp->nurPhone;
                    position = moreTemp->nurPosition;
                    cout << "\n\n\t\t\tEDITED...";
                    saveEditNurseData(c);
                    break;

                case 4:
                    cout << "\n\n\t\tPLEASE ENTER THE NEW PHONE NUMBER: ";
                    cin >> phoneNumber;
                    ic = moreTemp->nurIC;
                    gender = moreTemp->nurGender;
                    name = moreTemp->nurName;
                    position = moreTemp->nurPosition;
                    cout << "\n\n\t\t\tEDITED...";
                    saveEditNurseData(c);
                    break;

                case 5:
                    while(1)
                    {
                        cout << "\n\n\t\tPLEASE ENTER THE NEW POSITION: \n";
                        cout << "\n\t\t\tPOSITION:\n\t\t\t1. RECEIPTIONIST\n\t\t\t2. DOCTOR'S HELPER\n\t\t\t3. PHARMACIES\n\t\t\tSELECTION: ";
                        cin >> pick;

                        switch(pick)
                        {
                        case 1:
                            position = "RECEIPTIONIST";
                            break;
                        case 2:
                            position = "DOCTOR'S HELPER";
                            break;
                        case 3:
                            position = "PHARMACIES";
                            break;
                        default:
                            cout << "\n\n\t\t\tWRONG INPUT! PLEASE TRY AGAIN.";
                            break;
                        }

                        if(pick == 1 || pick == 2 || pick == 3)
                        {
                            break;
                        }
                    }
                    ic = moreTemp->nurIC;
                    gender = moreTemp->nurGender;
                    phoneNumber = moreTemp->nurPhone;
                    name = moreTemp->nurName;
                    cout << "\n\n\t\t\tEDITED...";
                    saveEditNurseData(c);

                    break;

                case 6:

                    break;

                default:
                    cout << "\n\n\t\t\tWRONG INPUT! TRY AGAIN.";
                    break;
                }

                if(editselect > 0 && editselect < 7)
                {
                    break;
                }

            }

            load();
            break;

        case 2:
            break;

        default:
            cout << "\n\n\t\tWRONG INPUT PLEASE TRY AGAIN!\n";
            load();
            break;
        }

        if(select == 2)
        {
            break;
        }

    }

}

void clinic :: displayNurseInformation()
{
    nurse *temp;
    int select, selectPat;
    load();
    while(1)
    {
        staffTitle();
        temp = nurH;
        int count=1;

        cout << "\t\tLIST OF NURSE'S INFORMATION:\n\n";

        while(temp)
        {
            if(temp != NULL)
            {
                    cout << "\t\t" << count << ". " << temp->nurName << "\n";
                    count++;
            }
            temp = temp->nurNext;
        }


        cout << "\n\n\t\t1. SELECT WHICH NURSE'S INFORMATION TO DISPLAY\n\t\t2. EXIT\n\t\tSELECT: ";
        cin >> select;

        switch (select)
        {
        case 1:
            nurse *moreTemp;
            moreTemp = nurH;
            cout << "\n\n\t\tPATIENT NUMBER: ";
            cin >> selectPat;

            if(selectPat <= count)
            {
                for(int i=0; i<selectPat; i++)
                {
                    if(moreTemp->nurNext != NULL)
                    {
                        if(i!=selectPat-1)
                        {
                            moreTemp = moreTemp->nurNext;
                        }

                    }
                }
            }

            cout << "\n\n\t\tSELECTED PATIENT NUMBER: " << selectPat;
            cout << "\n**************************************************************************";
            cout << "\n\n\t\t      NAME: " << moreTemp->nurName;
            cout << "\n\t\t  I/C NUMBER: " << moreTemp->nurIC;
            cout << "\n\t\t      GENDER: " << moreTemp->nurGender;
            cout << "\n\t\tPHONE NUMBER: " << moreTemp->nurPhone;
            cout << "\n\t\t    POSITION: " << moreTemp->nurPosition;
            load();
            break;

        case 2:

            break;

        default:
            cout << "\n\n\t\tWRONG INPUT PLEASE TRY AGAIN!\n";
            load();
            break;
        }

        if(select == 2)
        {
            break;
        }

    }

}

void clinic :: removeNurseInformation()
{
    nurse *temp;
    int select, selectPat;
    ifstream file;
    int k = 1;
    char a[33];
    string b,c,sel;
    bool checking = false;
    load();
    while(1)
    {
        staffTitle();
        temp = nurH;
        int count=1;

        cout << "\t\tLIST OF NURSE'S INFORMATION:\n\n";

        while(temp)
        {
            if(temp != NULL)
            {
                    cout << "\t\t" << count << ". " << temp->nurName << "\n";
                    count++;
            }
            temp = temp->nurNext;
        }

        cout << "\n\n\t\tPLEASE SELECT WHICH NURSE'S INFORMATION TO REMOVE\n\t\tNURSE: ";
        cin >> std::ws;
        getline(cin, sel);

        remove(("Nurse Database/nurse"+ sel +".txt").c_str());

        while(1)
        {
            b = itoa(k, a, 10);
            file.open(("Nurse Database/nurse"+ b +".txt").c_str());
            if( file.is_open() )
            {
                file.close();
            }

            else
            {
                b = itoa(k+1, a, 10);
                file.open(("Nurse Database/nurse"+ b +".txt").c_str());
                if( file.is_open() )
                {
                    c = itoa(k, a, 10);
                    file.close();
                    rename(("Nurse Database/nurse"+ b +".txt").c_str(), ("Nurse Database/nurse"+ c +".txt").c_str());
                }

                else
                {
                    checking = true;
                    break;
                }
            }
            k++;
        }

        if(checking == true)
        {
            break;
        }

    }
}

//===========================================FUNCTION DEFINITION FOR DOCTOR==============================================================================

string clinic :: readDoctorData(int k)
{
    ifstream file;
    char a[33];
    string b;

      b = itoa(k, a, 10);
      file.open(("Doctor Database/doctor" + b +".txt").c_str());

      if(file.is_open())
      {
          file.close();
          return readDoctorData(k+1);

      }
      else
      {
          return itoa(k, a, 10);
      }

}

void clinic :: saveDoctorData()
{
    ofstream file;
    string b = readDoctorData(1);

    file.open(("Doctor Database/doctor"+b+".txt").c_str());

    if(docH == 0)
    {
        docH = new doctor;
        docH->docName = name;
        docH->docIC = ic;
        docH->docGender = gender;
        docH->docPhone = phoneNumber;
        docH->docSpecialty = specialty;

        docH->docNext = NULL;

    }

    else
    {
        doctor *temp, *newAccDb;

        newAccDb = new doctor;
        temp = docH;

        while(temp -> docNext != NULL)
        {
            temp = temp -> docNext;
        }

        newAccDb->docName = name;
        newAccDb->docIC = ic;
        newAccDb->docGender = gender;
        newAccDb->docPhone = phoneNumber;
        newAccDb->docSpecialty = specialty;

        temp->docNext = newAccDb;
        newAccDb->docNext= NULL;
    }

    for(int i=0; i<name.length(); i++)
        file << toupper(name[i], locale());
    file << endl;
    file << ic << endl;
    for(int i=0; i<gender.length(); i++)
        file << toupper(gender[i], locale());
    file << endl;
    file << phoneNumber << endl;
    file << specialty;
    file.close();

}

void clinic :: addDoctorDataInLinkedList(string b)
{
    ifstream file;

    file.open(("Doctor Database/doctor"+b+".txt").c_str());

    if(docH == 0)
    {
        docH = new doctor;

        file >> std::ws;
        getline(file, docH->docName);
        file >> docH->docIC;
        file >> std::ws;
        file >> docH->docGender;
        file >> std::ws;
        file >> docH->docPhone;
        file >> std::ws;
        getline(file, docH->docSpecialty);

        docH->docNext = NULL;

    }

    else
    {
        doctor *temp, *newAccDb;

        newAccDb = new doctor;
        temp = docH;

        while(temp->docNext != NULL)
        {
            temp = temp->docNext;
        }

        file >> std::ws;
        getline(file, newAccDb->docName);
        file >> newAccDb->docIC;
        file >> newAccDb->docGender;
        file >> newAccDb->docPhone;
        file >> std::ws;
        getline(file, newAccDb->docSpecialty);

        temp->docNext = newAccDb;
        newAccDb->docNext= NULL;
    }
}

void clinic :: storeDoctorDataInLinkedList()
{
    ifstream file;
    int k = 1;
    char a[33];
    string b;

    while(1)
    {
      b = itoa(k, a, 10);
      file.open(("Doctor Database/doctor" + b +".txt").c_str());

      if(file.is_open())
      {
          addDoctorDataInLinkedList(b);
          file.close();
      }
      else
      {
          break;
      }
      k++;

    }
}

void clinic :: doctorAddingDisplay()
{
    load();
    staffTitle();
    int pick;

    cout << "\t\t\t        NAME: ";
    cin >> std::ws;
    getline(cin, name);
    cout << "\t\t\t  I/C NUMBER: ";
    cin >> ic;
    cout << "\t\t\t      GENDER: ";
    cin >> gender;
    cout << "\t\t\tPHONE NUMBER: ";
    cin >> phoneNumber;
    while(1)
    {
        load();
        staffTitle();


        cout << "\t\t\t        NAME: ";
        for(int i=0; i<name.length(); i++)
            cout << toupper(name[i], locale());
        cout << "\n\t\t\t  I/C NUMBER: " << ic;
        cout << "\n\t\t\t      GENDER: ";
        for(int i=0; i<gender.length(); i++)
            cout << toupper(gender[i], locale());
        cout << "\n\t\t\tPHONE NUMBER: " << phoneNumber;
        cout << "\n\t\t\tSPECIALTY:\n\t\t\t1. OPHTHALMOLOGY\n\t\t\t2. OBSTETRICIAN\n\t\t\t3. NEUROLOGIST\n\t\t\tSELECTION: ";
        cin >> pick;

        switch(pick)
        {
        case 1:
            specialty = "OPHTHALMOLOGY";    //OPHTHALMOLOGY //OBSTETRICIAN //NEUROLOGIST
            break;
        case 2:
            specialty = "OBSTETRICIAN";
            break;
        case 3:
            specialty = "NEUROLOGIST";
            break;
        default:
            cout << "\n\n\t\t\tWRONG INPUT! PLEASE TRY AGAIN.";
            break;
        }

        if(pick == 1 || pick == 2 || pick == 3)
        {
            break;
        }
    }

    docH = 0;
    saveDoctorData();
    storeDoctorDataInLinkedList();
}

void clinic :: saveEditDoctorData(string b)
{
    ofstream file;

    file.open(("Doctor Database/doctor"+b+".txt").c_str());

    for(int i=0; i<name.length(); i++)
        file << toupper(name[i], locale());
    file << endl;
    file << ic << endl;
    for(int i=0; i<gender.length(); i++)
        file << toupper(gender[i], locale());
    file << endl;
    file << phoneNumber << endl;
    file << specialty;

    file.close();
}

void clinic :: editDoctorData()
{
    doctor *temp;
    int select, selectPat, pick;
    int editselect;
    string c;
    char a[33];

    load();

    while(1)
    {
        staffTitle();
        docH = 0;
        storeDoctorDataInLinkedList();
        temp = docH;
        int count=1;

        cout << "\t\tLIST OF DOCTOR'S INFORMATION:\n\n";

        while(temp)
        {
            if(temp != NULL)
            {
                    cout << "\t\t" << count << ". " << temp->docName << "\n";
                    count++;
            }
            temp = temp->docNext;
        }


        cout << "\n\n\t\t1. SELECT WHICH DOCTOR'S INFORMATION TO DISPLAY\n\t\t2. EXIT\n\t\tSELECT: ";
        cin >> select;

        switch (select)
        {
        case 1:
            doctor *moreTemp;
            moreTemp = docH;
            cout << "\n\n\t\tDOCTOR NUMBER: ";
            cin >> selectPat;

            if(selectPat <= count)
            {
                for(int i=0; i<selectPat; i++)
                {
                    if(moreTemp->docNext != NULL)
                    {
                        if(i!=selectPat-1)
                        {
                            moreTemp = moreTemp->docNext;
                        }

                    }
                }
            }

            load();
            c = itoa(selectPat, a, 10);
            while(1)
            {
                staffTitle();
                cout << "\n\n\t\tSELECTED DOCTOR NUMBER: " << selectPat;
                cout << "\n**************************************************************************";
                cout << "\n\n\t\t      NAME: " << moreTemp->docName;
                cout << "\n\t\t  I/C NUMBER: " << moreTemp->docIC;
                cout << "\n\t\t      GENDER: " << moreTemp->docGender;
                cout << "\n\t\tPHONE NUMBER: " << moreTemp->docPhone;
                cout << "\n\t\t    SPECIALTY: " << moreTemp->docSpecialty;


                cout << "\n\n\n\t\tPLEASE SELECT WHICH THING TO EDIT\n\t\t\t1. NAME\n\t\t\t2. I/C NUMBER\n\t\t\t3. GENDER\n\t\t\t4. PHONE NUMBER";
                cout << "\n\t\t\t5. SPECIALTY\n\t\t\t6. EXIT\n\t\t\tSELECTION: ";
                cin >> editselect;
                switch(editselect)
                {
                case 1:
                    cout << "\n\n\t\tPLEASE ENTER THE NEW NAME: ";
                    cin >> std::ws;
                    getline(cin, name);
                    ic = moreTemp->docIC;
                    gender = moreTemp->docGender;
                    phoneNumber = moreTemp->docPhone;
                    specialty = moreTemp->docSpecialty;
                    cout << "\n\n\t\t\tEDITED...";
                    saveEditDoctorData(c);
                    break;

                case 2:
                    cout << "\n\n\t\tPLEASE ENTER THE NEW I/C NUMBER: ";
                    cin >> ic;
                    name = moreTemp->docName;
                    gender = moreTemp->docGender;
                    phoneNumber = moreTemp->docPhone;
                    specialty = moreTemp->docSpecialty;
                    cout << "\n\n\t\t\tEDITED...";
                    saveEditDoctorData(c);
                    break;

                case 3:
                    cout << "\n\n\t\tPLEASE ENTER THE NEW GENDER: ";
                    cin >> gender;
                    ic = moreTemp->docIC;
                    name = moreTemp->docName;
                    phoneNumber = moreTemp->docPhone;
                    specialty = moreTemp->docSpecialty;
                    cout << "\n\n\t\t\tEDITED...";
                    saveEditDoctorData(c);
                    break;

                case 4:
                    cout << "\n\n\t\tPLEASE ENTER THE NEW PHONE NUMBER: ";
                    cin >> phoneNumber;
                    ic = moreTemp->docIC;
                    gender = moreTemp->docGender;
                    name = moreTemp->docName;
                    specialty = moreTemp->docSpecialty;
                    cout << "\n\n\t\t\tEDITED...";
                    saveEditDoctorData(c);
                    break;

                case 5:
                    while(1)
                    {
                        cout << "\n\n\t\tPLEASE ENTER THE NEW SPECIALTY: \n";
                        cout << "\n\t\t\tSPECIALTY:\n\t\t\t1. OPHTHALMOLOGY\n\t\t\t2. OBSTETRICIAN\n\t\t\t3. NEUROLOGIST\n\t\t\tSELECTION: ";
                        cin >> pick;

                        switch(pick)
                        {
                        case 1:
                            specialty = "OPHTHALMOLOGY"; //OPHTHALMOLOGY //OBSTETRICIAN //NEUROLOGIST
                            break;
                        case 2:
                            specialty = "OBSTETRICIAN";
                            break;
                        case 3:
                            specialty = "NEUROLOGIST";
                            break;
                        default:
                            cout << "\n\n\t\t\tWRONG INPUT! PLEASE TRY AGAIN.";
                            break;
                        }

                        if(pick == 1 || pick == 2 || pick == 3)
                        {
                            break;
                        }
                    }
                    ic = moreTemp->docIC;
                    gender = moreTemp->docGender;
                    phoneNumber = moreTemp->docPhone;
                    name = moreTemp->docName;
                    cout << "\n\n\t\t\tEDITED...";
                    saveEditDoctorData(c);

                    break;

                case 6:

                    break;

                default:
                    cout << "\n\n\t\t\tWRONG INPUT! TRY AGAIN.";
                    break;
                }

                if(editselect > 0 && editselect < 7)
                {
                    break;
                }

            }

            load();
            break;

        case 2:
            break;

        default:
            cout << "\n\n\t\tWRONG INPUT PLEASE TRY AGAIN!\n";
            load();
            break;
        }

        if(select == 2)
        {
            break;
        }

    }

}

void clinic :: displayDoctorInformation()
{
    doctor *temp;
    int select, selectPat;
    load();
    while(1)
    {
        staffTitle();
        temp = docH;
        int count=1;

        cout << "\t\tLIST OF DOCTOR'S INFORMATION:\n\n";

        while(temp)
        {
            if(temp != NULL)
            {
                    cout << "\t\t" << count << ". " << temp->docName << "\n";
                    count++;
            }
            temp = temp->docNext;
        }


        cout << "\n\n\t\t1. SELECT WHICH DOCTOR'S INFORMATION TO DISPLAY\n\t\t2. EXIT\n\t\tSELECT: ";
        cin >> select;

        switch (select)
        {
        case 1:
            doctor *moreTemp;
            moreTemp = docH;
            cout << "\n\n\t\tDOCTOR NUMBER: ";
            cin >> selectPat;

            if(selectPat <= count)
            {
                for(int i=0; i<selectPat; i++)
                {
                    if(moreTemp->docNext != NULL)
                    {
                        if(i!=selectPat-1)
                        {
                            moreTemp = moreTemp->docNext;
                        }

                    }
                }
            }

            cout << "\n\n\t\tSELECTED DOCTOR NUMBER: " << selectPat;
            cout << "\n**************************************************************************";
            cout << "\n\n\t\t      NAME: " << moreTemp->docName;
            cout << "\n\t\t  I/C NUMBER: " << moreTemp->docIC;
            cout << "\n\t\t      GENDER: " << moreTemp->docGender;
            cout << "\n\t\tPHONE NUMBER: " << moreTemp->docPhone;
            cout << "\n\t\t    POSITION: " << moreTemp->docSpecialty;
            load();
            break;

        case 2:

            break;

        default:
            cout << "\n\n\t\tWRONG INPUT PLEASE TRY AGAIN!\n";
            load();
            break;
        }

        if(select == 2)
        {
            break;
        }

    }

}

void clinic :: removeDoctorInformation()
{
    doctor *temp;
    int select, selectPat;
    ifstream file;
    int k = 1;
    char a[33];
    string b,c,sel;
    bool checking = false;
    load();
    while(1)
    {
        staffTitle();
        temp = docH;
        int count=1;

        cout << "\t\tLIST OF DOCTOR'S INFORMATION:\n\n";

        while(temp)
        {
            if(temp != NULL)
            {
                    cout << "\t\t" << count << ". " << temp->docName << "\n";
                    count++;
            }
            temp = temp->docNext;
        }

        cout << "\n\n\t\tPLEASE SELECT WHICH DOCTOR'S INFORMATION TO REMOVE\n\t\tDOCTOR: ";
        cin >> std::ws;
        cin >> sel;
        //getline(cin, sel);

        remove(("Doctor Database/doctor"+ sel +".txt").c_str());

        while(1)
        {
            b = itoa(k, a, 10);
            file.open(("Doctor Database/doctor"+ b +".txt").c_str());
            if( file.is_open() )
            {
                file.close();
            }

            else
            {
                b = itoa(k+1, a, 10);
                file.open(("Doctor Database/doctor"+ b +".txt").c_str());
                if( file.is_open() )
                {
                    c = itoa(k, a, 10);
                    file.close();
                    rename(("Doctor Database/doctor"+ b +".txt").c_str(), ("Doctor Database/doctor"+ c +".txt").c_str());
                }

                else
                {
                    checking = true;
                    break;
                }
            }
            k++;
        }
        if(checking == true)
        {
            break;
        }

    }
}


//==========================================FUNCTION DEFINITION FOR MEDICINE============================================================================

void clinic :: addMedicineDataInLinkedList(string b)
{
    ifstream file;

    file.open(("Medicine Database/medicine"+b+".txt").c_str());

    if(medH == 0)
    {
        medH = new medicine;

        file >> std::ws;
        getline(file, medH->medName);
        file >> medH->medPrice;
        file >> medH->medQuantity;

        medH->medNext = NULL;

    }

    else
    {
        medicine *temp, *newAccDb;

        newAccDb = new medicine;
        temp = medH;

        while(temp->medNext != NULL)
        {
            temp = temp->medNext;
        }

        file >> std::ws;
        getline(file, newAccDb->medName);
        file >> newAccDb->medPrice;
        file >> newAccDb->medQuantity;

        temp->medNext = newAccDb;
        newAccDb->medNext= NULL;
    }
    file.close();
}

void clinic :: storeMedicineDataInLinkedList()
{
    ifstream file;
    int k = 1;
    char a[33];
    string b;

    while(1)
    {
      b = itoa(k, a, 10);
      file.open(("Medicine Database/medicine" + b +".txt").c_str());

      if(file.is_open())
      {
          addMedicineDataInLinkedList(b);
          file.close();
      }
      else
      {
          break;
      }
      k++;

    }
}

void clinic :: displayMedicineInformation()
{
    medicine *temp;
    int select, selectPat;
    load();
    while(1)
    {
        staffTitle();
        temp = medH;
        int count=1;

        cout << "\t\tLIST OF MEDICINE'S INFORMATION:\n\n";

        while(temp)
        {
            if(temp != NULL)
            {
                    cout << "\t\t" << count << ". " << temp->medName << "\n";
                    count++;
            }
            temp = temp->medNext;
        }


        cout << "\n\n\t\t1. SELECT WHICH MEDICINE'S INFORMATION TO DISPLAY\n\t\t2. EXIT\n\t\tSELECT: ";
        cin >> select;

        switch (select)
        {
        case 1:
            medicine *moreTemp;
            moreTemp = medH;
            cout << "\n\n\t\tMEDICINE NUMBER: ";
            cin >> selectPat;

            if(selectPat <= count)
            {
                for(int i=0; i<selectPat; i++)
                {
                    if(moreTemp->medNext != NULL)
                    {
                        if(i!=selectPat-1)
                        {
                            moreTemp = moreTemp->medNext;
                        }

                    }
                }
            }

            cout << "\n\n\t\tSELECTED MEDICINE NUMBER: " << selectPat;
            cout << "\n**************************************************************************";
            cout << "\n\n\t\t  MEDICINE: " << moreTemp->medName;
            cout << "\n\t\t       PRICE: RM" <<fixed << setprecision(2)<< moreTemp->medPrice;
            cout << "\n\t\t    QUANTITY: " << moreTemp->medQuantity;
            load();
            break;

        case 2:

            break;

        default:
            cout << "\n\n\t\tWRONG INPUT PLEASE TRY AGAIN!\n";
            load();
            break;
        }

        if(select == 2)
        {
            break;
        }

    }

}

void clinic :: saveEditMedicineData(string b)
{
    ofstream file;

    file.open(("Medicine Database/medicine"+b+".txt").c_str());

    file << nameOfMedicine << endl;
    file << price << endl;
    file << quantity;

    file.close();
}

void clinic :: editMedicineData()
{
    medicine *temp;
    int select, selectPat;
    string c;
    char a[33];
    load();
    while(1)
    {
        staffTitle();
        temp = medH;
        int count=1;

        cout << "\t\tLIST OF MEDICINE'S INFORMATION:\n\n";

        while(temp)
        {
            if(temp != NULL)
            {
                    cout << "\t\t" << count << ". " << temp->medName << "\n";
                    count++;
            }
            temp = temp->medNext;
        }


        cout << "\n\n\t\t1. SELECT WHICH MEDICINE'S QUANTITY TO EDIT\n\t\t2. EXIT\n\t\tSELECT: ";
        cin >> select;

        switch (select)
        {
        case 1:
            medicine *moreTemp;
            moreTemp = medH;
            cout << "\n\n\t\tMEDICINE NUMBER: ";
            cin >> selectPat;

            if(selectPat <= count)
            {
                for(int i=0; i<selectPat; i++)
                {
                    if(moreTemp->medNext != NULL)
                    {
                        if(i!=selectPat-1)
                        {
                            moreTemp = moreTemp->medNext;
                        }

                    }
                }
            }
            load();
            c = itoa(selectPat, a, 10);
            staffTitle();

            cout << "\n\n\t\tSELECTED MEDICINE NUMBER: " << selectPat;
            cout << "\n**************************************************************************";
            cout << "\n\n\t\t  MEDICINE: " << moreTemp->medName;
            cout << "\n\t\t       PRICE: RM" <<fixed << setprecision(2)<< moreTemp->medPrice;
            cout << "\n\t\t    QUANTITY: " << moreTemp->medQuantity;

            cout << "\n\n\t\tPLEASE ENTER NEW QUANTITY: ";
            cin >> quantity;
            nameOfMedicine = moreTemp->medName;
            price = moreTemp->medPrice;
            saveEditMedicineData(c);
            load();
            break;

        case 2:

            break;

        default:
            cout << "\n\n\t\tWRONG INPUT PLEASE TRY AGAIN!\n";
            load();
            break;
        }

        if(select == 2)
        {
            break;
        }

    }

}


//==================================================ADD, EDIT & REMOVE==================================================================================

void clinic :: addData()
{
    int select;
    while(1)
    {
        load();
        staffTitle();
        cout << "\t\t\t1. ADD DOCTOR'S INFORMATION\n\t\t\t2. ADD NURSE'S INFORMATION\n\t\t\t3. EXIT\n\t\t\tSELECTION: ";
        cin >> select;

        switch(select)
        {
        case 1:
            doctorAddingDisplay();
            break;

        case 2:
            nurseAddingDisplay();
            break;

        case 3:

            break;
        }

        if(select == 3)
        {
            break;
        }
    }
}

void clinic :: editData()
{
    int select;
    while(1)
    {
        load();
        staffTitle();
        cout << "\t\t\t1. EDIT DOCTOR'S INFORMATION\n\t\t\t2. EDIT NURSE'S INFORMATION\n\t\t\t3. EDIT MEDICINE'S INFORMATION\n\t\t\t4. EXIT\n\t\t\tSELECTION: ";
        cin >> select;

        switch(select)
        {
        case 1:
            editDoctorData();
            break;

        case 2:
            editNurseData();
            break;

        case 3:
            editMedicineData();
            break;

        case 4:

            break;
        }

        if(select == 4)
        {
            break;
        }
    }
}


void clinic :: removeData()
{
    int select;
    while(1)
    {
        load();
        staffTitle();
        cout << "\t\t\t1. REMOVE DOCTOR'S INFORMATION\n\t\t\t2. REMOVE NURSE'S INFORMATION\n\t\t\t3. EXIT\n\t\t\tSELECTION: ";
        cin >> select;

        switch(select)
        {
        case 1:
            docH = 0;
            storeDoctorDataInLinkedList();
            removeDoctorInformation();
            break;

        case 2:
            nurH = 0;
            storeNurseDataInLinkedList();
            removeNurseInformation();
            break;

        case 3:

            break;
        }

        if(select == 3)
        {
            break;
        }
    }
}

