#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

Int columns[32],rows[32];
Int table[32][32];

int main()
{
    Int i,j,n;
    Int winningsq=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            scanf("%I64d",&table[i][j]);
        }
    }
    for (i=1;i<=n;i++)
    {
        columns[i]=0;
        rows[i]=0;
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            rows[i]=rows[i]+table[i][j];
            columns[j]=columns[j]+table[i][j];
        }
    }
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (columns[j]>rows[i])
            winningsq++;
        }
    }
    printf("%I64d\n",winningsq);
    return 0;
}