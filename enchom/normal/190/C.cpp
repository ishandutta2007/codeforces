#include <iostream>
#include <stdio.h>
using namespace std;
char wrong[400001];
int L=0;
char fixedd[800001];
int fL=0;
int pairs[100001],pL=0;
int main()
{
    int n;
    int uk;
    int i;
    char input;
    
    cin>>n;
    while (!cin.eof())
    {
        cin>>input;
        if (cin.eof())
        break;

        
        if (input=='i' || input=='n' || input=='t' || input=='p' || input=='a' || input=='r')
        {
            L++;
            wrong[L]=input;
        }
    }
    if (L==3 && wrong[1]=='i')
    {
        cout<<"int"<<endl;
        return 0;
    }
    uk=1;
    while(uk<=L)
    {
        if (wrong[uk]=='p')
        {
            fL++;
            fixedd[fL]=wrong[uk];
            uk++;
            
            fL++;
            fixedd[fL]=wrong[uk];
            uk++;
            
            fL++;
            fixedd[fL]=wrong[uk];
            uk++;
            
            fL++;
            fixedd[fL]=wrong[uk];
            uk++;
            
            fL++;
            fixedd[fL]='<';
            
            pL++;
            pairs[pL]=1;
        }
        else if (wrong[uk]=='i')
        {
            if (pL==0)
            {
                cout<<"Error occurred"<<endl;
                return 0;
            }
            
            fL++;
            fixedd[fL]=wrong[uk];
            uk++;
            
            fL++;
            fixedd[fL]=wrong[uk];
            uk++;
            
            fL++;
            fixedd[fL]=wrong[uk];
            uk++;
            
            if (pairs[pL]==1)
            {
                fL++;
                fixedd[fL]=',';
                pairs[pL]=2;
            }
            else
            {
                fL++;
                fixedd[fL]='>';
                pL--;
                while (pL>0 && pairs[pL]==2)
                {
                    fL++;
                    fixedd[fL]='>';
                    pL--;
                }
                if (pL>0 && pairs[pL]==1)
                {
                    fL++;
                    fixedd[fL]=',';
                    pairs[pL]=2;
                }
            }
            
        }
    }
    
    if (pL>0)
    {
        cout<<"Error occurred"<<endl;
        return 0;
    }
    for (i=1;i<=fL;i++)
    {
        cout<<fixedd[i];
    }
    cout<<endl;
}