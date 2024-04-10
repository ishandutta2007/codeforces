#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int msk[11];

Int Mask(Int k)
{
    Int L=0;
    Int num=0;
    Int i;

    while(k>0)
    {
        L++;
        msk[L]=k%10;
        k=k/10;
    }

    for (i=L;i>=1;i--)
    {
        if (msk[i]==4 || msk[i]==7)
        num=num*10+msk[i];
    }

    return num;
}

int main()
{
    Int powerof10=1;
    Int a,b;
    Int basicnum=1;
    Int creatednum;
    Int i;

    scanf("%I64d %I64d",&a,&b);

    for (i=a+1;i<=1000000;i++)
    {
        if (Mask(i)==b)
        {
            printf("%I64d\n",i);
            return 0;
        }
    }

    return 0;
}