#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int arr[100001];

int main()
{
    Int n;
    Int i;
    Int k=0;
    Int lastnum=0;
    Int len=0;
    scanf("%I64d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&arr[i]);
    }
    for (i=1;i<=n;i++)
    {
        if (lastnum==0)
        {
            len=1;
            lastnum=1;
        }
        else if (arr[lastnum]==arr[i])
        {
            len++;
        }
        else
        {
            k=k+(len*(len+1))/2;
            len=1;
            lastnum=i;
        }
    }
    k=k+(len*(len+1))/2;
    printf("%I64d\n",k);
    return 0;
}