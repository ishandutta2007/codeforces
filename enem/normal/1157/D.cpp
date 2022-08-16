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
void pairsort(int a[], int b[], int n);
int logint(int x,int y);


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

ll powwwer(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = powwwer(x, y/2, m) % m;
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

int logint(int x,int y)
{
    int ans=0;
    int a=1;
    for(int i=0;i<x;i++)
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

    ll n,k;
    cin>>n>>k;
    ll str;
    if(k<=30)
    {
        ll x=powwwer(2,k,1000000000000000000);
        str=((n-1)/(x-1))+1;
    }
    else str=1;
    ll t=n-k*(k+1)/2-(str-1)*k;
    if(t<0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    ll cur;
    REP(i,0,k)
    {
        if(i==0)
        {
            cout<<str<<' ';
            cur=str;
            continue;
        }
        ll t1=t/(k-(ll)i);
        if(t1<cur)
        {
            t-=t1*(k-(ll)i);
            cout<<cur+t1+1<<' ';
            cur=cur+t1+1;
        }
        else
        {
            t-=(cur-1)*(k-(ll)i);
            cout<<2*cur<<' ';
            cur=2*cur;
        }
    }


    return 0;
}