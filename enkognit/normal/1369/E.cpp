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

const ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, mx, T, a[100001], b[100001];
vector<pll> c[100001];
bool tt[100001];

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

#define dies_from_cringe exit(0)

auto cmp(pii x,pii y)
{
    return x.fi>y.fi || (x.fi==y.fi && x.se<y.se);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(mp(y,i));
        c[y].pb(mp(x,i));
    }
    set<pii> s;
    for (int i = 1; i <= n; i++) b[i]=-(a[i]-c[i].size()), s.insert(mp(b[i], i));
    vector<ll> v;
    while (s.size())
    {
        pii z=(*s.begin());
        //cout << z.fi << " " << z.se << "\n";
        if (z.fi>0) {cout << "DEAD\n";dies_from_cringe;}
        s.erase(s.begin());
        ll x=z.se;
        tt[x]=1;
        for (int j = 0; j < c[x].size(); j++)
            if (!tt[c[x][j].fi])
            {
                s.erase(mp(b[c[x][j].fi], c[x][j].fi));
                b[c[x][j].fi]--;
                v.pb(c[x][j].se);
                s.insert(mp(b[c[x][j].fi], c[x][j].fi));
            }
    }
    reverse(all(v));
    cout << "ALIVE\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
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