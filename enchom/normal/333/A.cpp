#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int ctr=0;
Int n;

void Solve(Int k)
{
    if (n%k==0)
    {
        Solve(3*k);
    }
    else
    {
        ctr=n/k+1;
    }

    return;
}

int main()
{
    scanf("%I64d",&n);

    Solve(3);

    printf("%I64d\n",ctr);

    return 0;
}