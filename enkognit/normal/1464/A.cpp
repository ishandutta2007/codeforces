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
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, ans, TT, a[100005];
vector<pll> c[100001];
bool tt[1000001];


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

void dfs(int h,int p=-1)
{
    tt[h]=1;
    ans++;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i].se!=p)
            if (tt[c[h][i].fi]) ans++; else dfs(c[h][i].fi, c[h][i].se);
}

void solve()
{
    cin >> n >> m;
    ans=0;
    for (int i = 1; i <= n; i++) c[i].clear(), tt[i]=0;
    ll k=m;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (x!=y)
        {
            c[x].pb(mp(y, i));
            c[y].pb(mp(x, i));
        }
    }
    for (int i = 1; i <= n; i++)
        if (!tt[i] && c[i].size())
        {
            ans--;
            dfs(i);
        }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
4 4
4 7
5 8
6 4
9 6
1 9 11 8 4
1 3 7 8 2
1 3 6 8 1
1 13 6 3 11


4 8
4 7
5 8
6 4
9 6
1 9 11 8 4
1 3 7 8 2
1 3 6 8 1
1 13 6 3 11
2 6 4 5 8
2 6 6 7 7
2 7 5 9 11
2 5 3 6 6
*/