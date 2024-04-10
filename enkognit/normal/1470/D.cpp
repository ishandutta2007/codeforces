#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define cringe exit(0)
#define y1 Enkognit

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 999999001;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-10;
mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, Z, a[300005], kl[300005];
vector<ll> v, c[300005];
bool tt[300001];

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}



ll binpow(ll h, ll r)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h;
        h*=h;
        r /= 2;
    }
    return l;
}

void dfs(int h)
{
    k++;
    a[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!a[c[h][i]]) dfs(c[h][i]);
}

void dfs2(int h)
{
    tt[h]=1;
    if (a[h]==1)
    {
        v.pb(h);
        vector<int> z;
        for (int i = 0; i < c[h].size(); i++)
            if (a[c[h][i]]==1)
            {
                z.pb(c[h][i]);
                a[c[h][i]]=2;
            }
        for (int i = 0; i < z.size(); i++) dfs2(z[i]);
    }else
    {
        for (int i = 0; i < c[h].size(); i++)
            if (!tt[c[h][i]]) dfs2(c[h][i]);
    }
}

void solve()
{
    cin >> n >> m;
    v.clear();
    for (int i = 1; i <= n; i++) c[i].clear(), a[i]=0, tt[i]=0;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    k=0;
    dfs(1);
    if (k!=n)
    {
        cout << "NO\n";
        return;
    }
    dfs2(1);
    cout << "YES\n";
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
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

*/