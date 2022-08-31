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

    int n;
    cin>>n;
    int a[n];
    int mind=n;
    REP(i,0,n)
    {
        char c;
        cin>>c;
        a[i]=c-'0';
    }
    VI v;
    REP(i,1,n)
    {
        if(a[i]==0) continue;
        else
        {
            int t=max(i,n-i);
            if(t==mind) v.PB(i);
            else if(t<mind)
            {
                v.clear();
                mind=t;
                v.PB(i);
            }
        }
    }
    int nv=v.size();
    int x[nv][mind+1]={};
    REP(j,0,nv)
    {
        REP(i,0,mind)
        {
            if(v[j]>i) x[j][i]+=a[v[j]-1-i];
            if(n-v[j]>i) x[j][i]+=a[n-1-i];
            if(x[j][i]>9)
            {
                x[j][i+1]=x[j][i]/10;
                x[j][i]=x[j][i]%10;
            }
        }
    }
    int f[nv]={};
    int flag=1;
    while(flag)
    {
        int minx=10;
        REP(i,0,nv)
        {
            if(f[i]==0)
            {
                if(x[i][mind+1-flag]<minx)
                {
                    minx=x[i][mind+1-flag];
                }
            }
        }
        REP(i,0,nv)
        {
            if(f[i]==0)
            {
                if(x[i][mind+1-flag]!=minx)
                {
                    f[i]=1;
                }
            }
        }
        int k=0;
        REP(i,0,nv)
        {
            if(f[i]==0) k++;
        }
        if(k==1) flag=0;
        else flag++;
    }
    REP(i,0,nv)
    {
        if(f[i]==0)
        {
            if(x[i][mind]!=0) cout<<x[i][mind];
            REP(j,0,mind)
            {
                cout<<x[i][mind-1-j];
            }
        }
    }

    return 0;
}