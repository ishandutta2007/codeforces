#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long Int;

Int arr[100001];
Int multi[100001];
Int powerof2[25];

int main()
{
    Int n;
    Int i,j;
    Int total=0;
    
    scanf("%I64d",&n);
    
    powerof2[0]=1;
    for (i=1;i<=24;i++)
    powerof2[i]=powerof2[i-1]*2;
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&arr[i]);
    }
    for (i=1;i<=n-1;i++)
    {
        total=total+arr[i];
        for (j=24;j>=0;j--)
        {
            if (i+powerof2[j]<=n)
            {
                arr[ i+powerof2[j] ]+=arr[i];
                break;
            }
        }
        printf("%I64d\n",total);
    }
    return 0;
}