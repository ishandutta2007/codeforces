#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1ll<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=400010,mod=1e9+7;
int n,q,p[N],a[N],cnt,e[N];
ll t[4*N],m[4*N],T[4*N],M[4*N],Pw[310][1000],pW[310][1000],nd[310];
ll pw(ll a,int i)
{
    ll b=1;
    for(;i;i>>=1,a=a*a%mod) if(i&1) b=b*a%mod;
    return b;
}
ll PW(int a,int b)
{
    if(a>300) return pw(a,b);
    return pW[a][b/500]*Pw[a][b%500]%mod;
}
void build(int s,int l,int r)
{
    m[s]=1;
    if(l==r)
    {
        t[s]=a[l];
        forinc(j,1,cnt) if(a[l]%e[j]==0) T[s]=onbit(T[s],j);
        return;
    }
    int mid=(l+r)/2;
    build(2*s,l,mid);
    build(2*s+1,mid+1,r);
    t[s]=t[2*s]*t[2*s+1]%mod;
    T[s]=T[2*s]|T[2*s+1];
}
void tran(int s,int l,int r)
{
    if(m[s]!=1)
    {
        int mid=(l+r)/2;
        t[2*s]=t[2*s]*PW(m[s],mid-l+1)%mod;
        t[2*s+1]=t[2*s+1]*PW(m[s],r-mid)%mod;
        m[2*s]=m[2*s]*m[s]%mod;
        m[2*s+1]=m[2*s+1]*m[s]%mod;
        m[s]=1;
    }
    if(M[s]!=0)
    {
        T[2*s]|=M[s];
        T[2*s+1]|=M[s];
        M[2*s]|=M[s];
        M[2*s+1]|=M[s];
        M[s]=0;
    }
}
void update(int s,int l,int r,int u,int v,ll x,ll y)
{
    if(l>v||r<u) return;
    if(l>=u&&r<=v)
    {
        t[s]=t[s]*PW(x,r-l+1)%mod;
        T[s]|=y;M[s]|=y;
        m[s]=m[s]*x%mod;
        return;
    }
    tran(s,l,r);
    int mid=(l+r)/2;
    update(2*s,l,mid,u,v,x,y);
    update(2*s+1,mid+1,r,u,v,x,y);
    t[s]=t[2*s]*t[2*s+1]%mod;
    T[s]=T[2*s]|T[2*s+1];
}
ll get(int s,int l,int r,int u,int v)
{
    if(l>v||r<u) return 1;
    if(l>=u&&r<=v) return t[s];
    int mid=(l+r)/2;
    tran(s,l,r);
    return (get(2*s,l,mid,u,v)*get(2*s+1,mid+1,r,u,v))%mod;
}
ll get2(int s,int l,int r,int u,int v)
{
    if(l>v||r<u) return 0;
    if(l>=u&&r<=v) return T[s];
    int mid=(l+r)/2;
    tran(s,l,r);
    return (get2(2*s,l,mid,u,v)|get2(2*s+1,mid+1,r,u,v));
}
main()
{
    //freopen("1114F.inp","r",stdin);
    forinc(i,2,300) if(!p[i])
    {
        e[++cnt]=i;
        for(int j=i;j<=300;j+=i) p[j]=i;
    }
    forinc(i,1,300)
    {
        Pw[i][0]=pW[i][0]=1;
        forinc(j,1,500) Pw[i][j]=Pw[i][j-1]*i%mod;
        forinc(j,1,800) pW[i][j]=pW[i][j-1]*Pw[i][500]%mod;
        nd[i]=pw(i,mod-2);
    }
    n=in,q=in;
    forinc(i,1,n) a[i]=in;
    build(1,1,n);
    while(q--)
    {
        string s=ins;
        int l=in,r=in;
        if(s.size()==7)
        {
            ll ans=get(1,1,n,l,r);
            ll b=get2(1,1,n,l,r);
            forinc(i,1,cnt) if(bit(b,i)) ans=(ans*(e[i]-1)%mod*nd[e[i]])%mod;
            cout<<ans<<"\n";
        }
        else
        {
            int x=in;
            ll y=0;
            forinc(i,1,cnt) if(x%e[i]==0) y=onbit(y,i);
            update(1,1,n,l,r,x,y);
        }
    }
}