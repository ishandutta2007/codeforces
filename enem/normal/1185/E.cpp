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

    ll q;
    cin>>q;
    while(q--)
    {
        ll n,m;
        cin>>n>>m;
        char gr[n][m];
        vector<pair<ll,ll>> v[26];
        REP(i,0,n)
        {
            REP(j,0,m)
            {
                char c;
                cin>>c;
                gr[i][j]=c;
                if(c!='.')
                {
                    v[c-'a'].PB({i,j});
                }
            }
        }
        ll flag=0;
        ll emp[26]={};
        ll lst=-1;
        REP(i,0,26)
        {
            ll nv=v[i].size();
            if(nv>0)
            {
                lst=i;
                if(v[i][0].F==v[i][nv-1].F)
                {
                    REP(j,v[i][0].S,v[i][nv-1].S+1)
                    {
                        char c=gr[v[i][0].F][j];
                        if(c=='.')
                        {
                            flag=1;
                            break;
                        }
                        else if((c-'a')<i)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1) break;
                }
                else if(v[i][0].S==v[i][nv-1].S)
                {
                    REP(j,0,nv)
                    {
                        if(v[i][j].S!=v[i][0].S)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        REP(j,v[i][0].F,v[i][nv-1].F+1)
                        {
                            char c=gr[j][v[i][0].S];
                            if(c=='.')
                            {
                                flag=1;
                                break;
                            }
                            else if((c-'a')<i)
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                    if(flag==1) break;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            else
            {
                emp[i]=1;
            }
        }
        if(flag==1) cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            cout<<lst+1<<'\n';
            REP(i,0,lst+1)
            {
                if(emp[i]==1)
                {
                    ll nv=v[lst].size();
                    cout<<v[lst][0].F+1<<' '<<v[lst][0].S+1<<' '<<v[lst][nv-1].F+1<<' '<<v[lst][nv-1].S+1<<'\n';
                }
                else
                {
                    ll nv=v[i].size();
                    cout<<v[i][0].F+1<<' '<<v[i][0].S+1<<' '<<v[i][nv-1].F+1<<' '<<v[i][nv-1].S+1<<'\n';
                }
            }
        }
    }

    return 0;
}