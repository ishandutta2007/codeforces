#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
bool cmin(auto &l,auto r){return l>r?l=r,1:0;}
bool cmax(auto &l,auto r){return l<r?l=r,1:0;}
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
vector<int>to[N],q;
bool vis[N],flag;
int ans;
void dfs1(int x,int f)
{
    q.pb(x);
    if(vis[x])vis[q[q.size()>>1]]=1;
    else for(int t:to[x])if(t^f)dfs1(t,x);
    q.pop_back();
}
void dfs2(int x,int f)
{
    for(int t:to[x])if(t^f)
    {
        if(vis[t])++ans;
        else if(to[t].size()==1)flag=1;
        else dfs2(t,x);
    }
}
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)to[i].clear(),vis[i]=0;
    while(m--)vis[read()]=1;
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs1(1,0);
    ans=flag=0;
    dfs2(1,0);
    write(flag?-1:ans,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}