#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int negative[101];
Int positive[101];
Int zeroes[101];
Int neg=0,pos=0,zer=0;

int main()
{
    Int n;
    Int i;
    Int num;
    Int sng;
    Int endnums;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&num);
        if (num<0)
        {
            neg++;
            negative[neg]=num;
        }
        else if (num==0)
        {
            zer++;
            zeroes[zer]=num;
        }
        else
        {
            pos++;
            positive[pos]=num;
        }
    }

    sng=2;
    printf("1 %I64d\n",negative[1]);
    endnums=-1;

    if (pos!=0)
    {
        printf("1 %I64d\n",positive[1]);
        endnums-=1;
    }
    else
    {
        printf("2 %I64d %I64d\n",negative[2],negative[3]);
        endnums-=2;
        sng=4;
    }

    endnums+=zer+neg+pos;
    printf("%I64d ",endnums);

    for (i=2;i<=pos;i++)
    {
        printf("%I64d ",positive[i]);
    }
    for (i=sng;i<=neg;i++)
    {
        printf("%I64d ",negative[i]);
    }
    for (i=1;i<=zer;i++)
    {
        printf("0");
        if (i!=zer)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}