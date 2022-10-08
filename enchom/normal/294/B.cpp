#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct book
{
    Int thick,wide;
};

Int F[101][201];
book books[101];
Int totalwidth=0;

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main()
{
    Int n;
    Int i,j;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&books[i].thick,&books[i].wide);
        totalwidth=totalwidth+books[i].wide;
    }

    for (i=0;i<=100;i++)
    {
        for (j=0;j<=200;j++)
        {
            F[i][j]=-1;
        }
    }

    F[0][0]=0;

    for (i=1;i<=n;i++)
    {
        for (j=0;j<=200;j++)
        {
            if (j-books[i].thick>=0)
            {
                F[i][j]=MAX( F[i-1][j], F[i-1][j-books[i].thick]+books[i].wide );
            }
            else
            {
                F[i][j]=F[i-1][j];
            }
        }
    }

    for (i=0;i<=200;i++)
    {
        if (F[n][i]!=-1)
        {
            if (totalwidth-F[n][i]<=i)
            {
                printf("%I64d\n",i);
                return 0;
            }
        }
    }

    return 0;
}