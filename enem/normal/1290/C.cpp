#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define V(a) vector<a>

template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

ll modI(ll a,ll m);
ll gcd(ll a,ll b);
ll powM(ll x,ll y,ll m);
template<typename T>
void pairsort(T a[],T b[],ll n);
ll logint(ll x,ll y);
void Miden(ll **p1,ll n);
void Mmult(ll **p1,ll **p2,ll **ans,ll x,ll y,ll z,ll m);
void Mpow(ll **p1,ll **ans,ll n,ll y,ll m);
pll Egcd(ll x,ll y);
ll PrimRoot(ll n,ll x);
void fft(ll a[],ll n,bool invert,ll m,ll x);
V(ll) PolyMult(V(ll) &a,V(ll) &b,ll m,ll x);

ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}

pll Egcd(ll x,ll y)
{
    if(x==0) return MP(0,1);
    pll t=Egcd(y%x,x);
    return MP(t.S-t.F*(y/x),t.F);
}

ll powM(ll x,ll y,ll m)
{
    if(y==0) return 1;
    ll p=powM(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}

ll modI(ll a, ll m)
{
    ll m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1)
    {
        ll q=a/m;
        ll t=m;
        m=a%m;
        a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0) x+=m0;
    return x;
}

template<typename T>
void pairsort(T a[],T b[],ll n)
{
    pair<T,T> v[n];
    REP(i,0,n)
    {
        v[i].F=a[i];
        v[i].S=b[i];
    }
    sort(v,v+n);
    REP(i,0,n)
    {
        a[i]=v[i].F;
        b[i]=v[i].S;
    }
}

ll logint(ll x,ll y)
{
    ll ans=0;
    ll a=1;
    for(ll i=0;i<=x;i++)
    {
        if(x<a)
        {
            return ans;
        }
        ans++;
        a*=y;
    }
    return -1;
}

void Miden(ll **p1,ll n)
{
    ll (*x)[n]=(ll(*)[n]) p1;
    REP(i,0,n)
    {
        REP(j,0,n)
        {
            x[i][j]=0;
        }
        x[i][i]=1;
    }
    return;
}

void Mmult(ll **p1,ll **p2,ll **ans,ll x,ll y,ll z,ll m)
{
    ll (*a)[y]=(ll (*)[y])p1;
    ll (*b)[z]=(ll (*)[z])p2;
    ll (*c)[z]=(ll (*)[z])ans;
    REP(i,0,x)
    {
        REP(j,0,z)
        {
            c[i][j]=0;
            REP(k,0,y)
            {
                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]%=m;
            }
        }
    }
    return;
}

void Mpow(ll **p1,ll **ans,ll n,ll y,ll m)
{
    if(y==0)
    {
        Miden(ans,n);
        return;
    }
    ll t[n][n];
    Mpow(p1,(ll **)t,n,y/2,m);
    ll z[n][n];
    Mmult((ll **)t,(ll **)t,(ll **)z,n,n,n,m);
    if(y%2)
    {
        Mmult((ll **)z,p1,ans,n,n,n,m);
    }
    else
    {
        Miden((ll **)t,n);
        Mmult((ll **)z,(ll **)t,ans,n,n,n,m);
    }
    return;
}

ll PrimRoot(ll p,ll x)
{
    //finds primitive root of prime p greater than x(If it doesnt exist, returns 0)
    V(ll) v;
    ll t=p-1;
    REP(i,2,t+1)
    {
        if(i*i>t) break;
        if(t%i==0)
        {
            v.PB((p-1)/i);
            while(t%i==0)
            {
                t/=i;
            }
        }
    }
    if(t>1) v.PB((p-1)/t);
    REP(i,x+1,p)
    {
        ll flag=0;
        REP(j,0,v.size())
        {
            if(powM(i,v[j],p)==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return i;
        }
    }

    return 0;
}

void fft(ll a[],ll n,bool invert,ll m,ll x)
{
    if(n==1) return;
    ll d[2][n>>1];
    REP(i,0,n/2)
    {
        d[0][i]=a[i<<1];
        d[1][i]=a[(i<<1)+1];
    }
    fft(d[0],n>>1,invert,m,(x*x)%m);
    fft(d[1],n>>1,invert,m,(x*x)%m);
    ll r=1;
    if(invert) x=modI(x,m);
    REP(i,0,n>>1)
    {
        a[i]=(d[0][i]+(r*d[1][i])%m)%m;
        if(a[i]<0) a[i]+=m;
        a[i+(n>>1)]=(d[0][i]-(r*d[1][i])%m)%m;
        if(a[i+(n>>1)]<0) a[i+(n>>1)]+=m;
        r*=x;
        r%=m;
    }
    if(invert)
    {
        ll inv2=modI(2,m);
        REP(i,0,n)
        {
            a[i]=(a[i]*inv2)%m;
        }
    }
    return;
}

V(ll) PolyMult(V(ll) &a,V(ll) &b,ll m,ll x)
{
    ll n=1;
    while(n<a.size()+b.size())
    { 
        n<<=1;
    }
    ll fa[n]={};
    ll fb[n]={};
    ll f[n]={};
    REP(i,0,a.size())
    {
        fa[i]=a[i];
    }
    REP(i,0,b.size())
    {
        fb[i]=b[i];
    }
    ll y=powM(x,(m-1)/n,m);
    fft(fa,n,false,m,y);
    fft(fb,n,false,m,y);
    REP(i,0,n)
    {
        f[i]=(fa[i]*fb[i])%m;
    }
    fft(f,n,true,m,y);
    V(ll) v(n);
    REP(i,0,n)
    {
        v[i]=f[i];
    }
    return v;
}

ll fn(ll x,ll rn[])
{
    if(x==rn[x])
        return x;
    else
        return rn[x]=fn(rn[x],rn);
}

ll un(ll x,ll y,ll rn[],ll sz[],ll pl[],ll f[])
{
    x=fn(x,rn);
    y=fn(y,rn);
    if(x==y) 
        return x;
    if(sz[x]<sz[y]) swap(x,y);
    sz[x]+=sz[y];
    pl[x]+=pl[y];
    rn[y]=x;
    if(f[x]==-1) f[x]=f[y];
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */

    ll ntc=1;
    //cin>>ntc;
    REP(tc,1,ntc+1)
    {
        //cout<<"Case #"<<tc<<": ";

        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        V(ll) ad[n];
        REP(i,0,k)
        {
            ll t;
            cin>>t;
            REP(j,0,t)
            {
                ll tt;
                cin>>tt;
                ad[tt-1].PB(i);
            }
        }
        ll rn[2*k],sz[2*k],pl[2*k],f[2*k];
        ll ans=0;
        REP(i,0,2*k)
        {
            rn[i]=i;
            sz[i]=1;
            if(i<k) pl[i]=1;
            else pl[i]=0;
            f[i]=-1;
        }
        REP(i,0,n)
        {
            if(s[i]=='0')
            {
                if(ad[i].size()==1)
                {
                    ll x1=fn(ad[i][0],rn);
                    ll x0=fn(ad[i][0]+k,rn);
                    if(pl[x0]<pl[x1]&&f[x1]==-1)
                    {
                        ans+=pl[x1]-pl[x0];
                    }
                    f[x1]=1;
                    f[x0]=0;
                }
                else if(ad[i].size()==2)
                {
                    ll x1=fn(ad[i][0],rn);
                    ll x0=fn(ad[i][0]+k,rn);
                    ll y1=fn(ad[i][1],rn);
                    ll y0=fn(ad[i][1]+k,rn);
                    ll plx,ply,plt;
                    if(f[x1]==1) plx=pl[x1];
                    else if(f[x0]==1) plx=pl[x0];
                    else plx=min(pl[x1],pl[x0]);
                    if(f[y1]==1) ply=pl[y1];
                    else if(f[y0]==1) ply=pl[y0];
                    else ply=min(pl[y1],pl[y0]);
                    ll t1=un(x1,y0,rn,sz,pl,f);
                    ll t0=un(x0,y1,rn,sz,pl,f);
                    if(f[t1]==1) plt=pl[t1];
                    else if(f[t0]==1) plt=pl[t0];
                    else plt=min(pl[t1],pl[t0]);
                    ans+=max(plt-plx-ply,0LL);
                }
            }
            else
            {
                if(ad[i].size()==1)
                {
                    ll x1=fn(ad[i][0],rn);
                    ll x0=fn(ad[i][0]+k,rn);
                    if(pl[x1]<pl[x0]&&f[x0]==-1)
                    {
                        ans+=pl[x0]-pl[x1];
                    }
                    f[x0]=1;
                    f[x1]=0;
                }
                else if(ad[i].size()==2)
                {
                    ll x1=fn(ad[i][0],rn);
                    ll x0=fn(ad[i][0]+k,rn);
                    ll y1=fn(ad[i][1],rn);
                    ll y0=fn(ad[i][1]+k,rn);
                    ll plx,ply,plt;
                    if(f[x1]==1) plx=pl[x1];
                    else if(f[x0]==1) plx=pl[x0];
                    else plx=min(pl[x1],pl[x0]);
                    if(f[y1]==1) ply=pl[y1];
                    else if(f[y0]==1) ply=pl[y0];
                    else ply=min(pl[y1],pl[y0]);
                    ll t1=un(x1,y1,rn,sz,pl,f);
                    ll t0=un(x0,y0,rn,sz,pl,f);
                    if(f[t1]==1) plt=pl[t1];
                    else if(f[t0]==1) plt=pl[t0];
                    else plt=min(pl[t1],pl[t0]);
                    ans+=max(plt-plx-ply,0LL);
                }
            }
            cout<<ans<<'\n';
        }
        
    }

    return 0;
}