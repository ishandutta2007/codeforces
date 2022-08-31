#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M 1000000007
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
#define VI vector<int>
#define VLL vector<long long>

#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

ll modI(ll a, ll m);
ll gcd(ll a, ll b);
ll powM(ll x, unsigned ll y, unsigned ll m);
void pairsort(int a[], int b[], int n);
void pairsortll(ll a[],ll b[],ll n);
ll logint(ll x,ll y);


ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
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

void pairsort(int a[],int b[],int n)
{
    pair<int,int> v[n];
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

void pairsortll(ll a[],ll b[],ll n)
{
    pair<ll,ll> v[n];
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

void dfs1(ll x,ll y,VLL ad[],ll dep[],ll sz[])
{
    sz[x]=1;
    if(x==0) dep[x]=0;
    else dep[x]=dep[y]+1;
    ll nv=ad[x].size();
    REP(i,0,nv)
    {
        if(ad[x][i]!=y)
        {
            dfs1(ad[x][i],x,ad,dep,sz);
            sz[x]+=sz[ad[x][i]];
        }
    }
    return;
}

void dfs2(ll x,ll y,VLL ad[],ll dep[],ll sz[],ll t1,ll &ans)
{
    ll t;
    if(x==0) t=t1;
    else
    {
        t=(sz[0]-2*sz[x])+t1;
    }
    ans=max(t,ans);
    ll nv=ad[x].size();
    REP(i,0,nv)
    {
        if(ad[x][i]!=y)
        {
            dfs2(ad[x][i],x,ad,dep,sz,t,ans);
        }
    }
    return;
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

    ll q=1;
    //cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        VLL ad[n];
        REP(i,0,n-1)
        {
            ll t1,t2;
            cin>>t1>>t2;
            t1--;
            t2--;
            ad[t1].PB(t2);
            ad[t2].PB(t1);
        }
        ll dep[n];
        ll sz[n];
        dfs1(0,-1,ad,dep,sz);
        ll ans=0;
        REP(i,0,n) ans+=sz[i];
        dfs2(0,-1,ad,dep,sz,ans,ans);
        cout<<ans<<'\n';

    }

    return 0;
}