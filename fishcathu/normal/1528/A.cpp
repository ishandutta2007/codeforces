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
int l[N],r[N];
vct to[N];
ll y[N],z[N];
void dfs(int x,int f)
{
    y[x]=z[x]=0;
    for(int t:to[x])
    {
        if(t==f)continue;
        dfs(t,x);
        y[x]+=max(y[t]+abs(l[x]-l[t]),z[t]+abs(l[x]-r[t]));
        z[x]+=max(y[t]+abs(r[x]-l[t]),z[t]+abs(r[x]-r[t]));
    }
}
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)
    {
        l[i]=read();
        r[i]=read();
        to[i].clear();
    }
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs(1,0);
    write(max(y[1],z[1]),'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}