#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,ans;
bool vis[200001];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(register int i=0;i<=n+m;++i)
            vis[i]=0;
        ans=0;
        if(n>m)
            n^=m^=n^=m;
        for(register int i=0;i<=n;++i)
            vis[((n+m+1)>>1)-n+i+i]=vis[((n+m)>>1)-n+i+i]=1;
        for(register int i=0;i<=n+m;++i)
            ans+=vis[i];
        printf("%d\n",ans);
        for(register int i=0;i<=n+m;++i)
            if(vis[i])
                printf("%d ",i);
        puts("");
    }
    return 0;
}