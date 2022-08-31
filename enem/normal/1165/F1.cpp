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

int solve(int n1,int n2,int n,int m,int k[],set<int> v[])
{
    int flag=0;
    int dd=(n1+n2)/2;
    int last=0;
    vector<pair<int,int>> x;
    REP(i,0,n)
    {
        if(k[i]!=0)
        {
            if(v[i].empty()==1)
            {
                last+=2*k[i];
            }
            else
            {
                auto it=v[i].upper_bound(dd);
                if(it==v[i].begin())
                {
                    last+=2*k[i];
                }
                else
                {
                    x.PB(MP(*(--it),k[i]));
                }
            }
        }
    }
    sort(x.begin(),x.end());
    int money=0;
    REP(i,0,x.size())
    {
        if(i==0)
        {
            money+=x[i].F;
        }
        else
        {
            money+=x[i].F-x[i-1].F;
        }
        if(money>=x[i].S)
        {
            money-=x[i].S;
        }
        else
        {
            last+=(x[i].S-money)*2;
            money=0;
        }
    }
    if(x.empty()==1)
    {
        money+=dd;
    }
    else
    {
        money+=dd-x[x.size()-1].F;
    }
    if(money>=last) flag=1;


    if(flag==1)
    {
        if(n2==n1+1)
        {
            return n1;
        }
        else
        {
            int ans=solve(n1,dd,n,m,k,v);
            return ans;
        }
    }
    else
    {
        if(n2==n1+1)
        {
            return n2;
        }
        else
        {
            int ans=solve(dd,n2,n,m,k,v);
            return ans;
        }
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

    int n,m;
    cin>>n>>m;
    int k[n];
    REP(i,0,n)
    {
        int t0;
        cin>>t0;
        k[i]=t0;
    }
    set<int> v[n];
    REP(i,0,m)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t2-1].insert(t1);
    }
    int ans=solve(1,400001,n,m,k,v);
    cout<<ans;

    return 0;
}