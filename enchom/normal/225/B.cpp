#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int F[1001];
Int fL=0;
Int arr[1001];
Int aL=0;

int main()
{
    Int s,k;
    Int i,j;
    
    scanf("%I64d %I64d",&s,&k);
    
    fL=1;
    F[1]=1;
    while(F[fL]<2000000001)
    {
        fL++;
        
        F[fL]=0;
        for (j=fL-1;j>=fL-k;j--)
        {
            if (j<1)
            break;
            
            F[fL]+=F[j];
        }
        //cout<<F[fL]<<endl;
    }
    
    for (i=fL;i>=1;i--)
    {
        if (F[i]<=s)
        {
            aL++;
            arr[aL]=F[i];
            s-=F[i];
        }
    }
    if (aL==1)
    {
        aL++;
        arr[aL]=0;
    }
    
    cout<<aL<<endl;
    for (i=1;i<=aL;i++)
    {
        cout<<arr[i];
        if (i!=aL)
        cout<<" ";
        else
        cout<<endl;
    }
}