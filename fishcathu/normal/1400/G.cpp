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
const int N=3E5+10,M=21;
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
int u[N],d[N];
int l[N],r[N],q[N];
int f[N][M<<1];
int y[M],z[M];
int vis[N];
int main()
{
    const int p=998244353;
    int n=read(),m=read();
    u[0]=d[0]=d[1]=1;
    for(int i=2;i<=n;++i)d[i]=(p-p/i)*1LL*d[p%i]%p;
    for(int i=1;i<=n;++i)
    {
        u[i]=u[i-1]*1LL*i%p;
        d[i]=d[i-1]*1LL*d[i]%p;
    }
    for(int i=1;i<=n;++i)
    {
        ++q[l[i]=read()];
        --q[(r[i]=read())+1];
    }
    for(int i=1,s=0;i<=n;++i)
    {
        s+=q[i];
        for(int j=min(i,m<<1);j>=0;--j)
        {
            f[i][j]=f[i-1][j];
            if(s>=i)f[i][j]=(f[i][j]+u[s-j]*1LL*d[i-j]%p*d[s-i])%p;
        }
    }
    for(int i=0;i<m;++i)
    {
        y[i]=read();
        z[i]=read();
    }
    int ans=0;
    for(int s=1<<m;s--;)
    {
        int mn=1,mx=n,sum=0,op=1;
        auto work=[&](int x)
        {
            if(vis[x]!=s)
            {
                vis[x]=s;
                ++sum;
            }
            mn=max(mn,l[x]);
            mx=min(mx,r[x]);
        };
        for(int j=0;j<m;++j)
        {
            if(s>>j&1)
            {
                work(y[j]);
                work(z[j]);
                op=p-op;
            }
        }
        if(mn<=mx)ans=(ans+(f[mx][sum]-f[mn-1][sum]+p)*1LL*op)%p;
    }
    write(ans,'\n');
}