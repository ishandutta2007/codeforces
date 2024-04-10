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
const int N=2E5+10;
const ll inf=1LL<<60;
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
ll a[N],f[N],g[N];
pii b[N];
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=m;++i)b[i]={read(),read()};
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    a[n+1]=inf;
    f[n+1]=0;
    for(int i=n,j=m;i>=0;--i)
    {
        f[i]=g[i]=inf;
        ll mn=a[i+1];
        while(j&&b[j].fi>=a[i])
        {
            ll u=b[j].fi-a[i],v=a[i+1]-mn;
            ll t=min(f[i+1]+v*2,g[i+1]+v);
            f[i]=min(f[i],t+u);
            g[i]=min(g[i],t+u*2);
            mn=min(mn,b[j].se);
            --j;
        }
        ll v=a[i+1]-mn,t=min(f[i+1]+v*2,g[i+1]+v);
        f[i]=min(f[i],t);
        g[i]=min(g[i],t);
    }
    write(f[0],'\n');
}
int main()
{
    a[0]=-inf;
    for(int x=read();x--;)
    {
        solve();
    }
}