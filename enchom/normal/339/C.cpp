#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int F[11][11][1001];
bool allowed[11];
char inp[11];
Int m;

void Calc(Int a,Int b,Int k)
{
    if (F[a][b][k]!=0)
    {
        return;
    }

    Int i;

    if (k==1)
    {
        if (a==b)
        {
            F[a][b][k]=1;
        }
        else
        {
            F[a][b][k]=-1;
        }
    }
    else
    {
        if (a<=b)
        {
            F[a][b][k]=-1;
        }
        else
        {
            for (i=1;i<=10;i++)
            {
                if (!allowed[i] || i==a)
                continue;

                Calc(i,a-b,k-1);

                if (F[i][a-b][k-1]!=-1)
                {
                    F[a][b][k]=i;
                    return;
                }
            }

            F[a][b][k]=-1;
        }
    }

    return;
}

void PrintAns(Int a,Int b,Int k)
{
    if (k==1)
    {
        printf("%I64d",a);
    }
    else
    {
        PrintAns( F[a][b][k],a-b,k-1 );
        printf("%I64d",a);
    }

    if (k!=m)
    {
        printf(" ");
    }

    return;
}

int main()
{
    Int i,j;

    memset(F,0,sizeof(F[0][0][0])*11*11*1001);

    scanf("%s",inp);
    scanf("%I64d",&m);

    for (i=0;i<=9;i++)
    {
        if (inp[i]=='1')
        {
            allowed[i+1]=true;
        }
        else
        {
            allowed[i+1]=false;
        }
    }

    for (i=1;i<=10;i++)
    {
        if (!allowed[i])
        {
            continue;
        }
        for (j=1;j<=10;j++)
        {
            Calc(i,j,m);

            if (F[i][j][m]!=-1)
            {
                printf("YES\n");
                PrintAns(i,j,m);
                printf("\n");
                return 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}