#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int progressbar[101];

int main()
{
    Int i,j;
    Int n,k,t;
    Int x;
    
    scanf("%I64d %I64d %I64d",&n,&k,&t);
    
    x=(n*k*t)/100;
    
    for (i=0;i<=100;i++)
    {
        progressbar[i]=0;
    }
    for (i=1;i<=100;i++)
    {
        for (j=1;j<=k;j++)
        {
            if (x==0)
            break;
            
            progressbar[i]++;
            x--;
        }
        if (x==0)
        break;
    }
    for (i=1;i<=n;i++)
    {
        printf("%I64d",progressbar[i]);
        if (i!=n)
        printf(" ");
    }
    printf("\n");
    return 0;
}