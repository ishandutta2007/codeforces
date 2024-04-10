#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

int main()
{
    int t, test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        llong sum = 0;
        int n;

        scanf("%d", &n);

        for (i=1;i<=n;i++)
        {
            int a;
            scanf("%d", &a);
            sum += a;
        }

        if (sum % n == 0)
            printf("0\n");
        else
            printf("1\n");
    }

    return 0;
}