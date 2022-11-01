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
const int N=301;
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
const int p=998244353;
int m;
vct to[N];
int f[N][2][N],sum[N],c[2][N];
void dp(int *a,int *b,int *c)
{
    for(int i=0,j=p-b[0];i>=-m;--i)
    {
        j=((j+b[i])%p+b[-i])%p;
        c[i]=(c[i]+a[i]*1LL*j)%p;

    }
    for(int i=1,j=0;i<=m;++i)
    {
        j=((j+b[i])%p+b[1-i])%p;
        c[i]=(c[i]+a[i]*1LL*j)%p;
    }
}
void dfs(int x,int fa)
{
    for(int i=-m;i<=m;++i)f[x][1][i]=0;
    f[x][1][0]=1;
    for(int t:to[x])
    {
        if(t==fa)continue;
        dfs(t,x);
        for(int i=-m;i<=m;++i)c[1][i]=(p-f[x][1][i]*1LL*f[t][1][i]%p)%p;
        dp(f[x][1],f[t][1],c[1]);
        dp(f[t][1],f[x][1],c[1]);
        for(int i=-m;i<=m;++i)f[x][1][i]=c[1][i];
    }
    for(int i=-m;i<=m;++i)f[x][1][m+1]=(f[x][1][m+1]+f[x][1][i])%p;
    for(int i=-m;i<=m;++i)f[x][1][i]=f[x][1][i+1];
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
    for(m=1;m<n;++m)
    {
        dfs(1,0);
        for(int i=0;i<=m;++i)sum[m]=(sum[m]+f[1][1][i])%p;
    }
    int ans=n-1;
    for(int i=2;i<n;++i)ans=(ans+(i-1)*1LL*(sum[i]-sum[i-1]+p))%p;
    for(ll i=(p-2)*1LL*n,j=2;i;i>>=1)
    {
        if(i&1)ans=ans*j%p;
        j=j*j%p;
    }
    write(ans,'\n');
}