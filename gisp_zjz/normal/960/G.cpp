#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<iostream>
#define maxn 250000

using namespace std;
typedef long long ll;

const ll mod=998244353;

ll b[maxn],c[maxn],n,m,k,p,q,ans;

ll pow_(ll x,ll y)
{
    ll rt=1; while (y){if (y&1) rt=rt*x%mod; x=x*x%mod; y>>=1;} return rt;
}

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

struct poly{
    ll ws[maxn],sz;
}a;

poly solve(ll x,ll y)
{
    poly tmp;
    if (x==y){
        tmp.sz=2; tmp.ws[0]=x; tmp.ws[1]=1; return tmp;
    }
    ll mid=(x+y)/2;
    poly tmp1=solve(x,mid);
    poly tmp2=solve(mid+1,y);
    ll size=digbit(tmp1.sz+tmp2.sz-1);
    for (int i=tmp1.sz;i<size;i++) tmp1.ws[i]=0;
    for (int i=tmp2.sz;i<size;i++) tmp2.ws[i]=0;
    fft(tmp1.ws,size); fft(tmp2.ws,size);
    for (int i=0;i<size;i++) tmp.ws[i]=tmp1.ws[i]*tmp2.ws[i]%mod;
    ifft(tmp.ws,size); tmp.sz=tmp1.sz+tmp2.sz-1;
    return tmp;
}

int main()
{
    scanf("%d%d%d",&n,&p,&q); n--; p--; q--;
    if (p+q>n||p<0||q<0) {printf("0\n");return 0;}
    if (n==0) {printf("%d\n",!p&&!q); return 0;}
    a=solve(0,n-1);
    ans=a.ws[p+q];
    //for (int i=0;i<=n;i++) printf("%d ",a.ws[i]); printf("\n");
    for (int i=1;i<=p+q;i++) ans=ans*i%mod;
    for (int i=1;i<=p;i++) ans=ans*pow_(i,mod-2)%mod;
    for (int i=1;i<=q;i++) ans=ans*pow_(i,mod-2)%mod;
    cout << ans << endl;
    return 0;
}