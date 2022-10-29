#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, T, sm, a[100005];
int tt[20000001];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

ll binpow(ll h,ll r,ll md)
{


    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

//vector<ll> z;

void solve()
{
    ll c, d, x;
    cin >> c >> d >> x;
    ll p=sqrt(x);
    vector<ll> v;
    for (int i = 1; i <= p; i++)
        if (x%i==0)
        {
            v.pb(i);
            if (x/i!=i) v.pb(x/i);
        }
    ll kl=0;
    for (int i = 0; i < v.size(); i++)
        if ((d+x/v[i])%c==0)
        {
            ll z=(d+x/v[i])/c;
            //cout << " " << z << " " << tt[z] << "\n";
            kl+=(1<<tt[z]);
        }
    cout << kl << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 2; i <= 2e7; i++)
        if (tt[i]==0)
        {
            //z.pb(i);
            ll j=i;
            while (j<=2e7) tt[j]++, j+=i;
        }
    //cout << z.size() << "\n";
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}