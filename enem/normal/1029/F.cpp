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
        ll a,b;
        cin>>a>>b;
        VLL va1,va2,vb1,vb2;
        REP(i,1,sqrt(a)+1)
        {
            if(a%i==0)
            {
                va1.PB(a/i);
                va2.PB(i);
            }
        }
        sort(va1.begin(),va1.end());
        sort(va2.begin(),va2.end());
        ll nva=va1.size();
        REP(i,1,sqrt(b)+1)
        {
            if(b%i==0)
            {
                vb1.PB(b/i);
                vb2.PB(i);
            }
        }
        sort(vb1.begin(),vb1.end());
        sort(vb2.begin(),vb2.end());
        ll nvb=vb1.size();
        REPI(i,1,(ll)sqrt(a+b)+1)
        {
            if((a+b)%i==0)
            {
                ll flag=0;
                ll x1=upper_bound(va1.begin(),va1.end(),(a+b)/i)-va1.begin();
                ll x2=upper_bound(va2.begin(),va2.end(),i)-va2.begin();
                ll y1=upper_bound(vb1.begin(),vb1.end(),(a+b)/i)-vb1.begin();
                ll y2=upper_bound(vb2.begin(),vb2.end(),i)-vb2.begin();
                if(x1+x2>nva) flag=1;
                if(y1+y2>nvb) flag=1;
                if(flag==1)
                {
                    cout<<(2*i+2*(a+b)/i);
                    break;
                }
            }
        }
    }

    return 0;
}