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
void pairsort(int a[], int b[], int n);
void pairsortll(ll a[],ll b[],ll n);
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

void pairsortll(ll a[], ll b[], ll n)
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

    ll n,m;
    cin>>n>>m;
    ll a[n][m]={};
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            char c;
            cin>>c;
            if(c=='*') a[i][j]=1;
        }
    }
    ll flag=0;
    REP(i,1,n-1)
    {
        REP(j,1,m-1)
        {
            if(a[i][j]==1&&a[i+1][j]==1&&a[i-1][j]==1&&a[i][j+1]==1&&a[i][j-1]==1)
            {
                flag=1;
                ll i1=i+1;
                ll i2=i-1;
                ll j1=j+1;
                ll j2=j-1;
                while(a[i1][j]==1)
                {
                    a[i1][j]=0;
                    i1++;
                    if(i1>=n) break;
                }
                while(a[i2][j]==1)
                {
                    a[i2][j]=0;
                    i2--;
                    if(i2<0) break;
                }
                while(a[i][j1]==1)
                {
                    a[i][j1]=0;
                    j1++;
                    if(j1>=m) break;
                }
                while(a[i][j2]==1)
                {
                    a[i][j2]=0;
                    j2--;
                    if(j2<0) break;
                }
                a[i][j]=0;
            }
            if(flag==1) break;
        }
        if(flag==1) break;
    }
    ll k=1;
    REP(i,0,n) REP(j,0,m) if(a[i][j]==1) k=0;
    if(k==1&&flag==1) cout<<"YES";
    else cout<<"NO";

    return 0;
}