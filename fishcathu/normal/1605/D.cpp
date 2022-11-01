#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
void cmin(auto &l,auto r){l=l<r?l:r;}
void cmax(auto &l,auto r){l=l>r?l:r;}
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
vector<int>a[2];
int ans[N];
void dfs(int x,int f,bool k)
{
    a[k].pb(x);
    for(int t:to[x])if(t^f)dfs(t,x,!k);
}
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)to[i].clear();
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs(1,0,0);
    for(int l,r=n;r;r=l-1)
    {
        l=1<<__lg(r);
        bool k=a[1].size()>a[0].size();
        for(int i=l;i<=r;++i)ans[a[k].back()]=i,a[k].pop_back();
    }
    for(int i=1;i<=n;++i)write(ans[i],' ');
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}