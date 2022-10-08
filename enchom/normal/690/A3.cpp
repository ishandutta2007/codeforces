#include <iostream>
#include <stdio.h>
using namespace std;

int t;
int n,r;

int main()
{
    int i;
    int test,a,sum=0;
    int guess=0;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d",&n,&r);

        sum=0;
        guess=0;
        for (i=1;i<=n-1;i++)
        {
            scanf("%d",&a);

            sum+=(a-1);
        }

        sum%=n;

        guess=0;
        while((sum+guess)%n!=r-1)
        guess++;

        printf("%d\n",guess+1);
    }

    return 0;
}