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
    string s,t;
    cin>>s>>t;
    int f1[26]={},f2[26]={};
    REP(i,0,n)
    {
        f1[s[i]-'a']++;
        f2[t[i]-'a']++;
    }
    REP(i,0,26)
    {
        if(f1[i]!=f2[i])
        {
            cout<<-1;
            return 0;
        }
    }
    int v[10000];
    int k=0;
    while(true)
    {
        int f=-1;
        REP(i,0,n)
        {
            if(s[i]!=t[i])
            {
                f=i;
                break;
            }
        }
        if(f==-1) break;
        int j;
        REP(i,f,n)
        {
            if(s[i]==t[f])
            {
                j=i;
                break;
            }
        }
        for(int i=j-1;i>=f;i--)
        {
            char c=s[i];
            s[i]=s[i+1];
            s[i+1]=c;
            v[k]=i+1;
            k++;
        }
    }
    cout<<k<<'\n';
    REP(i,0,k)
    {
        cout<<v[i]<<' ';
    }

    return 0;
}