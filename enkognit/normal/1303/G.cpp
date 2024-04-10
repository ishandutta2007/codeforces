#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-avx2")
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

const ll MOD = 1e9 + 7;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, a[150001], ans;
vector<ll> c[150001];
bool tt[1000001];
ll sz[150001];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
        r /= 2;
    }
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

void dfs(int h, int p = -1)
{
    sz[h] = 1;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i] != p && !tt[c[h][i]])
        {
            dfs(c[h][i], h);
            sz[h] += sz[c[h][i]];
        }
}

ll get_centroid(int h, int kl, int p = -1)
{
    //cout << h << "\n";
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i] != p && kl < sz[c[h][i]]*2 && !tt[c[h][i]]) return get_centroid(c[h][i], kl, h);
    return h;
}

void dfs2(int h, int p,ll sum,ll pr1,ll pr2,int len,vector<pair<pll,pll> > &v)
{
    ll q = 0;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]] && c[h][i] != p)
        {
            q++;
            ll k = a[c[h][i]];
            dfs2(c[h][i], h, sum + k, pr1 + sum + k, pr2 + (len + 1) * k, len + 1, v);
        }
    if (q == 0)
    {
        //cout << h << " " << pr1 << " " << pr2 << " " << sum << " " << len << "\n";
        v.pb(mp(mp(pr1, pr2), mp(sum, len)));
        //ans = max(ans, pr1);
        //ans = max(ans, pr2);
    }
}

ll yy(ll x,pll q)
{
    return q.first * x + q.second;
}

struct Li_Chao_tree
{
private:
    struct node
    {
        node *l, *r;
        pll x;
        node() :x(mp(0,0)),l(nullptr),r(nullptr) {};
    };

public:
    node* root;
    Li_Chao_tree() :root(new node()) {};

    node* make()
    {
        return new node();
    }

    void build(node* h, int l, int r)
    {
        h->x = mp(0,0);
        if (r - l == 1) return;
        int w = (l + r) / 2;
        if (h->l==nullptr) h->l = new node();
        if (h->r==nullptr) h->r = new node();
        build(h->l, l, w);
        build(h->r, w, r);
    }

    void update(node* h, int l, int r, pll x)
    {
        if (r - l == 1) return;
        int w = (l + r) / 2;
        bool tt = (yy(l, x) > yy(l, h->x));
        bool t = (yy(w, x) > yy(w, h->x));
        if (t) swap(x,h->x), tt = !tt;
        if (r - l == 1) return;
        if (tt) update(h->l, l, w, x); else update(h->r, w, r, x);
    }

    ll get(node* h, int l, int r, int x)
    {
        if (r - l == 1) return yy(x, h->x);
        int w = (l + r) / 2;
        if (x <= w) return max(get(h->l, l, w, x), yy(x, h->x)); else
            return max(get(h->r, w, r, x), yy(x, h->x));
    }
};

Li_Chao_tree g;

void rec(int h)
{
    dfs(h);
    ll nn = sz[h];

    h = get_centroid(h, sz[h]);
    //cout << "------\n";
    //cout << h << "\n";
    vector<vector<pair<pll,pll> > > v;
    vector<pair<pll,pll> > vv;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]])
        {
            v.pb(vv);
            dfs2(c[h][i], h, a[c[h][i]], a[c[h][i]], a[c[h][i]], 1, v.back());
        }
    g.build(g.root,0,nn);
    //cout << v.size() << "-\n";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            //cout << v[i][j].first.first << " " << v[i][j].first.se << " " << v[i][j].second.first << " " << v[i][j].second.second << "\n";
            ans = max(ans, g.get(g.root, 0, nn, v[i][j].se.se) + v[i][j].fi.fi);
            ans = max(ans, v[i][j].fi.fi+(v[i][j].se.se+1)*a[h]);
            ans = max(ans, v[i][j].fi.se+v[i][j].se.fi+a[h]);
        }

        for (int j = 0; j < v[i].size(); j++)
        {
            g.update(g.root, 0, nn, mp(v[i][j].se.fi + a[h], v[i][j].fi.se+a[h]+v[i][j].se.fi));
        }
    }
    g.build(g.root,0,nn);
    for (int i = v.size()-1; i > -1; i--)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            //cout << v[i][j].first.first << " " << v[i][j].first.se << " " << v[i][j].second.first << " " << v[i][j].second.second << "\n";
            ans = max(ans, g.get(g.root, 0, nn, v[i][j].se.se) + v[i][j].fi.fi);
            //ans = max(ans, v[i][j].fi.fi+(v[i][j].se.se+1)*a[h]);
            //ans = max(ans, v[i][j].fi.se+v[i][j].fi.fi+a[h]);
        }

        for (int j = 0; j < v[i].size(); j++)
        {
            g.update(g.root, 0, nn, mp(v[i][j].se.fi + a[h], v[i][j].fi.se+a[h]+v[i][j].se.fi));
        }
    }
    tt[h] = 1;
    for (int i = 0; i < c[h].size(); i++)
        if (!tt[c[h][i]]) rec(c[h][i]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    g.root = g.make();
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    rec(1);
    cout << ans << "\n";
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