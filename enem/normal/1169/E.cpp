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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */

    int n,q;
    cin>>n>>q;
    int a[n];
    int d[n][20];
    int pp[20];
    REP(i,0,20) pp[i]=n;
    REP(i,0,n)
    {
        int t;
        cin>>t;
        a[i]=t;
    }
    REP(i,0,n)
    {
        int t=a[n-1-i];
        int f[20]={};
        REP(j,0,20)
        {
            if(((1<<j)&t)>0)
            {
                d[n-1-i][j]=pp[j];
                f[j]=1;
                pp[j]=n-1-i;
            }
        }
        REP(j,0,20)
        {
            if(f[j]==0)
            {
                int lm=n;
                REP(k,0,20)
                {
                    if(f[k]==1)
                    {
                        int xx=d[n-1-i][k];
                        if(xx!=n) lm=min(lm,d[xx][j]);
                    }
                }
                d[n-1-i][j]=lm;
            }
        }
    }
    REP(i,0,q)
    {
        int t1,t2;
        cin>>t1>>t2;
        t1--;
        t2--;
        int flag=0;
        REP(j,0,20)
        {
            if(((1<<j)&a[t2])>0)
            {
                if(d[t1][j]<=t2)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1) cout<<"Shi\n";
        else cout<<"Fou\n";
    }

    return 0;
}