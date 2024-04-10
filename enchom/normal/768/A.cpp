#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100111];
int n;

int main()
{
    int i,j;
    int ctr=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a+1,a+1+n);

    for (i=1;i<=n;i++)
    {
        if (a[i]!=a[1] && a[i]!=a[n])
        ctr++;
    }

    printf("%d\n",ctr);

    return 0;
}