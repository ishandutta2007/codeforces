#include <iostream>
using namespace std;
int main ()
{
    int a,b1[1000],b2[1000],i,d=0,j;
    cin>>a;
    for(i=1; i<=a; i++)
    {
        cin>>b1[i]>>b2[i];
        }
    for(i=1; i<=a; i++)
    {
        for(j=1; j<=a; j++)
        {
            if(b1[i]==b2[j]){d++;}
            }
        }
        cout<<d;
    return 0;
    }