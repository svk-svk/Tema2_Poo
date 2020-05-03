#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//nu am putut sa fac in fisiere separate deoarece imi dadea o eroare cu toate ca am facut tot ce trebuia
class Persoana
{
    unsigned int id;
    string nume;
public:
    Persoana (int i = 0, string n = "");
    Persoana (const Persoana &pers);
    ~Persoana ();
    friend istream& operator>> (istream &f, Persoana &p);
    friend ostream& operator<< (ostream &g, Persoana &p);
    Persoana& operator= (const Persoana &pers);
    string getNume();
};



Persoana:: Persoana (int i , string n)
{
    id = i;
    nume = n;
}
Persoana:: Persoana (const Persoana &pers)
{   if (this != &pers)
    {id = pers.id;
    nume = pers.nume;}
}
Persoana:: ~Persoana ()
{

}
istream& operator>> (istream &f, Persoana &p)
{
    return (f >>p.id>>p.nume);
}
ostream& operator<< (ostream &g, Persoana &p)
{
    return (g<<"\nid - "<<p.id<<", name - "<<p.nume);
}
Persoana& Persoana:: operator= (const Persoana &pers)
{if (this != &pers)
    {id = pers.id;
    nume = pers.nume;}
    return *this;
}
string Persoana:: getNume()
{
    return nume;
}

class Abonat: public Persoana
{
    unsigned long nr_telefon;
public:
    Abonat (int i,string n,long nr);
    Abonat (const Abonat &Ab);
    ~Abonat ();
    friend istream& operator>> (istream &f, Abonat &a);
    friend ostream& operator<< (ostream &g, Abonat &a);
    Abonat& operator= (const Abonat &Ab);
};
Abonat:: Abonat (int i = 0,string n = "",long nr = 0) : Persoana(i, n)
{
    nr_telefon = nr;
}
Abonat:: Abonat (const Abonat &Ab) : Persoana (Ab)
{
    if (this != &Ab)
    {
        nr_telefon = Ab.nr_telefon;
    }
}
Abonat:: ~Abonat ()
{

}
istream& operator>> (istream &f, Abonat &a)
{
    Persoana &p = a;
    f >> p;
    return (f >> a.nr_telefon);
}
ostream& operator<< (ostream &g, Abonat &a)
{
    Persoana &p = a;
    g << p;
    return (g<<", numar de telefon - " << a.nr_telefon);
}
Abonat& Abonat:: operator= (const Abonat &Ab)
{if(this != &Ab)
    {Persoana &p = *this;
    p = Ab;
    nr_telefon = Ab.nr_telefon;
    }
    return *this;
}

class Abonat_Skype: public Abonat
{
    unsigned int id_skype;
public:
    Abonat_Skype (int i, string n, long nr, int is);
    Abonat_Skype (const Abonat_Skype &Ab_S);
    ~Abonat_Skype ();
    friend istream& operator>> (istream &f, Abonat_Skype &a);
    friend ostream& operator<< (ostream &g, Abonat_Skype &a);
    Abonat_Skype& operator= (const Abonat_Skype &Ab_S);
};



Abonat_Skype:: Abonat_Skype (int i = 0, string n = "", long nr = 0, int is = 0) : Abonat (i, n, nr)
{
    id_skype = is;
}
Abonat_Skype:: Abonat_Skype (const Abonat_Skype &Ab_S) : Abonat (Ab_S)
{
    if (this != &Ab_S)
    {
        id_skype = Ab_S.id_skype;
    }
}
Abonat_Skype:: ~Abonat_Skype ()
{

}
istream& operator>> (istream &f, Abonat_Skype &a)
{Abonat &p = a;
return (f>>p>>a.id_skype);}

ostream& operator<< (ostream &g, Abonat_Skype &a)
{Abonat &p = a;
return (g<<p<< ", id skype - " <<a.id_skype);
}
Abonat_Skype& Abonat_Skype:: operator= (const Abonat_Skype &Ab_S)
{
    if (this != &Ab_S)
    {
        Abonat &p = *this;
        p = Ab_S;
        id_skype =Ab_S.id_skype;
    }
    return *this;
}

class Abonat_Skype_Romania: public Abonat_Skype
{
    string adresa_mail;
public:
    Abonat_Skype_Romania (int i,string n,long nr, int is, string a);
    Abonat_Skype_Romania (const Abonat_Skype_Romania &Ro);
    ~Abonat_Skype_Romania ();
    friend istream& operator>> (istream &f, Abonat_Skype_Romania &a);
    friend ostream& operator<< (ostream &g, Abonat_Skype_Romania &a);
    Abonat_Skype_Romania& operator= (const Abonat_Skype_Romania &Ro);
    string getInfo ();
};


Abonat_Skype_Romania:: Abonat_Skype_Romania (int i = 0,string n = "",long nr = 0,int is = 0,string a = "") : Abonat_Skype (i, n, nr, is)
{
    adresa_mail = a;
}
Abonat_Skype_Romania:: Abonat_Skype_Romania (const Abonat_Skype_Romania &Ro) : Abonat_Skype (Ro)
{
    if (this != &Ro)
    {
        adresa_mail = Ro.adresa_mail;
    }
}
Abonat_Skype_Romania:: ~Abonat_Skype_Romania ()
{

}
istream& operator>> (istream &f, Abonat_Skype_Romania &a)
{
    Abonat_Skype &p = a;
    return (f >> p >> a.adresa_mail);
}
ostream& operator<< (ostream &g, Abonat_Skype_Romania &a)
{
    Abonat_Skype &p = a;
    return (g << p << ", adresa de mail - " <<  a.adresa_mail);
}
Abonat_Skype_Romania& Abonat_Skype_Romania:: operator= (const Abonat_Skype_Romania &Ro)
{
    if (this != &Ro)
    {
        Abonat_Skype &p = *this;
        p = Ro;
        adresa_mail = Ro.adresa_mail;
    }
    return *this;
}
string Abonat_Skype_Romania:: getInfo ()
{
    return adresa_mail;
}

class Abonat_Skype_Extern: public Abonat_Skype
{
    string tara;
public:
    Abonat_Skype_Extern (int i,string n, long nr, int is , string t);
    Abonat_Skype_Extern (const Abonat_Skype_Extern &Ex);
    ~Abonat_Skype_Extern ();
    friend istream& operator>> (istream &f, Abonat_Skype_Extern &a);
    friend ostream& operator<< (ostream &g, Abonat_Skype_Extern &a);
    Abonat_Skype_Extern& operator= (const Abonat_Skype_Extern &Ex);
    Abonat_Skype_Extern& operator= (Abonat_Skype_Romania &Ex);//nu stiu exact cum sa introduc in agenda Abonat_Skype_Extern si Abonat_Skype_Romania astept un sfat
    string getInfo ();
};
Abonat_Skype_Extern:: Abonat_Skype_Extern (int i = 0,string n = "",long nr = 0,int is =0,string t = "") : Abonat_Skype (i, n, nr, is)
{
    tara = t;
}
Abonat_Skype_Extern:: Abonat_Skype_Extern (const Abonat_Skype_Extern &Ex) : Abonat_Skype (Ex)
{
    if (this != &Ex)
    {
        tara = Ex.tara;
    }
}
Abonat_Skype_Extern:: ~Abonat_Skype_Extern ()
{
}
istream& operator>> (istream &f, Abonat_Skype_Extern &a)
{
    Abonat_Skype &p = a;
    return (f>>p>>a.tara);
}
ostream& operator<< (ostream &g, Abonat_Skype_Extern &a)
{
    Abonat_Skype &p = a;
    return (g<<p<<", tara - " <<  a.tara);
}
Abonat_Skype_Extern& Abonat_Skype_Extern:: operator= (const Abonat_Skype_Extern &Ex)
{
    if (this != &Ex)
    {
        Abonat_Skype &p = *this;
        p = Ex;
        tara = Ex.tara;
    }
    return *this;
}
Abonat_Skype_Extern& Abonat_Skype_Extern:: operator= (Abonat_Skype_Romania &Ex)
{
    Abonat_Skype &p = *this;
    p = Ex;

    tara = Ex.getInfo();
    return *this;
}
string Abonat_Skype_Extern:: getInfo ()
{
    return tara;
}


class Agenda
{
    Abonat_Skype_Extern info;
    Agenda *next;
public:

    Agenda (Abonat_Skype_Romania &i, Agenda *n );
    Agenda (Abonat_Skype_Extern &i, Agenda *n);
    Agenda (Agenda *AG);
    ~Agenda ();
    Agenda& operator= (Agenda *AG);
    friend istream& operator>> (istream &f, Agenda &a);
    friend istream& operator>> (istream &f, Agenda* &a);
    friend ostream& operator<< (ostream &g, Agenda &a);
    friend ostream& operator<< (ostream &f, Agenda* &a);
    Agenda* operator[] (string index_nume);
};

Agenda:: Agenda (Abonat_Skype_Romania &i, Agenda *n = NULL)
{
    info = i;
    next = n;
}
Agenda:: Agenda (Abonat_Skype_Extern &i, Agenda *n = NULL)
{
    info = i;
    next = n;
}
Agenda:: Agenda (Agenda *AG)
{
    if (AG != NULL)
    {
        this->info = AG->info;
        this->next = (AG->next == NULL) ? NULL : new Agenda (AG->next);
    }
    else
    {
        this->next = NULL;
        Abonat_Skype_Romania a;
        info = a;
    }
}
Agenda:: ~Agenda ()
{
    if (this)
    {
        delete this->next;
    }
}
Agenda& Agenda:: operator= (Agenda *AG)
{
    if (this == NULL)
    {
        return *this;
    }
    else
    {
        delete this->next;
    }
    if (AG!= NULL)
    {
        this->info = AG->info;
        this->next = (AG->next == NULL) ? NULL : new Agenda (AG->next);
    }
    else
    {
        Abonat_Skype_Extern a;
        this->info = a;
        this->next = NULL;
    }
    return *this;
}
istream& operator>> (istream &f, Agenda &a)
{
    return (f >> a.info);
}
istream& operator>> (istream &f, Agenda* &a)
{
    delete a;
    a = NULL;
    int numar_r, numar_e;
    f >> numar_r >> numar_e;
    Abonat_Skype_Romania Ab_r;
    Abonat_Skype_Extern Ab_e;
    while (numar_r-- > 0)
    {
        f>> Ab_r;
        a = new Agenda (Ab_r, a);
    }
    while (numar_e-- > 0)
    {
        f>> Ab_e;
        a = new Agenda (Ab_e, a);
    }
    return f;
}
ostream& operator<< (ostream &g, Agenda &a)
{
    return (g<< a.info);
}
ostream& operator<< (ostream &f, Agenda* &a)
{
    return (a == NULL) ? f : (f<< *a << a->next);
}
Agenda* Agenda:: operator[] (string index_nume)
{
    return (this == NULL || this->info.getNume() == index_nume) ? this : (*this->next)[index_nume];
}

int main()
{
    ifstream f ("date.in");

    Agenda *a = NULL, *p;
    f>> a;

    cout << a << "\n";

    p = (*a)["a"];
    if (p != NULL)
        cout << *p;
    else
    {
        cout << "\nNu exista in Agenda";
    }

    return 0;
    f.close();
}
