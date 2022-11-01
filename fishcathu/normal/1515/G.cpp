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
vector<pii>to[N];
int dfn[N],low[N],cnt;
ll dis[N],ans[N];
vct q;
bitset<N>b;
void dfs(int x,ll d)
{
    if(dfn[x])return;
    dfn[x]=low[x]=++cnt;
    dis[x]=d;
    q.pb(x);
    for(pii t:to[x])
    {
        dfs(t.fi,d+t.se);
        if(b[t.fi])continue;
        low[x]=min(low[x],low[t.fi]);
        ans[x]=__gcd(ans[x],abs(d+t.se-dis[t.fi]));
    }
    if(dfn[x]!=low[x])return;
    while(1)
    {
        int t=q.back();
        q.pop_back();
        low[t]=x;
        b[t]=1;
        if(t==x)return;
        ans[x]=__gcd(ans[x],ans[t]);
    }
}
int main()
{
    int n=read();
    for(int m=read();m--;)
    {
        int u=read(),v=read();
        to[u].pb(mp(v,read()));
    }
    for(int i=1;i<=n;++i)dfs(i,0);
    for(int m=read();m--;)
    {
        ll x=ans[low[read()]];
        int y=read(),z=read();
        puts((z-y)%__gcd(x,z*1LL)?"NO":"YES");
    }
}