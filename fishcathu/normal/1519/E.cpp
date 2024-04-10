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
typedef pair<ll,ll> pll;
const int N=4E5+10;
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
pll l[N>>1],r[N>>1],q[N];
vector<pii>to[N],ans;
int dfn[N],laz[N],cnt;
pll init(ll l,ll r)
{
    ll m=__gcd(l,r);
    return mp(l/m,r/m);
}
void dfs(int x)
{
    if(dfn[x])return;
    dfn[x]=++cnt;
    for(pii t:to[x])
    {
        dfs(t.fi);
        if(dfn[t.fi]<dfn[x])continue;
        if(laz[t.fi])
        {
            ans.pb(mp(t.se,laz[t.fi]));
            laz[t.fi]=0;
        }
        else if(laz[x])
        {
            ans.pb(mp(t.se,laz[x]));
            laz[x]=0;
        }
        else laz[x]=t.se;
    }
}
int main()
{
    int n=read(),m=0;
    for(int i=1;i<=n;++i)
    {
        int a=read(),b=read(),c=read(),d=read();
        q[++m]=l[i]=init((a+b)*1LL*d,b*1LL*c);
        q[++m]=r[i]=init(a*1LL*d,b*1LL*(c+d));
    }
    sort(q+1,q+1+m);
    m=unique(q+1,q+1+m)-q-1;
    for(int i=1;i<=n;++i)
    {
        int u=lower_bound(q+1,q+1+m,l[i])-q;
        int v=lower_bound(q+1,q+1+m,r[i])-q;
        to[u].pb(mp(v,i));
        to[v].pb(mp(u,i));
    }
    for(int i=1;i<=m;++i)dfs(i);
    write(ans.size(),'\n');
    for(pii x:ans)
    {
        write(x.fi,' ');
        write(x.se,'\n');
    }
}