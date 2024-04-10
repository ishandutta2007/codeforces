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
        ll n,m;
        cin>>n>>m;
        static ll a[5005][5005];
        static ll dp[5005][5005];
        ll ans=0;
        REP(i,0,n)
        {
            REP(j,0,m)
            {
                char c;
                cin>>c;
                a[i][j]=c-'0';
            }
        }
        REP(i,0,n)
        {
            REPI(j,0,m)
            {
                if(a[i][j]==1) dp[i][j]=dp[i][j+1]+1;
                else dp[i][j]=0;
            }
        }
        REP(j,0,m)
        {
            ll tmp[n+1]={};
            REP(i,0,n)
            {
                tmp[dp[i][j]]++;
            }
            ll cur=0;
            REP(i,0,n+1)
            {
                while(tmp[i]>0)
                {
                    tmp[i]--;
                    dp[cur][j]=i;
                    cur++;
                }
            }
            vector<pair<ll,ll>> v;
            REP(i,0,n)
            {
                while(v.size()>0) 
                {
                    if(dp[i][j]>=v[v.size()-1].F) break;
                    ans=max(ans,v[v.size()-1].F*(i+1-v[v.size()-1].S));
                    v.pop_back();
                }
                if(v.size()>0) if(dp[i][j]!=v[v.size()-1].F) v.PB(MP(dp[i][j],i+1));
                if(v.size()==0) v.PB(MP(dp[i][j],i+1));
            }
            while(v.size()>0)
            {
                ans=max(ans,v[v.size()-1].F*(n+1-v[v.size()-1].S));
                v.pop_back();
            }
        }
        cout<<ans;
    }

    return 0;
}