#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define REP(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define VI vector<int>
#define VLL vector<long long>

int modInverse(int a, int m);
int gcd(int a, int b);
int power(int x, unsigned int y, unsigned int m);
void pairsort(int a[], int b[], int n);
int logint(int x,int y);


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        int q = a / m;
        int t = m;

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

void pairsort(int a[], int b[], int n)
{
    pair<int, int> pairt[n];

    // Storing the respective array
    // elements in pairs.
    for (int i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }

    // Sorting the pair array.
    sort(pairt, pairt + n);

    // Modifying original arrays
    for (int i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}

ll powwwer(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = powwwer(x, y/2);
    p = (p * p);

    return (y%2 == 0)? p : (x * p);
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

ll xd(ll n)
{
    ll ans=0;
    ll t=logint(n+1,(ll)2)-1;
    if(t%2)
    {
        ll x=(powwwer(4,t/2 + 1) - 1)/3;
        ans+=((x%M)*(x%M))%M;
        ans+=(((n-x)%M)*((n-x+1)%M))%M;
    }
    else
    {
        ll x=(powwwer(4,t/2) - 1)*2/3;
        ans+=((x%M)*((x+1)%M))%M;
        ans+=(((n-x)%M)*((n-x)%M))%M;
    }
    return ans;
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


    ll l,r;
    cin>>l>>r;
    ll ans=0;
    ans+=xd(r)%M;
    if(l>1) ans-=xd(l-1)%M;
    if(ans<0) ans+=M;
    cout<<ans;

    return 0;
}