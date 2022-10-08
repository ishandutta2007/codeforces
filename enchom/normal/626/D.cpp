#include <iostream>
#include <stdio.h>
using namespace std;
typedef long double Double;

int Chance[5011];
int total=0;
int n;
int balls[2011];

Double DChance[5011];
Double Suffix[5011];

Double ans=0;

int ABS(int a)
{
    if (a<0)
    return -a;
    else
    return a;
}

int main()
{
    int i,j;
    int dif;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&balls[i]);
    }

    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            total++;

            Chance[ABS(balls[i]-balls[j])]++;
        }
    }

    for (i=1;i<=5000;i++)
    {
        DChance[i]=(Double)Chance[i]/(Double)total;
    }

    Suffix[5000]=DChance[5000];
    for (i=4999;i>=1;i--)
    {
        Suffix[i]=Suffix[i+1]+DChance[i];
    }

    for (i=1;i<=5000;i++)
    {
        for (j=1;j<=5000;j++)
        {
            if (i+j<5000)
            ans+=DChance[i]*DChance[j]*Suffix[i+j+1];
        }
    }

    printf("%.10f\n",(double)ans);

    return 0;
}