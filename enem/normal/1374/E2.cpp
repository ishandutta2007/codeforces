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

void build(ll v,ll tl,ll tr,ll st[],ll stn[],pll x[])
{
    if(tl==tr)
    {
        st[v]=x[tl].F;
        stn[v]=1;
        return;
    }
    build((v<<1),tl,((tl+tr)>>1),st,stn,x);
    build((v<<1)|1,((tl+tr)>>1)+1,tr,st,stn,x);
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    stn[v]=stn[(v<<1)]+stn[(v<<1)|1];
    return;
}

void update(ll v,ll tl,ll tr,ll pos,bool set,ll st[],ll stn[],pll x[])
{
    if(pos>tr||pos<tl)
    {
        return;
    }
    if(tl==tr&&tl==pos)
    {
        if(set)
        {
            st[v]=x[tl].F;
            stn[v]=1;
        }
        else
        {
            st[v]=0;
            stn[v]=0;
        }
        return;
    }
    update((v<<1),tl,((tl+tr)>>1),pos,set,st,stn,x);
    update((v<<1)|1,((tl+tr)>>1)+1,tr,pos,set,st,stn,x);
    st[v]=st[(v<<1)]+st[(v<<1)|1];
    stn[v]=stn[(v<<1)]+stn[(v<<1)|1];
    return;
}

ll query(ll v,ll tl,ll tr,ll val,ll st[],ll stn[])
{
    if(tl==tr)
    {
        if(val==0) return 0LL;
        else if(val==1&&stn[v]==1) return st[v];
        else return (1LL<<60);
    }
    if(stn[(v<<1)]<=val)
    {
        return st[v<<1]+query((v<<1)|1,((tl+tr)>>1)+1,tr,val-stn[v<<1],st,stn);
    }
    else
    {
        return query((v<<1),tl,((tl+tr)>>1),val,st,stn);
    }
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

        ll n,m,k;
        cin>>n>>m>>k;
        V(pll) v[4];
        pll x[n];
        REP(i,0,n)
        {
            ll t,a,b;
            cin>>t>>a>>b;
            v[(a<<1)|b].PB(MP(t,i));
            x[i]=MP(t,i);
        }
        sort(x,x+n);
        map<ll,ll> re;
        REP(i,0,n)
        {
            re[x[i].S]=i;
        }
        REP(j,0,4)
        {
            if(!v[j].empty())
                sort(v[j].begin(),v[j].end());

            for(auto &it:v[j])
                it.S=re[it.S];
        }
        ll st[4*n],stn[4*n];
        build(1,0,n-1,st,stn,x);
        ll ans=(1LL<<60),anspt=-1;
        if(min((ll)v[1].size(),(ll)v[2].size())+v[3].size()>=k)
        {
            ll pt=min((ll)v[3].size(),k);
            ll cur1=0;
            REP(i,0,pt)
            {
                cur1+=v[3][i].F;
                update(1,0,n-1,v[3][i].S,false,st,stn,x);
            }
            REP(i,0,k-pt)
            {
                cur1+=v[1][i].F;
                update(1,0,n-1,v[1][i].S,false,st,stn,x);
                cur1+=v[2][i].F;
                update(1,0,n-1,v[2][i].S,false,st,stn,x);
            }
            ll cur2=query(1,0,n-1,m-(2*k-pt),st,stn);
            if(cur1+cur2<ans)
            {
                ans=cur1+cur2;
                anspt=pt;
            }
            while(pt>0)
            {
                if(k-pt>=min((ll)v[1].size(),(ll)v[2].size())) break;
                cur1-=v[3][pt-1].F;
                update(1,0,n-1,v[3][pt-1].S,true,st,stn,x);
                cur1+=v[1][k-pt].F;
                update(1,0,n-1,v[1][k-pt].S,false,st,stn,x);
                cur1+=v[2][k-pt].F;
                update(1,0,n-1,v[2][k-pt].S,false,st,stn,x);
                pt--;
                ll cur2=query(1,0,n-1,m-(2*k-pt),st,stn);
                if(cur1+cur2<ans)
                {
                    ans=cur1+cur2;
                    anspt=pt;
                }
            }
        }
        if(anspt==-1) cout<<-1;
        else
        {
            cout<<ans<<'\n';
            bool f[n];
            REP(i,0,n)
            {
                f[i]=false;
            }
            REP(i,0,anspt)
            {
                f[v[3][i].S]=true;
                m--;
            }
            REP(i,0,k-anspt)
            {
                f[v[1][i].S]=true;
                f[v[2][i].S]=true;
                m-=2;
            }
            REP(i,0,n)
            {
                if(!f[i]&&m>0)
                {
                    f[i]=true;
                    m--;
                }
            }
            V(ll) ansv;
            REP(i,0,n)
            {
                if(f[i]) ansv.PB(x[i].S+1);
            }
            sort(ansv.begin(),ansv.end());
            for(auto it:ansv) cout<<it<<' ';
        }

        cout<<'\n';
    }

    return 0;
}