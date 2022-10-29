#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, dd, m, k, T, jj, a[200001];
vector<pll> v;

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

void solve()
{
    cin >> n;
    vector<ll> vx, vy;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vx.pb(x);
        vy.pb(y);
    }
    sort(all(vx));
    sort(all(vy));
    ll z=0, u=0;
    if ((int)vx.size()%2)
    {
        z=1;
    }else
    {
        z=(vx[(int)vx.size()/2]-vx[(int)vx.size()/2-1]+1);
    }

    if ((int)vy.size()%2)
    {
        u=1;
    }else
    {
        u=(vy[(int)vy.size()/2]-vy[(int)vy.size()/2-1]+1);
    }
    cout << z*u << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

10
4 1 7 6 5 5 4 2 3 1
*/