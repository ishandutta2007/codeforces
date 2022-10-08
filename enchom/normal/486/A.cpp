#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int n;

int main()
{
    scanf("%I64d",&n);

    if (n%2==0)
    {
        printf("%I64d\n",n/2);
    }
    else
    {
        printf("%I64d\n",-(n+1)/2);
    }

    return 0;
}