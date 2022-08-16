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

    int n,m;
    cin>>n>>m;
    int a[n][m]={};
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            char c;
            cin>>c;
            if(c=='*') a[i][j]=1;
        }
    }
    int k=0;
    int x[n*m],y[n*m],s[n*m];
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            if(a[i][j]==1)
            {
                int c=0;
                while(true)
                {
                    if(i+c<n&&i-c>=0&&j+c<m&&j-c>=0)
                    {
                        if(a[i+c][j]==1&&a[i-c][j]==1&&a[i][j+c]==1&&a[i][j-c]==1)
                        {
                            c++;
                        }
                        else break;
                    }
                    else break;
                }
                c--;
                if(c!=0)
                {
                    x[k]=i+1;
                    y[k]=j+1;
                    s[k]=c;
                    k++;
                }
            }
        }
    }
    int b[n][m]={};
    REP(i,0,k)
    {
        int xx=x[i]-1;
        int yy=y[i]-1;
        b[xx][yy]=1;
        REP(j,1,s[i]+1)
        {
            b[xx+j][yy]=1;
            b[xx-j][yy]=1;
            b[xx][yy+j]=1;
            b[xx][yy-j]=1;
        }
    }
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            if(a[i][j]!=b[i][j])
            {
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<k<<'\n';
    REP(i,0,k)
    {
        cout<<x[i]<<' '<<y[i]<<' '<<s[i]<<'\n';
    }

    return 0;
}