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

    ll n;
    cin>>n;
    ll a[n];
    ll x[n];
    REP(i,0,n)
    {
        ll t;
        cin>>t;
        a[i]=t;
        x[i]=i+1;
    }
    pairsortll(a,x,n);
    ll d[n-1];
    set<ll> st;
    ll xi;
    ll yi;
    REP(i,1,n)
    {
        d[i-1]=a[i]-a[i-1];
        st.insert(d[i-1]);
    }
    if(n==2||n==3)
    {
        cout<<1;
    }
    else
    {
        ll flag=0;
        if((a[n-1]-a[1])%(n-2)==0)
        {
            ll c=(a[n-1]-a[1])/(n-2);
            REP(i,1,n-1)
            {
                if(d[i]!=c)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) cout<<x[0];
        }
        else flag=1;
        if(flag==1)
        {
            flag=0;
            if((a[n-2]-a[0])%(n-2)==0)
            {
                ll c=(a[n-2]-a[0])/(n-2);
                REP(i,0,n-2)
                {
                    if(d[i]!=c)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0) cout<<x[n-1];
            }
            else flag=1;
            if(flag==1)
            {
                flag=0;
                ll f2=0;
                if((a[n-1]-a[0])%(n-2)==0)
                {
                    ll c=(a[n-1]-a[0])/(n-2);
                    REP(i,0,n-1)
                    {
                        if(d[i]!=c&&f2==0)
                        {
                            if(d[i]+d[i+1]==c)
                            {
                                f2=i+1;
                                i++;
                            }
                            else
                            {
                                flag=1;
                                break;
                            }
                        }
                        else if(d[i]!=c)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0) cout<<x[f2];
                }
                else flag=1;
                if(flag==1) cout<<-1;
            }
        }
    }
    return 0;
}