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
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, d, T, Q, a[200001], c2[200001], iss[200001];pll c[200001];
vector<ll> ans[200001], vv[200001];
string s;
vector<pll> v[200001];
vector<ll> h[200001];
vector<pll> g;

ll binpow(ll h, ll r, ll md = MOD)
{
    bool t = 0;
    if (h < 0) t = 1, h = -h;
    if (r % 2 == 0) t = 0;
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
    if (t) l = -l;
    //cout << l << "\n";
    return l;
}

ll gcd(int x, int y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

ll gt(ll x, ll y)
{
    x %= MOD;
    y %= MOD;
    return (x * y) % MOD;
}

struct sparse_table
{
    pll d[200001][20];

    void build(int n)
    {
        for (int i = n; i > 0; i--)
        {
            d[i][0] = mp(a[i], a[i]);
            for (int j = 1; i + (1 << j) - 1 <= n; j++)
            {
                d[i][j] = mp(min(d[i][j-1].fi, d[i+(1<<(j-1))][j-1].fi), max(d[i][j - 1].se, d[i + (1 << (j - 1))][j - 1].se));
            }
        }
    }

    ll getmin(int l, int r)
    {
        return min(d[l][iss[r-l+1]].fi, d[r-(1<<iss[r-l+1])+1][iss[r-l+1]].fi);
    }

    ll getmax(int l, int r)
    {
        return max(d[l][iss[r - l + 1]].se, d[r - (1 << iss[r - l + 1]) + 1][iss[r - l + 1]].se);
    }
};

sparse_table pp;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   // freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    ll nw = 0, j = -1;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        if (i / 2 == nw) nw = i, j++;
        iss[i] = j;
    }
    vector<pll> ss;
    for (int i = 1; i <= n; i++) { cin >> a[i];ss.pb(mp(a[i], i)); }
    sort(all(ss));
    ll k = 0;
    for (int i = 0;i < ss.size(); i++)
    {
        if (i == 0 || ss[i].fi != ss[i - 1].fi) k++;
        a[ss[i].se] = k;
    }
    for (int i = 1; i <= n; i++)
    {
        //g.pb(mp(a[i], i));
        c[i] = mp(1e9, 1e9);
        c2[i] = 1e9;
        vv[a[i]].pb(i);
    }
    for (int j = 1; j <= q; j++)
    {
        ll x, y;
        cin >> x >> y;
        v[x].pb(mp(y, j));
    }
    //sort(all(g));
    vector<ll> z;
    pp.build(n);
    //cout << i << " : " << lr << " " << rr << "\n";
   // for (int i = 1; i <= n; i++) cout << i << " " << c[i].fi << "\n";
    
    for (int i = 2; i < n; i++)
    {
        ll l = 1, r = i - 1, lr = 0, rr = 0;
        while (l < r)
        {
            int w = (l + r + 1) / 2;
            if (pp.getmin(w, i) >= a[i]) r = w - 1; else l = w;
        }
        if (pp.getmin(l,i)>=a[i]) continue;
        lr = l;
        l = i + 1, r = n;
        while (l < r)
        {
            int w = (l + r) / 2;
            if (pp.getmin(i, w) >= a[i]) l = w + 1; else r = w;
        }
        if (pp.getmin(i, l) >= a[i]) continue;
        rr = l;
        //cout << i << " : " << lr << " " << rr << "\n";
        if (c[lr].first > rr) c[lr] = mp(rr, i);
    }

    for (int i = 2; i < n; i++)
    {
        ll l = 1, r = i - 1, lr = 0, rr = 0;
        while (l < r)
        {
            int w = (l + r + 1) / 2;
            if (pp.getmax(w, i) <= a[i]) r = w - 1; else l = w;
        }
        if (pp.getmax(l, i) <= a[i]) continue;
        lr = l;
        l = i + 1, r = n;
        while (l < r)
        {
            int w = (l + r) / 2;
            if (pp.getmax(i, w) <= a[i]) l = w + 1; else r = w;
        }
        if (pp.getmax(i, l) <= a[i]) continue;
        rr = l;
        //cout << i << " : " << lr << " " << rr << "\n";
        if (c[lr].first > rr) c[lr] = mp(rr, i);
    }
    ll mn = 1e9, mx = 0;

    for (int i = 1; i <= n; i++)
    {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        if (a[i] == mn || a[i] == mx) continue;
        ll l = 1, r = i;
        while (l < r)
        {
            int w = (l + r + 1) / 2;
            ll p1 = pp.getmin(w, i), p2 = pp.getmax(w, i);
            if (p1 == a[i] || p2 == a[i]) r = w - 1; else l = w;
        }
        h[l - 1].pb(i);
    }
    set<int> s;
    //cout << "------\n";
    mn = 1e9, mx = 0;
    for (int i = n; i > 0; i--)
    {
        mn = min(mn, a[i]);
        mx = min(mx, a[i]);
        for (int j = 0; j < h[i].size(); j++)
        {
            s.insert(h[i][j]);
        }
        if (mn == a[i] || mx == a[i]) continue;
        ll l = i, r = n;
        while (l < r)
        {
            int w = (l + r) / 2;
            ll p1 = pp.getmin(i, w), p2 = pp.getmax(i, w);
            if (p1 == a[i] || p2 == a[i]) l = w + 1; else r = w;
        }
        if (s.size() == 0) continue;
        auto u = s.end();
        u--;
        if (*u <= l) continue;
        ll y = *s.upper_bound(l);
        c2[i] = y;
    }
    //cout << "-----\n";
    //cout << pp.getmax(1,1,n,1,4) << "\n";
    pll mn1 = mp(1e9,1e9);
    ll op = 0;
    pll mn2 = mp(1e9,1e9);
    for (int i = n; i > 0; i--)
    {
        if (mn1.se > c[i].fi) mn1 = mp(i,c[i].fi), op=c[i].se;
        if (mn2.se > c2[i]) mn2 = mp(i, c2[i]);
        
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j].fi>=mn2.se)
            {
                ll o = v[i][j].second;
                ans[o].pb(mn2.fi);

                ll p1 = pp.getmin(mn2.first,mn2.se), p2 = pp.getmax(mn2.first, mn2.se);               
                ll ps1 = upper_bound(all(vv[p1]), mn2.fi) - vv[p1].begin();
                ll ps2 = upper_bound(all(vv[p2]), mn2.fi) - vv[p2].begin();
                ps1 = vv[p1][ps1];
                ps2 = vv[p2][ps2];
                if (ps1 > ps2) swap(ps1, ps2);
                ans[o].pb(ps1);
                ans[o].pb(ps2);
                ans[o].pb(mn2.se);
            } else 
            if (v[i][j].first >= mn1.se)
            {
                ll o = v[i][j].second;
                ans[o].pb(mn1.fi);
                ans[o].pb(op);                
                ans[o].pb(mn1.se);
            }
        }
    }

    for (int i = 1; i <= q; i++)
    {
        cout << ans[i].size() << "\n";
        for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
/*

10
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb
abcdedcb

*/