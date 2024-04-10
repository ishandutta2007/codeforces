#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=2E5+10;
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
vct to[N];
int fa[N],son[N],siz[N],dep[N],top[N];
int las[N],q[2][N],s[2];
ll ans[N];
void dfs1(int x)
{
    siz[x]=1;
    son[x]=0;
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
void dfs2(int x,int p)
{
    top[x]=p;
    for(int t:to[x])
    {
        if(t!=fa[x])
        {
            dfs2(t,t==son[x]?p:t);
        }
    }
}
int lca(int l,int r)
{
    int u=top[l],v=top[r];
    while(u!=v)
    {
        dep[u]>dep[v]?u=top[l=fa[u]]:v=top[r=fa[v]];
    }
    return dep[l]<dep[r]?l:r;
}
ll solve0()
{
    ll ans=0;
    for(int x:to[1])ans+=siz[x]*1LL*(siz[x]-1)>>1;
    return ans;
}
ll solve1()
{
    ll ans=0;
    int s=0;
    vct w;
    for(int x:to[1])
    {
        int t=siz[x];
        if(lca(x,2)==x)t-=siz[2];
        w.pb(t);
        s+=t;
    }
    for(int x:w)ans+=x*1LL*(s-x);
    return ans/2+siz[1]-siz[2]-1;
}
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)
    {
        to[i].clear();
        ans[i]=0;
    }
    for(int i=n;--i;)
    {
        int u=read()+1,v=read()+1;
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs1(1);
    dfs2(1,1);
    for(int i=0;i<=1;++i)q[i][s[i]=0]=1;
    for(int i=2,now;i<=n;++i)
    {
        bool bo=0;
        for(int j=0;j<=1;++j)
        {
            int k=lca(i,q[j][s[j]]);
            if(k==q[j][s[j]])
            {
                now=q[j][++s[j]]=i;
                las[now]=i;
                bo=1;
                break;
            }
            if(k==i)
            {
                las[now]=i;
                bo=1;
                break;
            }
            if(k!=1)break;
        }
        if(!bo)break;
    }
    ans[0]=solve0();
    ans[1]=solve1();
    for(int x:to[1])
    {
        if(lca(x,2)==x)
        {
            siz[1]-=siz[x];
            break;
        }
    }
    int y[2]={1,1};
    while(y[0]<=s[0]||y[1]<=s[1])
    {
        bool w=y[0]>s[0]||y[1]<=s[1]&&q[1][y[1]]<q[0][y[0]];
        ++y[w];
        int z[2]={siz[q[0][y[0]-1]],siz[q[1][y[1]-1]]};
        if(y[0]<=s[0]||y[1]<=s[1])
        {
            bool k=y[0]>s[0]||y[1]<=s[1]&&q[1][y[1]]<q[0][y[0]];
            z[k]-=siz[q[k][y[k]]];
        }
        ans[las[q[w][y[w]-1]]]=z[0]*1LL*z[1];
    }
    for(int i=0;i<=n;++i)write(ans[i],' ');
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}