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

void sp(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
    return;
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
    int p[n],p0[n],a[n];
    REP(i,0,n)
    {
        int t;
        cin>>t;
        p[i]=t-1;
        p0[i]=t-1;
        a[i]=i;
    }
    pairsort(p,a,n);
    int m=0;
    int u[5*n],v[5*n];
    REP(d,0,n/2-1)
    {
        int x=n/2-1-d;
        int y=n/2+d;
        if(a[x]<=n/2-1)
        {
            u[m]=a[x];
            v[m]=n-1;
            sp(&p0[u[m]],&p0[v[m]]);
            sp(&a[p0[u[m]]],&a[p0[v[m]]]);
            m++;

            u[m]=n-1;
            v[m]=x;
            sp(&p0[u[m]],&p0[v[m]]);
            sp(&a[p0[u[m]]],&a[p0[v[m]]]);
            m++;
        }
        else
        {
            u[m]=a[x];
            v[m]=0;
            sp(&p0[u[m]],&p0[v[m]]);
            sp(&a[p0[u[m]]],&a[p0[v[m]]]);
            m++;

            u[m]=0;
            v[m]=n-1;
            sp(&p0[u[m]],&p0[v[m]]);
            sp(&a[p0[u[m]]],&a[p0[v[m]]]);
            m++;

            u[m]=n-1;
            v[m]=x;
            sp(&p0[u[m]],&p0[v[m]]);
            sp(&a[p0[u[m]]],&a[p0[v[m]]]);
            m++;
        }
        if(a[y]>=n/2)
        {
            u[m]=a[y];
            v[m]=0;
            sp(&p0[u[m]],&p0[v[m]]);
            sp(&a[p0[u[m]]],&a[p0[v[m]]]);
            m++;

            u[m]=0;
            v[m]=y;
            sp(&p0[u[m]],&p0[v[m]]);
            sp(&a[p0[u[m]]],&a[p0[v[m]]]);
            m++;
        }
        else
        {
            u[m]=a[y];
            v[m]=n-1;
            sp(&p0[u[m]],&p0[v[m]]);
            sp(&a[p0[u[m]]],&a[p0[v[m]]]);
            m++;

            u[m]=n-1;
            v[m]=0;
            sp(&p0[u[m]],&p0[v[m]]);
            sp(&a[p0[u[m]]],&a[p0[v[m]]]);
            m++;

            u[m]=0;
            v[m]=y;
            sp(&p0[u[m]],&p0[v[m]]);
            sp(&a[p0[u[m]]],&a[p0[v[m]]]);
            m++;
        }
    }
    if(a[0]!=0)
    {
        u[m]=0;
        v[m]=n-1;
        sp(&a[u[m]],&a[v[m]]);
        m++;
    }
    cout<<m<<'\n';
    REP(i,0,m)
    {
        cout<<u[i]+1<<' '<<v[i]+1<<'\n';
    }

    return 0;
}