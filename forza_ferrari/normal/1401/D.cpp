#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
struct edges
{
    int nxt,to;
}e[100001<<1];
const int mod=1000000007;
int t,n,m,p[100001],tot,h[100001],s[100001],ans,val[100001],cnt;
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs(int k,int f)
{
    s[k]=1;
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k);
        s[k]+=s[e[i].to];
        val[++cnt]=s[e[i].to]*(n-s[e[i].to]);
    }
}
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        tot=ans=cnt=0;
        for(register int i=1;i<n;++i)
        {
            int x,y;
            scanf("%lld%lld",&x,&y);
            add(x,y);
            add(y,x);
        }
        dfs(1,0);
        sort(val+1,val+cnt+1);
        scanf("%lld",&m);
        for(register int i=1;i<=m;++i)
           scanf("%lld",&p[i]);
        while(m<n-1)
            p[++m]=1;
        sort(p+1,p+m+1);
        if(m>n-1)
            for(int i=n;i<=m;++i)
                p[n-1]=p[n-1]*p[i]%mod;
        for(register int i=1;i<n;++i)
            ans=(ans+p[i]*val[i]%mod)%mod;
        printf("%lld\n",ans);
        for(int i=1;i<=n;++i)
            s[i]=h[i]=0;
        for(int i=1;i<=m;++i)
            p[i]=0;
        for(int i=1;i<n;++i)
            val[i]=0;
    }
    return 0;
}