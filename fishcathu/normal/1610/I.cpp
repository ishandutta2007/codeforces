#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=3E5+10;
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
vector<int>to[N];
int f[N],fa[N];
bool vis[N];
void dfs(int x)
{
    for(int t:to[x])if(t^fa[x])
    {
        fa[t]=x;
        dfs(t);
        f[x]^=f[t]+1;
    }
}
int main()
{
    int n=read();
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs(1);
    int ans=f[1];
    vis[1]=1;
    putchar(49+!ans);
    for(int i=2;i<=n;++i)
    {
        for(int j=i;!vis[j];j=fa[j])
        {
            ans^=f[j]+1^f[j]^1;
            vis[j]=1;
        }
        putchar(49+!ans);
    }
}