#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M 1000000007
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
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
 
void dfs(ll d[],ll i,ll &ans,ll x[16][16],ll n,ll r[])
{
    if(i==n)
    {
        ll r[n]={};
        REP(j1,0,n)
        {
            REP(j2,0,n)
            {
                r[(j1+d[j2])%n]=max(r[(j1+d[j2])%n],x[j1][j2]);
            }
        }
        ll t=0;
        REP(j,0,n) 
        {
            t+=r[j];
        }
        ans=max(ans,t);
    }
    else
    {
        REP(j,0,n)
        {
            if(r[j]==-1)
            {
                r[j]=1;    
                d[i]=j;
                dfs(d,i+1,ans,x,n,r);
                r[j]=-1;
            }
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
    cin>>q;
    static ll a[16][2005];
    while(q--)
    {
        ll n,m;
        cin>>n>>m;
        vector<tuple<ll,ll,ll>> v;
        REP(i,0,n)
        {
            REP(j,0,m)
            {
                cin>>a[i][j];
                v.PB(MT(a[i][j],i,j));
            }
        }
        sort(v.begin(),v.end());
        ll f[m];
        REP(i,0,m) f[i]=-1;
        ll r[n];
        REP(i,0,n) r[i]=-1;
        ll cntr=0;
        REPI(i,0,v.size())
        {
            if(f[G(2,v[i])]==-1)
            {
                f[G(2,v[i])]=1;
                cntr++;
                if(cntr==n) break;
            }
        }
        ll x[16][16]={};
        cntr=0;
        REP(i,0,m)
        {
            if(f[i]==1)
            {
                REP(j,0,n)
                {
                    x[j][cntr]=a[j][i];
                }
                cntr++;
            }
        }
        REP(j,0,n)
        {
            ll mxi=0;
            ll t[n];
            REP(i,0,n)
            {
                t[i]=x[i][j];
                if(t[i]>t[mxi])
                {
                    mxi=i;
                }
            }
            REP(i,0,n)
            {
                x[i][j]=t[(mxi+i)%n];
            }
        }
        ll d[n];
        d[0]=0;
        ll ans=0;
        r[0]=1;
        dfs(d,1,ans,x,n,r);
        cout<<ans<<'\n';
    }
 
    return 0;
}