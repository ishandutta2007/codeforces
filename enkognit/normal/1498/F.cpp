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
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, sz, ans[200005], a[200005];
vector<ll> c[200005], v[200005];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

bool is(ll n)
{
    ll x=n, o=0;
    while (x)
    {
        o+=x%10;
        x/=10;
    }
    return __gcd(n, o)>1;
}

void dfs(int h,int p=-1)
{
    v[h].resize(k*2);
    v[h][0]^=a[h];
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i], h);
            for (int j = 0; j < 2*k; j++)
            {
                v[h][(j+1)%(2*k)]^=v[c[h][i]][j];
            }
        }
}

vector<ll> vv;

void dfs1(int h,int p=-1)
{
    //cout << h << "\n";
    for (int i = 2*k-2; i > -1; i--)
        swap(vv[i+1], vv[i]);
    for (int i = 0; i < 2*k; i++)
        vv[i]^=v[h][i];
    for (int i = k; i < 2*k; i++)
        ans[h]^=vv[i];
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            for (int j = 0; j < 2*k; j++)
                vv[(j+1)%(2*k)]^=v[c[h][i]][j];
            dfs1(c[h][i], h);
            for (int j = 0; j < 2*k; j++)
                vv[(j+1)%(2*k)]^=v[c[h][i]][j];
        }
    for (int i = 0; i < 2*k; i++)
        vv[i]^=v[h][i];
    for (int i = 1; i < 2*k; i++)
        swap(vv[i-1], vv[i]);
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1);
    //cout << "---\n";
    vv.resize(2*k);
    dfs1(1);
    for (int i = 1; i <= n; i++)
        if (ans[i]==0) cout << "0 "; else cout << "1 ";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/