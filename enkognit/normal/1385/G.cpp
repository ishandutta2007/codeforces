#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, T, k, kl[200001], a[2][200001];
ll ans=0;
vector<ll> w;
vector<pll> q;
vector<pii> c[2][200001], v[200001];
bool tt[2][200001], nm[2][200001], tl[200001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

ll dfs(int x,int h,bool k)
{
    q.pb(mp(x,h));
    tt[x][h]=1;
    tl[h]=1;
    nm[x][h]=k;
    ll kl=0;
    //cout << x << " " << h << " " << nm[x][h] << "\n";
    if (x && k) kl++, w.pb(h);
    for (int i = 0; i < c[x][h].size(); i++)
        if (tt[c[x][h][i].fi][c[x][h][i].se])
        {
            //cout << x << " " << h << " " << c[x][h][i].fi << " " << c[x][h][i].se << "\n";
            if (nm[x][h]==nm[c[x][h][i].fi][c[x][h][i].se]) kl=1e18;
        }else
        {
            ll o=dfs(c[x][h][i].fi, c[x][h][i].se, !k);
            kl=min(kl+o, (ll)1e18);
        }
    return kl;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        tl[i]=0;
        v[i].clear();
        for (int j = 0; j < 2; j++) c[j][i].clear();
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[0][i];
        v[a[0][i]].pb(mp(0, i));
        c[0][i].pb(mp(1, i));
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[1][i];
        v[a[1][i]].pb(mp(1, i));
        c[1][i].pb(mp(0,i));
    }
    for (int i = 1; i <= n; i++)
        if (v[i].size()!=2) {cout << "-1\n";return;}
    for (int i = 1; i <= n; i++)
    {
        c[v[i][0].fi][v[i][0].se].pb(mp(v[i][1].fi, v[i][1].se));
        c[v[i][1].fi][v[i][1].se].pb(mp(v[i][0].fi, v[i][0].se));
    }
    vector<ll> ans;
    for (int i = 1; i <= n; i++)
        if (!tl[i])
        {
            q.clear();
            w.clear();
            vector<ll> w1, w2;
            ll p0=dfs(0,i,1);
            //cout << p0 << "\n";
            w1=w;
            for (int i = 0; i < q.size(); i++) tt[q[i].fi][q[i].se]=0, nm[q[i].fi][q[i].se]=0;
            q.clear();
            w.clear();
            ll p1=dfs(1,i,1);
            w2=w;
            for (int i = 0; i < q.size(); i++) tt[q[i].fi][q[i].se]=0, nm[q[i].fi][q[i].se]=0;
            ll p=min(p0, p1);
            if (p>=1e18) {cout << "-1\n";return;}
            /*cout << i << " " << p0 << " " << p1 << "\n ";
            for (int i = 0; i < w1.size(); i++) cout << w1[i] << " ";
            cout << "\n ";
            for (int i = 0; i < w2.size(); i++) cout << w2[i] << " ";
            cout << "\n";*/
            if (p0<p1) for (auto i : w1) ans.pb(i); else for(auto i : w2) ans.pb(i);
        }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

/*
3
4 2
1 1
1 0
3 2
2 2

3 1
1 1
1 0
3 2

3 2
1 1
1 0
3 2
*/