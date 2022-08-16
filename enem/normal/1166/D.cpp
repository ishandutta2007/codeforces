#include <bits/stdc++.h>
using namespace std;
#define M 1000000000000000000
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
    ll p = power(x, y/2, m);
    p = (p * p);

    return (y%2 == 0)? p : (x * p);
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */

    int q;
    cin>>q;
    while(q--)
    {
        ll a,b,m;
        cin>>a>>b>>m;
        if(a==b)
        {
            cout<<1<<' '<<a<<'\n';
            continue;
        }
        ll k=logint((b/(a+1)+1),2)+1;
        ll x=(a+1)*power(2,k-2,M);
        ll  v[k];
        v[0]=a;
        ll r[k];
        REP(i,0,k) r[i]=1;
        r[0]=a;
        ll diff=b-x;
        REP(i,1,k-1)
        {
            if(diff==0) break;
            else
            {
                ll ket=power(2,k-i-2,M);
                ll y=diff/ket;
                if(y>m-1) y=m-1;
                r[i]+=y;
                diff-=y*ket;
            }
        }
        if(diff<=m-1)
        {
            r[k-1]+=diff;
            diff-=diff;
            REP(i,1,k)
            {
                v[i]=2*v[i-1]+r[i]-r[i-1];
            }
            cout<<k<<' ';
            REP(i,0,k)
            {
                cout<<v[i]<<' ';
            }
            cout<<'\n';
        }
        else
        {
            cout<<-1<<'\n';
        }
    }
    return 0;
}