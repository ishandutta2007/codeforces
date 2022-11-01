#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E5+10;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
vector<int>to[N];
int fa[N],son[N],dep[N],top[N],siz[N];
int dfn[N],cnt,tot;
int a[N<<1],dp[310];
const int p=1E9+7;
bitset<N>b;
void dfs1(int x)
{
    dfn[x]=++cnt;
    siz[x]=1;
    for(int t:to[x])
    {
        if(t==fa[x])continue;
        fa[t]=x;
        dep[t]=dep[x]+1;
        dfs1(t);
        siz[x]+=siz[t];
        if(siz[t]>siz[son[x]])son[x]=t;
    }
}
void dfs2(int x,int g)
{
    top[x]=g;
    siz[x]+=dfn[x];
    for(int t:to[x])
    {
        if(t!=fa[x])
        {
            dfs2(t,t==son[x]?g:t);
        }
    }
}
int lca(int l,int r)
{
    int u=top[l],v=top[r];
    while(u!=v)
    {
        dep[u]<dep[v]?v=top[r=fa[v]]:u=top[l=fa[u]];
    }
    return dep[l]<dep[r]?l:r;
}
bool cmp(const int l,const int r)
{
    return dfn[l]<dfn[r];
}
void dfs3(int x)
{
    ++tot;
    while(tot<=cnt)
    {
        int t=a[tot];
        if(dfn[t]>=siz[x])break;
        to[x].pb(t);
        to[t].pb(x);
        dfs3(t);
    }
}
void dfs4(int x,int f,int k)
{
    if(b[x])
    {
        a[++cnt]=k++;
        b[x]=0;
    }
    for(int t:to[x])
    {
        if(t!=f)dfs4(t,x,k);
    }
}
int main()
{
    int n=read(),m=read();
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs1(1);
    dfs2(1,1);
    while(m--)
    {
        cnt=read();
        int k=read(),g=read();
        for(int i=1;i<=cnt;++i)b[a[i]=read()]=1;
        a[++cnt]=g;
        sort(a+1,a+1+cnt,cmp);
        for(int i=cnt;i>=2;--i)a[++cnt]=lca(a[i],a[i-1]);
        sort(a+1,a+1+cnt,cmp);
        cnt=unique(a+1,a+1+cnt)-a-1;
        for(int i=1;i<=cnt;++i)to[a[i]].clear();
        dfs3(a[tot=1]);
        cnt=0;
        dfs4(g,0,0);
        sort(a+1,a+1+cnt);
        dp[0]=1;
        for(int i=1;i<=cnt;++i)
        {
            for(int j=min(i,k);j>a[i];--j)
            {
                dp[j]=(dp[j]*1LL*(j-a[i])+dp[j-1])%p;
            }
            dp[a[i]]=0;
        }
        int ans=0;
        for(int i=k;i>a[cnt];--i)
        {
            ans=(ans+dp[i])%p;
            dp[i]=0;
        }
        write(ans,'\n');
    }
}