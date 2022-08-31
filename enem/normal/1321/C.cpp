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
    ll ans=1,r=1;
    x%=m;
    while(r>0&&r<=y)
    {
        if(r&y)
        {
            ans*=x;
            ans%=m;
        }
        r<<=1;
        x*=x;
        x%=m;
    }
    return ans;
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

        ll n;
        cin>>n;
        string s;
        cin>>s;
        REPI(j,1,26)
        {
            if(s.size()==1) continue;
            bool flag=0;
            if(flag==0)
            {
                if(s[0]=='a'+j&&s[1]=='a'+j-1)
                {
                    s=s.substr(1,s.size()-1);
                    flag=1;
                }
            }
            if(flag==0)
            {
                REP(i,1,s.size()-1)
                {
                    if(s[i]=='a'+j&&(s[i-1]=='a'+j-1||s[i+1]=='a'+j-1))
                    {
                        s=s.substr(0,i)+s.substr(i+1,s.size()-1-i);
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0)
            {
                if(s[s.size()-1]=='a'+j&&s[s.size()-2]=='a'+j-1)
                {
                    s=s.substr(0,s.size()-1);
                    flag=1;
                }
            }
            if(flag==1) j++;
        }
        cout<<n-s.size();

        cout<<'\n';
    }

    return 0;
}