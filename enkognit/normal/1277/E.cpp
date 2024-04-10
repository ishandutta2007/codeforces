#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;
const ll N=1e6+1;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=1e8, p1=31, p2=37, p3=41;

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, ans, TT, l, r, T, i, j, h, a, b, in[N], w[N], kol[N];
bool tt[1000001], q[1000001];
string s, d;
vector <ll> v;
vector <pll> c[200001];



void dfs3(ll h)
{
    tt[h]=1;
    T++;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i].fi]) dfs3(c[h][i].fi);
}

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll qq;
    cin >> qq;
    while (qq--)
    {
        cin >> n >> m >> a >> b;
        TT=0;
        for (int i = 1; i <= n; i++) c[i].clear(), tt[i]=0;
        for (int i = 1; i <= m; i++)
        {
            ll x, y;
            cin >> x >> y;
            q[i]=0;
            c[x].pb(mp(y,i));
            c[y].pb(mp(x,i));
        }
        tt[b]=1;
        T=1;
        dfs3(a);
        ll ans1=n-T;
        for (int i = 1; i <= n; i++) tt[i]=0;
        tt[a]=1;
        T=1;
        dfs3(b);
        ll ans2=n-T;
        cout << ans1*ans2 << "\n";
    }
    return 0;
}