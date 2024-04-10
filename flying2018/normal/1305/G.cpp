#include<iostream>
#include<cstdio>
#include<cstring>
#define M 18
#define N (1<<M)
#define ll long long
using namespace std;
int a[N+5],f[N+5],fa[N+5];
ll sf[N+5];
int find(int x){return x==fa[x]?fa[x]:(fa[x]=find(fa[x]));}
int g[N+5][2],h[N+5][2];
int main()
{
    int n;
    ll ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n+1;i++) fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        ans-=a[i];
    }
    int cnt=n;
    while(cnt)
    {
        for(int i=0;i<N;i++) g[i][0]=g[i][1]=h[i][0]=h[i][1]=-1;
        for(int i=1;i<=n+1;i++)
        {
            int u=find(i);
            if(h[a[i]][0]==-1) g[a[i]][0]=a[i],h[a[i]][0]=u;
            else if(h[a[i]][1]==-1 && h[a[i]][0]!=u) g[a[i]][1]=a[i],h[a[i]][1]=u;
        }
        for(int i=0;i<M;i++)
            for(int s=0;s<N;s++)
            if((s>>i)&1)
            {
                int t=s^(1<<i);
                for(int _=0;_<=1;_++)
                    if(g[t][_]>g[s][0] || (g[t][_]==g[s][0] && h[t][_]!=h[s][0]))
                    {
                        if(h[t][_]!=h[s][0]) g[s][1]=g[s][0],h[s][1]=h[s][0];
                        g[s][0]=g[t][_],h[s][0]=h[t][_];
                    }
                    else if(g[t][_]>g[s][1] && h[t][_]!=h[s][0]) g[s][1]=g[t][_],h[s][1]=h[t][_];
            }
        for(int i=1;i<=n+1;i++) sf[i]=f[i]=-1;
        for(int i=1;i<=n+1;i++)
        {
            int s=(N-1)^a[i],t=find(i);
            if(g[s][0]==-1) continue;
            for(int _=0;_<=1;_++)
            if((g[s][_]^a[i])>sf[t] && h[s][_]!=t)
                f[t]=h[s][_],sf[t]=g[s][_]^a[i];
        }
        for(int i=1;i<=n+1;i++)
        if(i==find(i) && sf[i]>=0 && find(f[i])!=find(i))
        {
            fa[find(i)]=find(f[i]);
            --cnt;
            ans+=sf[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}