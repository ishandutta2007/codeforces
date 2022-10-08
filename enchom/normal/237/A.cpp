#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int arr[24][60];

int main()
{
    Int n;
    Int a,b;
    Int i,j;
    Int themax=0;
    
    scanf("%I64d",&n);
    
    for (i=0;i<=23;i++)
    {
        for (j=0;j<=59;j++)
        {
            arr[i][j]=0;
        }
    }
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        arr[a][b]++;
    }
    for (i=0;i<=23;i++)
    {
        for (j=0;j<=59;j++)
        {
            if (arr[i][j]>themax)
            themax=arr[i][j];
        }
    }
    printf("%I64d\n",themax);
    return 0;
}