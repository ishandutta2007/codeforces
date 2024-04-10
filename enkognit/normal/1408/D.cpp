#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const ld E = 1e-7;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, a[1000001];
ll pr[4000001];

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
    if (x==0 || y==0) return x+y;
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

void solve()
{
    cin >> n >> m;
    vector<pll> vv, gg, v, g;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vv.pb(mp(x, y));
    }
    //cout << "-\n";
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        gg.pb(mp(x, y));
    }
    sort(all(vv));
    sort(all(gg));
    for (int i = 0; i < vv.size(); i++)
    {
        //if (v.size()==0 || v[i].se>vv[i].se)
            v.pb(vv[i]);
    }
    for (int i = 0; i < gg.size(); i++)
    {
        while (g.size()>0 && g.back().se<=gg[i].se)
            g.pop_back();
        g.pb(gg[i]);
        //cout << g.size() << "\n";
    }
    //cout << gg.size() << "\n";
    vector<pii > vr;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < g.size(); j++)
        {
            vr.pb(mp(g[j].fi+1-v[i].fi, g[j].se-v[i].se+1));
        }
    }
    pr[vr.size()]=0;
    //for (int i = 0; i < g.size(); i++) cout << g[i].fi << " " << g[i].se << "\n";
    sort(all(vr));
    //cout << "----\n";
    //for (int i = 0; i < vr.size(); i++) cout << vr[i].fi << " " << vr[i].se << "\n";
    //cout << "--\n";
    for (int i = vr.size()-1; i > -1; i--)
        pr[i]=max(pr[i+1], (ll)vr[i].se);
    ll ans=max(pr[0],0ll);
    //cout << "---\n";
    for (int i = 0; i < vr.size(); i++)
    {
        //cout << vr[i].fi << " " << pr[i+1] << "\n";
       // cout << "- ";for (auto y : s) cout << y << " ";
        //cout << "\n";
        if (vr[i].fi>=0)
        {
            ans=min(ans, (ll)vr[i].fi+max(pr[i+1],0ll));
        }
    }
    cout << ans << "\n";
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
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
*/