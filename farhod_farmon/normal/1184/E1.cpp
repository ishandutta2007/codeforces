#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double dbl;
#define pb push_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define all(a) a.begin(),a.end()
bool debug = 0;
const int MAXN = 1e6 + 100;
const int LOG = 25;
const int mod = 1e9 + 7;
const int MX = 1e6 + 100;
typedef long long li;
const li MOD = 1000000000949747713ll;

int parent[MAXN];

void build(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
}

int find_parent(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_parent(parent[v]);
}

mt19937 mt(228);

void union_set(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) {
        if (mt() & 1)
            swap(a, b);
        parent[b] = a;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    int a1 = 0, b1 = 0;
    vector<pair<int, pii> > cc;
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (i == 1) {
            a1 = a;
            b1 = b;
        } else {
            cc.pb({c, {a, b}});
        }
    }
    int l = 0, r = 1e9;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;

        build(n);

        for (auto x:cc) {
            if (x.fi < mid) {
                union_set(x.se.fi, x.se.se);
            }
        }

        if (find_parent(a1) == find_parent(b1)) {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }
    assert(ans!=-1);
    cout << ans;
}

signed main() {
#ifdef zxc
    debug = 1;
    freopen("../input.txt", "r", stdin);
    //freopen("../output.txt", "w", stdout);
#else
    //freopen("roboherd.in", "r", stdin);
    //freopen("roboherd.out", "w", stdout);

#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    int t = 1;
    while (t--)
        solve();
    if (debug)
        cerr << endl << "time : " << (1.0 * clock() / CLOCKS_PER_SEC) << endl;
}