#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define VI vector<int>
#define VLL vector<long long>

ll modInverse(ll a, ll m);
ll gcd(ll a, ll b);
ll power(ll x, unsigned ll y, unsigned ll m);
ll logint(ll x,ll y);


ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

ll power(ll x, unsigned ll y, unsigned ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        ll q = a / m;
        ll t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}

void pairsort(ll a[], ll b[], ll n)
{
    pair<ll, ll> pairt[n];

    // Storing the respective array
    // elements in pairs.
    for (ll i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }

    // Sorting the pair array.
    sort(pairt, pairt + n);

    // Modifying original arrays
    for (ll i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}

ll logint(ll x,ll y)
{
    ll ans=0;
    ll a=1;
    for(ll i=0;i<x;i++)
    {
        if(x<=a)
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

    ll n;
    cin>>n;
    ll a[n],b[n],p[n];
    REP(k,0,n)
    {
        ll t;
        cin>>t;
        a[k]=t;
        p[k]=k+1;
    }
    REP(k,0,n)
    {
        ll t;
        cin>>t;
        b[k]=t;
    }
    pairsort(a,p,n);
    sort(b,b+n);

    ll i=0;
    ll j=0;

    ll u[n+n],v[n+n],w[n+n];
    ll m=0;
    while(j!=n)
    {
        if(a[i]>b[i])
        {
            cout<<"NO";
            return 0;
        }
        if(a[j]<=b[j])
        {
            j++;
            continue;
        }
        if(a[i]==b[i])
        {
            i++;
            continue;
        }
        ll x=b[i]-a[i];
        ll y=a[j]-b[j];
        ll d=min(x,y);
        a[i]+=d;
        a[j]-=d;
        u[m]=p[i];
        v[m]=p[j];
        w[m]=d;
        m++;
    }
    while(i!=n)
    {
        if(a[i]!=b[i])
        {
            cout<<"NO";
            return 0;
        }
        else i++;
    }
    cout<<"YES\n"<<m<<'\n';
    REP(k,0,m)
    {
        cout<<u[k]<<' '<<v[k]<<' '<<w[k]<<'\n';
    }


    return 0;
}