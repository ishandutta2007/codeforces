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

    int n;
    cin>>n;
    string s;
    cin>>s;
    int k[n];
    if(s[0]=='(') k[0]=1;
    else k[0]=-1;
    REP(i,1,n)
    {
        if(s[i]=='(') k[i]=k[i-1]+1;
        else k[i]=k[i-1]-1;
    }
    int ans=0;
    int flag=0;
    if(k[n-1]==2)
    {
        REP(i,0,n)
        {
            if(k[i]<0)
            {
                ans=0;
                break;
            }
            if(k[i]<2&&flag==1)
            {
                flag=0;
                ans=0;
            }
            if(s[i]=='('&&k[i]>=2)
            {
                flag=1;
                ans++;
            }
        }
    }
    else if(k[n-1]==-2)
    {
        REP(i,0,n)
        {
            if(k[i]<-2)
            {
                ans=0;
                break;
            }
            if(s[i]==')'&&k[i]>=-2&&flag==0)
            {
                ans++;
            }
            if(k[i]<0)
            {
                flag=1;
            }
        }
    }
    cout<<ans;

    return 0;
}