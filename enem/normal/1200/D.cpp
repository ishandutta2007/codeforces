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
        ll n,k;
        cin>>n>>k;
        ll rl[n];
        ll rr[n];
        ll cl[n];
        ll cr[n];
        REP(i,0,n)
        {
            rl[i]=-1;
            rr[i]=-1;
            cl[i]=-1;
            cr[i]=-1;
        }
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                char t;
                cin>>t;
                if(t=='B')
                {
                    if(rl[i]==-1)
                    {
                        rl[i]=j;
                        rr[i]=j;
                    }
                    else
                    {
                        rr[i]=j;
                    }
                    if(cl[j]==-1)
                    {
                        cl[j]=i;
                        cr[j]=i;
                    }
                    else
                    {
                        cr[j]=i;
                    }
                }
            }
        }
        static ll a[2000][2000];
        REP(i,0,n) REP(j,0,n) a[i][j]=0;
        REP(i,0,n)
        {
            ll t=0;
            REP(j,0,k)
            {
                if(cl[j]>=i&&cr[j]<i+k) t++;
            }
            a[i][0]+=t;
            REP(j,k,n)
            {
                if(cl[j]>=i&&cr[j]<i+k) t++;
                if(cl[j-k]>=i&&cr[j-k]<i+k) t--;
                a[i][j-k+1]+=t;
            }
        }
        REP(i,0,n)
        {
            ll t=0;
            REP(j,0,k)
            {
                if(rl[j]>=i&&rr[j]<i+k) t++;
            }
            a[0][i]+=t;
            REP(j,k,n)
            {
                if(rl[j]>=i&&rr[j]<i+k) t++;
                if(rl[j-k]>=i&&rr[j-k]<i+k) t--;
                a[j-k+1][i]+=t;
            }
        }
        ll ans=0;
        REP(i,0,n)
        {
            REP(j,0,n)
            {
                ans=max(ans,a[i][j]);
            }
        }
        REP(i,0,n)
        {
            if(rl[i]==-1) ans++;
            if(cl[i]==-1) ans++;
        }
        cout<<ans;
    }

    return 0;
}