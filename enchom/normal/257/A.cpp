#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int sockets[101];

int main()
{
    Int n,m,k;
    Int i;
    Int freeones;
    Int actions=0;
    
    scanf("%I64d %I64d %I64d",&n,&m,&k);
    
    freeones=k;
    if (freeones>=m)
    {
        printf("0\n");
        return 0;
    }
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&sockets[i]);
    }
    
    sort(sockets+1,sockets+1+n);
    
    for (i=n;i>=1;i--)
    {
        if (sockets[i]>1)
        {
            freeones=freeones+sockets[i]-1;
            actions++;
            
            if (freeones>=m)
            break;
        }
        else
        break;
    }
    if (freeones>=m)
    {
        printf("%I64d\n",actions);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}