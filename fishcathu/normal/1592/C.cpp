#include<bits/extc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E5+10;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
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
int a[N],y,z;
vector<int>to[N];
void dfs(int x,int f)
{
    for(int t:to[x])
    {
        if(t==f)continue;
        dfs(t,x);
        a[x]^=a[t];
    }
    if(a[x]==y)a[x]=0,++z;
}
bool solve()
{
    int n=read(),m=read();
    y=z=0;
    for(int i=1;i<=n;++i)y^=a[i]=read(),to[i].clear();
    while(--n)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    if(!y)return 1;
    if(m==2)return 0;
    dfs(1,0);
    return z^1;
}
int main()
{
    for(int x=read();x--;)
    {
        puts(solve()?"YES":"NO");
    }
}