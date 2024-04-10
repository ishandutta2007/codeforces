#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k,maxn,a[200001];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        maxn=-1<<30;
        scanf("%d%d",&n,&k);
        for(register int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            maxn=max(maxn,a[i]);
        }
        for(register int i=1;i<=n;++i)
            a[i]=maxn-a[i];
        if(k&1)
            for(register int i=1;i<=n;++i)
                printf("%d ",a[i]);
        else
        {
            maxn=-1<<30;
            for(register int i=1;i<=n;++i)
                maxn=max(maxn,a[i]);
            for(register int i=1;i<=n;++i)
                printf("%d ",maxn-a[i]);
        }
        puts("");
    }
    return 0;
}