#include <iostream>
#include <stdio.h>
using namespace std;

int n,t;
int a[100001];

int main()
{
    int i;
    int cur=1;

    scanf("%d %d",&n,&t);

    for (i=1;i<=n-1;i++)
    {
        scanf("%d",&a[i]);
    }

    while(cur<t)
    {
        cur+=a[cur];
    }

    if (cur==t)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}