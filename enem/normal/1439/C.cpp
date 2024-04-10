#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M1 1000000007
#define M2 998244353
#define ll long long
#define ld long double
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

static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
#define o_set(T) tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

pll Egcd(ll,ll);
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

bool isprime(ll n)
{
    if(n<2)
        return false;
    for(ll x:{2,3,5,7,11,13,17,19,23,29,31,37})
    {
        if(n==x)
            return true;
        bool flag=true;
        ll r=1;
        ll t=1;
        while(r<=((n-1)>>__builtin_ctzll(n-1)))
        {
            if(r&((n-1)>>__builtin_ctzll(n-1)))
                t=((__int128)t*x)%n;
            x=((__int128)x*x)%n;
            r<<=1;
        }
        if(t==1||t==n-1)
            flag=false;
        for(r=0;r<__builtin_ctzll(n-1);r++)
        {
            t=((__int128)t*t)%n;
            if(t==n-1)
                flag=false;
        }
        if(flag)
            return false;
    }
    return true;
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
        REP(j,0,((ll)v.size()))
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

void fft(V(ll) &a,ll n,bool invert,ll m,ll x)
{
    REP(i,0,n)
    {
        ll y=0;
        REP(j,0,__builtin_ctzll(n))
        {
            if((1LL<<j)&i)
            {
                y|=(1LL<<(__builtin_ctzll(n)-j-1));
            }
        }
        if(y>i)
        {
            swap(a[i],a[y]);
        }
    }
    if(invert) x=modI(x,m);
    REP(s,1,__builtin_ctzll(n)+1)
    {
        ll y=powM(x,(n/(1LL<<s)),m);
        REP(j,0,(n/(1LL<<s)))
        {
            ll r=1;
            REP(i,0,(1LL<<(s-1)))
            {
                ll u=a[i+j*(1LL<<s)];
                ll v=(r*a[i+j*(1LL<<s)+(1LL<<(s-1))])%m;
                a[i+j*(1LL<<s)]=u+v;
                if(a[i+j*(1LL<<s)]>m) a[i+j*(1LL<<s)]-=m;
                a[i+j*(1LL<<s)+(1LL<<(s-1))]=u-v;
                if(a[i+j*(1LL<<s)+(1LL<<(s-1))]<0) a[i+j*(1LL<<s)+(1LL<<(s-1))]+=m;
                r*=y;
                r%=m;
            }
        }
    }
    if(invert)
    {
        ll invn=modI(n,m);
        REP(i,0,n)
        {
            a[i]=(a[i]*invn)%m;
        }
    }
    return;
}

void PolyMult(V(ll) &a,V(ll) &b,V(ll) &v,ll m,ll x)
{
    ll n=1;
    while(n<((ll)a.size())+((ll)b.size()))
    { 
        n<<=1;
    }
    V(ll) fa(a.begin(),a.end());
    fa.resize(n,0);
    V(ll) fb(b.begin(),b.end());
    fb.resize(n,0);
    ll y=powM(x,(m-1)/n,m);
    fft(fa,n,false,m,y);
    fft(fb,n,false,m,y);
    v.resize(n,0);
    REP(i,0,n)
    {
        v[i]=((fa[i]*fb[i])%m);
    }
    fft(v,n,true,m,y);
    v.resize(((ll)a.size())+((ll)b.size())-1,0LL);
    return;
}

void PolyInverse(V(ll) &a,V(ll) &v,ll n,ll m,ll x)
{
    v.clear();
    v.PB(modI(a[0],m));
    while(((ll)v.size())<n)
    {
        ll tmpsz=(((ll)v.size())<<1);
        V(ll) tmpa(tmpsz,0LL);
        REP(i,0,min(((ll)a.size()),tmpsz))
        {
            tmpa[i]=a[i];
        }
        V(ll) tmppr;
        PolyMult(tmpa,v,tmppr,m,x);
        tmppr.resize(tmpsz,0LL);
        REP(i,0,tmpsz)
        {
            tmppr[i]=((M2-tmppr[i])%M2);
        }
        tmppr[0]=((tmppr[0]+2)%M2);
        V(ll) tmpv(v.begin(),v.end());
        PolyMult(tmppr,tmpv,v,m,x);
        v.resize(tmpsz,0LL);
    }
    v.resize(n,0LL);
    return;
}

void PolyDiv(V(ll) &a,V(ll) &b,V(ll) &q,V(ll) &r,ll m,ll x)
{
    if(((ll)a.size())<((ll)b.size()))
    {
        r=a;
        r.resize(((ll)b.size())-1,0LL);
        q.clear();
        q.PB(0LL);
        return;
    }
    V(ll) ra(((ll)a.size())-((ll)b.size())+1,0LL);
    REP(i,0,((ll)a.size())-((ll)b.size())+1)
    {
        ra[i]=a[((ll)a.size())-1-i];
    }
    V(ll) rb(((ll)b.size()),0LL);
    REP(i,0,((ll)b.size()))
    {
        rb[i]=b[((ll)b.size())-1-i];
    }
    V(ll) irb;
    PolyInverse(rb,irb,((ll)a.size())-((ll)b.size())+1,m,x);
    V(ll) rq;
    PolyMult(ra,irb,rq,m,x);
    rq.resize(((ll)a.size())-((ll)b.size())+1,0LL);
    q.resize(((ll)a.size())-((ll)b.size())+1,0LL);
    REP(i,0,((ll)rq.size()))
    {
        q[i]=rq[((ll)rq.size())-1-i];
    }
    V(ll) tmppr;
    PolyMult(b,q,tmppr,m,x);
    r.resize(((ll)b.size())-1,0LL);
    REP(i,0,((ll)r.size()))
    {
        r[i]=((a[i]+M2-tmppr[i])%M2);
    }
    return;
}

ll fn(ll x,ll rn[])
{
    if(x==rn[x])
        return x;
    else
        return rn[x]=fn(rn[x],rn);
}

bool un(ll x,ll y,ll rn[],ll sz[])
{
    x=fn(x,rn);
    y=fn(y,rn);
    if(x==y)
        return false;
    if(sz[x]<sz[y])
        swap(x,y);
    sz[x]+=sz[y];
    rn[y]=x;
    return true;
}

void build(ll v,ll tl,ll tr,ll st[],ll stl[],ll str[],ll lz[],ll a[])
{
    if(tl==tr)
    {
        st[v]=a[tl];
        stl[v]=a[tl];
        str[v]=a[tr];
        lz[v]=0LL;
        return;
    }
    build((v<<1),tl,((tl+tr)>>1),st,stl,str,lz,a);
    build((v<<1)|1,((tl+tr)>>1)+1,tr,st,stl,str,lz,a);
    //operation
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    stl[v]=stl[(v<<1)];
    str[v]=str[(v<<1)|1];
    lz[v]=0LL;
    return;
}

void push2(ll v,ll tl,ll tr,ll st[],ll stl[],ll str[],ll lz[]);

void push(ll v,ll tl,ll tr,ll st[],ll stl[],ll str[],ll lz[])
{
    lz[(v<<1)]=max(lz[(v<<1)],lz[v]);
    push2((v<<1),tl,((tl+tr)>>1),st,stl,str,lz);
    lz[(v<<1)|1]=max(lz[(v<<1)|1],lz[v]);
    push2((v<<1)|1,((tl+tr)>>1)+1,tr,st,stl,str,lz);
    return;
}

void push2(ll v,ll tl,ll tr,ll st[],ll stl[],ll str[],ll lz[])
{
    if(stl[v]<=lz[v])
    {
        st[v]=lz[v]*(tr-tl+1);
        stl[v]=lz[v];
        str[v]=lz[v];
    }
    else if(str[v]<lz[v])
    {
        push(v,tl,tr,st,stl,str,lz);
        st[v]=st[(v<<1)]+st[(v<<1)|1];
        stl[v]=stl[(v<<1)];
        str[v]=str[(v<<1)|1];
    }
    return;
}


void update(ll v,ll tl,ll tr,ll r,ll val,ll st[],ll stl[],ll str[],ll lz[])
{
    if(tl>r)
    {
        return;
    }
    if(tr==r)
    {
        lz[v]=max(lz[v],val);
        push2(v,tl,tr,st,stl,str,lz);
        return;
    }
    push(v,tl,tr,st,stl,str,lz);
    update((v<<1),tl,((tl+tr)>>1),min(r,((tl+tr)>>1)),val,st,stl,str,lz);
    update((v<<1)|1,((tl+tr)>>1)+1,tr,r,val,st,stl,str,lz);
    //operation
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    stl[v]=stl[(v<<1)];
    str[v]=str[(v<<1)|1];
    return;
}

ll query(ll v,ll tl,ll tr,ll l,ll &val,ll st[],ll stl[],ll str[],ll lz[])
{
    if(l>tr||val<str[v])
    {
        return 0LL;
    }
    else if(l==tl&&val>=st[v])
    {
        val-=st[v];
        return tr-tl+1;
    }
    push(v,tl,tr,st,stl,str,lz);
    ll ans=query((v<<1),tl,((tl+tr)>>1),l,val,st,stl,str,lz);
    ans+=query((v<<1)|1,((tl+tr)>>1)+1,tr,max(l,((tl+tr)>>1)+1),val,st,stl,str,lz);
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,q;
    cin>>n>>q;
    ll a[n],st[4*n],stl[4*n],str[4*n],lz[4*n];
    REP(i,0,n)
    {
        ll t;
        cin>>t;
        a[i]=t;
    }
    build(1,0,n-1,st,stl,str,lz,a);
    REP(i,0,q)
    {
        ll typ,x,y;
        cin>>typ>>x>>y;
        if(typ==1)
        {
            update(1,0,n-1,x-1,y,st,stl,str,lz);
        }
        else
        {
            cout<<query(1,0,n-1,x-1,y,st,stl,str,lz)<<'\n';
        }
    }
    return 0;
}