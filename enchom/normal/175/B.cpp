#include <iostream>
#include <stdio.h>
using namespace std;

struct score
{
    int record;
    char name[150];
    int nameL;
};

score people[1011];
int pL=0;
double peoplehebeated;
double thisonegot;

int main()
{
    int n;
    int i,j,in;
    string k;
    bool identical;
    int dascore;
    char inputname[150];
    int inputnameL=0;
    
    cin>>n;
    
    for (i=1;i<=n;i++)
    {
        cin>>k;
        cin>>dascore;
        
        
        for (j=0;j<k.length();j++)
        inputname[j+1]=k[j];
        inputnameL=k.length();
        
        
        identical=false;
        for (j=1;j<=pL;j++)
        {
            identical=true;
            
            if (people[j].nameL!=inputnameL)
            identical=false;
            else
            {
                for (in=1;in<=people[j].nameL;in++)
                {
                    if (people[j].name[in]!=inputname[in])
                    {
                        identical=false;
                        break;
                    }
                }
            }
            
            if (identical)
            {
                if (people[j].record<dascore)
                people[j].record=dascore;
                
                break;
            }
        }
        if (!identical)
        {
            pL++;
            people[pL].record=dascore;
            people[pL].nameL=inputnameL;
            for (j=1;j<=inputnameL;j++)
            people[pL].name[j]=inputname[j];
        }
    }
    cout<<pL<<endl;
    for (i=1;i<=pL;i++)
    {
        thisonegot=0.0;
        peoplehebeated=0.0;
        for (j=1;j<=pL;j++)
        {
            if (people[i].record>=people[j].record)
            peoplehebeated=peoplehebeated+1;
        }
        for (j=1;j<=people[i].nameL;j++)
        {
            cout<<people[i].name[j];
        }
        cout<<" ";
        thisonegot=peoplehebeated*100.0;
        thisonegot=thisonegot/( (double)pL );
        if (thisonegot<50.0)
        cout<<"noob"<<endl;
        else if (thisonegot<80.0)
        cout<<"random"<<endl;
        else if (thisonegot<90.0)
        cout<<"average"<<endl;
        else if (thisonegot<99.0)
        cout<<"hardcore"<<endl;
        else
        cout<<"pro"<<endl;
    }
    return 0;
}