#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n,k;
int f[2001];

int main()
{
    int i;
    int ans=0;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
    }

    sort(f+1,f+1+n);

    for (i=n;i>=1;i-=k)
    {
        ans+=2*(f[i]-1);
    }

    printf("%d\n",ans);

    return 0;
}