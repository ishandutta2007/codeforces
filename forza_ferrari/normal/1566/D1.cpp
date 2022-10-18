#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m,a[301],node[301],sum[301],ans,cnt;
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x)
{
    for(;x<=cnt;x+=lowbit(x))
        ++sum[x];
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[x];
    return res;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans=0;
        for(register int i=1;i<=m;++i)
        {
            scanf("%d",&a[i]);
            node[i]=a[i];
        }
        sort(node+1,node+m+1);
        cnt=unique(node+1,node+m+1)-node-1;
        for(register int i=1;i<=m;++i)
        {
            a[i]=lower_bound(node+1,node+cnt+1,a[i])-node;
            ans+=query(a[i]-1);
            update(a[i]);
        }
        printf("%d\n",ans);
        for(register int i=1;i<=cnt;++i)
            sum[i]=0;
    }
    return 0;
}