#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<iostream>
#define maxn 262145

using namespace std;
typedef long long ll;

const ll mod=998244353;

ll a[maxn],b[maxn],c[maxn],n,m,size,k;
ll p[maxn],q[maxn],P[maxn];

ll lowbit(ll x)
{
    return x&(-x);
}

ll digbit(ll x)
{
    while (x!=lowbit(x)) x+=lowbit(x);
    return x;
}

ll power(ll x,ll y)
{
    if (y==0) return 1;
    ll tmp=power(x,y/2);
    tmp=(ll)tmp*tmp%mod;
    if (y%2==1) tmp=(ll)tmp*x%mod;
    return tmp;
}

ll create_w(ll w[],ll size)
{
    ll tmp=power(3,(mod-1)/size);
    w[0]=1;
    for (ll i=1;i<size;i++)
        w[i]=(ll)w[i-1]*tmp%mod;
}

ll create_id(ll id[],ll size,ll m)
{
    for (ll i=0;i<size;i++)
    {
        id[i]=0;
        for (ll j=0;j<m;j++)
            if ((i>>j)%2==1) id[i]+=1<<(m-j-1);
    }
}

void fft(ll d[],ll size)
{
     ll m=0,tmp=size;
     while (tmp>1)
     {
         m++;
         tmp/=2;
     }
     ll r[size],w[size],id[size];
     create_w(w,size);
     create_id(id,size,m);
     for (ll i=0;i<size;i++)
         r[i]=d[id[i]];
     for (ll i=1;i<=m;i++)
     {
         ll s=1<<i;
         for (ll j=0;j<size/s;j++)
             for (ll k=j*s;k<j*s+s/2;k++)
             {
                 ll r1=r[k];
                 ll r2=(ll)r[k+s/2]*w[size/s*(k-j*s)]%mod;
                 r[k]=(r1+r2)%mod;
                 r[k+s/2]=(r1-r2+mod)%mod;
             }
     }
     for (ll i=0;i<size;i++)
         d[i]=r[i];
}

void ifft(ll d[],ll size)
{
     ll m=0,tmp=size;
     while (tmp>1)
     {
         m++;
         tmp/=2;
     }
     ll r[size],w[size],id[size];
     create_w(w,size);
     create_id(id,size,m);
     for (ll i=0;i<size;i++)
         r[i]=d[i];
    for (ll i=m;i>=1;i--)
    {
        ll s=1<<i;
        for (ll j=0;j<size/s;j++)
            for (ll k=j*s;k<j*s+s/2;k++)
            {
                ll r1=r[k];
                ll r2=r[k+s/2];
                r[k]=(r1+r2)%mod;
                r[k+s/2]=(ll)(r1-r2+mod)*w[(size/s*(j*s-k)+size)%size]%mod;
                if (r[k]%2==1) r[k]=(r[k]+mod)/2; else r[k]=r[k]/2;
                if (r[k+s/2]%2==1) r[k+s/2]=(r[k+s/2]+mod)/2; else r[k+s/2]=r[k+s/2]/2;
            }
    }
     for (ll i=0;i<size;i++)
         d[i]=r[id[i]];
}

ll pow_(ll x,ll y)
{
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return rt;
}

ll inv(ll x)
{
    return pow_(x,mod-2);
}

int main()
{
    scanf("%lld%lld",&n,&m); n++;
    p[0]=q[0]=1;
    for (int i=1;i<=n;i++) p[i]=p[i-1]*i%mod,q[i]=q[i-1]*inv(i)%mod;
    ll size=digbit(n*2);
    for (int i=1;i<=n;i++) scanf("%lld",&P[i]);
    memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
    for (int i=0;i<=n;i++) a[i]=P[n-i]*p[n-i-1]%mod;
    for (int i=0;i<n;i++) b[i]=q[i];
    fft(a,size);
    fft(b,size);
    for (ll i=0;i<size;i++)
        c[i]=(ll)a[i]*b[i]%mod;
    ifft(c,size);
    for (ll i=0;i<=n;i++) if (i&1) c[i]=(mod-c[i])%mod;
    for (ll i=n+1;i<size;i++) c[i]=0;
    for (ll i=0;i<n;i++) c[i]=c[i]*pow_(inv(n-i),m)%mod;
    fft(c,size);
    for (ll i=0;i<size;i++) a[i]=(ll)c[i]*b[i]%mod;
    ifft(a,size);
    for (int i=0;i<n;i++) if (i&1) a[i]=(mod-a[i])%mod;
    for (ll i=0;i<n;i++)
        printf("%d ",a[n-i-1]*q[i]%mod);
    printf("\n");
    return 0;
}