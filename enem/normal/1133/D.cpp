#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long

ll modInverse(ll a, ll m);
ll gcd(ll a, ll b);
ll power(ll x, unsigned ll y, unsigned ll m);


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

void lmao(ll *a,ll *b)
{
    ll x,y;
    if(*a<0) x=(-*a);
    else x=*a;
    if(*b<0) y=(-*b);
    else y=*b;
    ll l=gcd(x,y);
    if(l!=0)
    {
        *a/=l;
        *b/=l;
    }
    if(*a<0)
    {
        *a=-*a;
        *b=-*b;
    }
    return;
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;
    ll a[n],b[n];
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>b[i];
        if(b[i]==0) ans++;
    }
    for(ll i=0;i<n;i++)
    {
        lmao(&a[i],&b[i]);
    }
    ll temp=1;
    ll aa[n],bb[n];
    ll c=0;
    ll zero=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]!=0&&b[i]!=0)
        {
            aa[c]=a[i];
            bb[c]=b[i];
            c++;
        }
        if(a[i]==0&&b[i]==0) zero++;
    }
    if(c!=0) ans=max(temp+zero,ans);
    pairsort(aa,bb,c);
    for(ll i=1;i<c;i++)
    {
        if(aa[i]==aa[i-1]&&bb[i]==bb[i-1])
        {
            temp++;
        }
        else
        {
            temp=1;
        }
        ans=max(temp+zero,ans);
    }
    cout<<ans;

    return 0;
}