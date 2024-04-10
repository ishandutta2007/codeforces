#include <iostream>
#include <stdio.h>
using namespace std;

int depth[100111];
int depthctr[100111];
int n;

int main()
{
    int i;
    int p;
    int ans=0;

    scanf("%d",&n);

    depth[1]=1;

    for (i=2;i<=n;i++)
    {
        scanf("%d",&p);

        depth[i]=depth[p]+1;
    }

    for (i=1;i<=n;i++)
    {
        depthctr[ depth[i] ]++;
    }

    for (i=1;i<=n;i++)
    {
        ans+=depthctr[i]%2;
    }

    printf("%d\n",ans);

    return 0;
}