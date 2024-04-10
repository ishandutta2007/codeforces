#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;
typedef int Int;

Int amount[26];
char inp[500001];
Int L;
Int F[3001][3001];
Int BestChoice[3001][3001];
bool Setted[3001][3001];
Int ctr=0;

void GetF(Int l,Int r)
{
    if (Setted[l][r])
    return;

    Setted[l][r]=true;

    if (r<l)
    return;

    if (l==r)
    {
        BestChoice[l][r]=0;

        F[l][r]=1;
        return;
    }

    if (inp[l]==inp[r])
    {
        BestChoice[l][r]=0;

        GetF(l+1,r-1);
        F[l][r]=F[l+1][r-1]+2;
    }
    else
    {
        GetF(l+1,r);
        GetF(l,r-1);

        if (F[l+1][r]>F[l][r-1])
        {
            BestChoice[l][r]=1;
            F[l][r]=F[l+1][r];
        }
        else
        {
            BestChoice[l][r]=2;
            F[l][r]=F[l][r-1];
        }
    }

    return;
}

void PrintAns(Int l,Int r)
{
    if (r<l)
    return;

    if (l==r)
    {
        printf("%c",inp[l]);
        return;
    }

    if (BestChoice[l][r]==0)
    {
        printf("%c",inp[l]);
        ctr++;

        if (ctr<50)
        PrintAns(l+1,r-1);

        printf("%c",inp[r]);
    }
    else if (BestChoice[l][r]==1)
    {
        PrintAns(l+1,r);
    }
    else
    {
        PrintAns(l,r-1);
    }
}

int main()
{
    Int i,j;
    Int l,r;
    Int test;
    Int themax,themaxl,themaxr;

    scanf("%s",inp);
    L=strlen(inp);

    memset(amount,0,sizeof(amount));
    memset(Setted,false,sizeof(Setted[0][0])*3001*3001);
    memset(F,0,sizeof(F[0][0])*3001*3001);

    for (i=0;i<L;i++)
    {
        amount[ inp[i]-'a' ]++;
    }

    for (i=0;i<=25;i++)
    {
        if (amount[i]>=100)
        {
            for (j=1;j<=100;j++)
            {
                printf("%c",(char)(i+'a'));
            }
            printf("\n");

            return 0;
        }
    }

    GetF(0,L-1);

    PrintAns(0,L-1);
    printf("\n");

    return 0;
}