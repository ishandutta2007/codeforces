#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long Int;

Int n;
Int Seq[4001];

Int NUM(char ch)
{
    return ch-'0';
}

Int ABS(Int a)
{
    if (a<0)
    return 0-a;
    else
    return a;
}

int main()
{
    Int i;
    char ch;
    Int zero=0;
    Int sum=0;
    Int smallest;

    scanf("%I64d",&n);

    for (i=1;i<=2*n;i++)
    {
        ch='|';

        while(ch!='.')
        {
            scanf("%c",&ch);
        }

        Seq[i]=0;
        scanf("%c",&ch);
        Seq[i]=Seq[i]+NUM(ch);
        scanf("%c",&ch);
        Seq[i]=Seq[i]*10+NUM(ch);
        scanf("%c",&ch);
        Seq[i]=Seq[i]*10+NUM(ch);

        if (Seq[i]==0)
        zero++;

        sum+=Seq[i];
    }

    smallest=ABS(n*1000-sum);
    for (i=n-1;i>=n-zero;i--)
    {
        if (ABS(i*1000-sum)<smallest)
        smallest=ABS(i*1000-sum);
    }

    printf("%I64d.",smallest/1000);

    if (smallest%1000>=100)
    printf("%I64d\n",smallest%1000);
    else if (smallest%1000>=10)
    printf("0%I64d\n",smallest%1000);
    else
    printf("00%I64d\n",smallest%1000);

    return 0;
}