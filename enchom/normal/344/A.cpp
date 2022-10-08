#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

char str[2];
Int arr[100001];

int main()
{
    Int n;
    Int i;
    Int ctr=1;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%s",str);

        arr[i]=(str[0]-'0')*2+(str[1]-'0');

        if (i>1)
        if (arr[i]!=arr[i-1])
        {
            ctr++;
        }
    }

    printf("%I64d\n",ctr);

    return 0;
}