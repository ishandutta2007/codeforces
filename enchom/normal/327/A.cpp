#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int n;
Int sum=0,maxsum=0;
Int ones=0;

int main()
{
    Int i;
    Int num;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&num);

        if (num==0)
        {
            sum++;
        }
        else
        {
            sum--;
            ones++;
        }

        if (sum<0)
        sum=0;

        if (sum>maxsum)
        maxsum=sum;
    }

    if (ones<n)
    printf("%I64d\n",ones+maxsum);
    else
    printf("%I64d\n",ones-1);

    return 0;
}