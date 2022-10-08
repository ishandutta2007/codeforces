#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

Int delitels[100001];
Int dL=0;

int main()
{
    Int n;
    Int i,j;
    Int num1,num2,num3;
    Int copy;
    Int themin=999999999999999,themax=-1;
    Int ans;
    Int stolen;
    
    scanf("%I64d",&n);
    
    for (i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            dL++;
            delitels[dL]=i;
            
            if (n/i!=i)
            {
                dL++;
                delitels[dL]=n/i;
            }
        }
    }
    
    for (i=1;i<=dL;i++)
    {
        for (j=1;j<=dL;j++)
        {
            copy=n;
            num1=delitels[i];
            copy=copy/delitels[i];
            //cout<<delitels[i]<<" "<<delitels[j]<<endl;
            if (copy%delitels[j]==0)
            {
                //cout<<"in"<<endl;
                num2=delitels[j];
                copy=copy/delitels[j];
                
                num3=copy;
                
                ans=(num1+1)*(num2+2)*(num3+2);
                stolen=ans-n;
                
                if ( themin>stolen )
                themin=stolen;
                if ( themax<stolen )
                themax=stolen;
            }
            //else
            //cout<<"out"<<endl;
        }
    }
    printf("%I64d %I64d\n",themin,themax);
    return 0;
}