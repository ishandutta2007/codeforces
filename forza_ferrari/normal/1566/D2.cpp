#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,m,a[301][301],node[301*301],p[301*301],qwq[301*301],del[301*301],sum[301][301*301],ans,cnt;
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x,int root)
{
    for(;x<=cnt;x+=lowbit(x))
        ++sum[root][x];
}
inline int query(int x,int root)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=sum[root][x];
    return res;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans=cnt=0;
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=m;++j)
            {
                scanf("%d",&a[i][j]);
                node[++cnt]=a[i][j];
                p[cnt]=del[cnt]=qwq[cnt]=0;
            }
        sort(node+1,node+cnt+1);
        cnt=unique(node+1,node+cnt+1)-node-1;
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=m;++j)
                ++p[a[i][j]=lower_bound(node+1,node+cnt+1,a[i][j])-node];
        for(register int i=1;i<=cnt;++i)
        {
            p[i]+=p[i-1];
            while((((p[i]-1)/m+1)-((p[i-1]-1)/m+1)>1)||(((p[i]-1)/m+1)-((p[i-1]-1)/m+1)==1&&p[i]%m==0)||(i==1&&p[i]>=m))
            {
                p[i]-=m;
                del[i]+=m;
            }
            if(((p[i]-1)/m+1)-(p[i-1]/m+1)||del[i])
                qwq[i]=max(p[i]-p[i-1]-p[i]%m,0);
        }
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=m;++j)
            {
                if(qwq[a[i][j]])
                {
                    int tmp=p[a[i][j]]/m+1;
                    ans+=query(a[i][j]-1,tmp-1);
                    update(a[i][j],tmp-1);
                    --qwq[a[i][j]];
                    continue;
                }
                if(del[a[i][j]])
                {
                    --del[a[i][j]];
                    continue;
                }
                int tmp=(p[a[i][j]]-1)/m+1;
                ans+=query(a[i][j]-1,tmp);
                update(a[i][j],tmp);
            }
        printf("%d\n",ans);
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=cnt;++j)
                sum[i][j]=0;
    }
    return 0;
}