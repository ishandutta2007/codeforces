#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int t;
int n;
int a[100111];

int main()
{
    int i, j;
    int test;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        for (i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
        }

        sort(a+1, a+1+n);

        printf("%d\n", a[n] + a[n-1]);
    }

    return 0;
}