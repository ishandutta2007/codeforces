#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int squares[51];

int main()
{
    Int n,k;
    Int i;
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&squares[i]);
    }
    
    sort(squares+1,squares+1+n);
    
    if (k>n)
    {
        printf("-1\n");
        return 0;
    }
    
    printf("%I64d %I64d\n",squares[n-k+1],squares[n-k+1]);
    return 0;
}