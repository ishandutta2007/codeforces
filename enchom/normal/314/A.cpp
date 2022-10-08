#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int a[200001];

int main()
{
    Int n,k;
    Int i;
    Int currentsum=0;
    Int d;
    Int cur=0;

    scanf("%I64d %I64d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }

    i=1;
    while(i<=n)
    {
        cur++;

        d=currentsum-(i-1)*a[cur]*(n-i);

        if (d<k)
        {
            n--;
            printf("%I64d\n",cur);
        }
        else
        {
            currentsum=currentsum+a[cur]*(i-1);
            i++;
        }
    }

    return 0;
}