#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int PowerOf2[63];
Int num1,num2;
Int firstnum[63];
Int secondnum[63];

int main()
{
    Int l,r;
    Int i;
    Int copy;
    Int d;
    bool provenlarger=false;
    Int ans;
    
    scanf("%I64d %I64d",&l,&r);
    
    PowerOf2[0]=1;
    for (i=1;i<=62;i++)
    {
        PowerOf2[i]=PowerOf2[i-1]*2;
    }
    
    copy=l;
    i=0;
    while (copy>0)
    {
        i++;
        firstnum[i]=copy%2;
        copy=copy/2;
    }
    i++;
    for (i;i<=62;i++)
    {
        firstnum[i]=0;
    }
    for (i=1;i<=31;i++)
    {
        d=firstnum[i];
        firstnum[i]=firstnum[63-i];
        firstnum[63-i]=d;
    }
    ///////////////////////////////////
    copy=r;
    i=0;
    while (copy>0)
    {
        i++;
        secondnum[i]=copy%2;
        copy=copy/2;
    }
    i++;
    for (i;i<=62;i++)
    {
        secondnum[i]=0;
    }
    for (i=1;i<=31;i++)
    {
        d=secondnum[i];
        secondnum[i]=secondnum[63-i];
        secondnum[63-i]=d;
    }
    
    //////////////////////////////////////
    
    num1=0;
    num2=0;
    
    for (i=1;i<=62;i++)
    {
        if (firstnum[i]==0 && secondnum[i]==0)
        {
            if (provenlarger)
            {
                num1=num1+PowerOf2[62-i];
            }
            else
            {
                continue;
            }
        }
        else if (firstnum[i]==0 && secondnum[i]==1)
        {
            num2=num2+PowerOf2[62-i];
            provenlarger=true;
        }
        else if (firstnum[i]==1 && secondnum[i]==0)
        {
            num1=num1+PowerOf2[62-i];
        }
        else /// 1 1
        {
            if (provenlarger)
            {
                num1=num1+PowerOf2[62-i];
            }
        }
    }
    
    ans=num1^num2;
    printf("%I64d\n",ans);
    
    return 0;
}