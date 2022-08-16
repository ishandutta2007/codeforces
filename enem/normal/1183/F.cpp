#include <bits/stdc++.h>
using namespace std;
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
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        ll a[n];
        REP(i,0,n)
        {
            ll t;
            cin>>t;
            a[i]=t;
        }
        sort(a,a+n);
        ll t=a[n-1];
        ll flag=0;
        if(t%30==0)
        {
            ll x=binary_search(a,a+n,t/2);
            ll y=binary_search(a,a+n,t/3);
            ll z=binary_search(a,a+n,t/5);
            if(x&&y&&z)
            {
                flag=(t/2+t/3+t/5);
            }
        }
        ll x=t;
        ll y=0;
        ll z=0;
        ll f=0;
        REP(i,1,n)
        {
            if(x%a[n-1-i]!=0)
            {
                y=a[n-1-i];
                f=i;
                break;
            }
        }
        if(f!=0)
        {
            REP(i,f,n)
            {
                if(x%a[n-1-i]!=0&&y%a[n-1-i]!=0)
                {
                    z=a[n-1-i];
                    break;
                }
            }
        }
        cout<<max(x+y+z,flag)<<'\n';
    }

    return 0;
}