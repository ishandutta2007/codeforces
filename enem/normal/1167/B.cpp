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

void solve(int a,int b,int c,int d,int ans[],int t[],int f[],int i)
{
    if(i==6)
    {
        if(ans[0]*ans[1]==a&&ans[1]*ans[2]==b&&ans[3]*ans[4]==c&&ans[4]*ans[5]==d)
        {
            cout<<"! ";
            REP(j,0,6)
            {
                cout<<ans[j]<<' ';
            }
            cout<<endl;
            exit(0);
        }
    }
    else
    {
        REP(j,0,6)
        {
            if(f[j]==0)
            {
                ans[i]=t[j];
                f[j]=1;
                solve(a,b,c,d,ans,t,f,i+1);
                f[j]=0;
            }
        }
    }
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

    int a,b,c,d;
    cout<<"? 1 2"<<endl;
    cin>>a;
    cout<<"? 2 3"<<endl;
    cin>>b;
    cout<<"? 4 5"<<endl;
    cin>>c;
    cout<<"? 5 6"<<endl;
    cin>>d;
    int ans[6];
    int t[6]={4,8,15,16,23,42};
    int f[6]={};
    solve(a,b,c,d,ans,t,f,0);

    return 0;
}