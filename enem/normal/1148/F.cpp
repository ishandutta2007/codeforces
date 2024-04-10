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

void pairsort(ll a[],ll b[], ll n)
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
    ll val[n],mask[n];
    ll sum=0;
    ll a[n][62]={};
    REP(i,0,n)
    {
        ll t1,t2;
        cin>>t1>>t2;
        val[i]=t1;
        sum+=t1;
        mask[i]=t2;
    }
    if(sum<0) REP(i,0,n) val[i]-=2*val[i];
    if(sum<0) sum-=2*sum;
    REP(i,0,n)
    {
        ll t2=mask[i];

        ll j=0;
        while(t2>0)
        {
            a[i][j]=(t2%2);
            t2/=2;
            j++;
        }
    }
    ll ans[62]={};
    ll t=1;
    REP(i,0,62)
    {
        ll x=0;
        REP(j,0,n)
        {
            if(mask[j]<2*t&&mask[j]>=t)
            {
                ll f=0;
                REP(k,0,i)
                {
                    if(ans[k]==1&&a[j][k]==1)
                    {
                        f++;
                    }
                }
                if(f%2) x+=val[j];
                else x-=val[j];
            }
        }
        if(x<0)
        {
            ans[i]=1;
        }
        t*=2;
    }
    ll s=0;
    t=1;
    REP(i,0,62)
    {
       s+=ans[i]*t;
       t*=2;
    }
    cout<<s;

    return 0;
}