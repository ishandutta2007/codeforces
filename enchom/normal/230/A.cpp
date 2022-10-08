#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long Int;

Int x[1001];
Int y[1001];
bool TFO[1001];

int main()
{
    Int n;
    Int s;
    Int i,j;
    Int deaddragons=0;
    bool killedsomething=false;
    
    for (i=0;i<=1000;i++)
    TFO[i]=false;
    
    scanf("%I64d %I64d",&s,&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&x[i],&y[i]);
    }
    
    while(1)
    {
        killedsomething=false;
        for (j=1;j<=n;j++)
        {
            if (!TFO[j])
            {
                if (x[j]<s)
                {
                    TFO[j]=true;
                    deaddragons++;
                    killedsomething=true;
                    s=s+y[j];
                }
            }
        }
        if (deaddragons==n)
        {
            break;
        }
        if (!killedsomething)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}