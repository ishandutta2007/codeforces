#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "popcnt")

#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 1000;
typedef bitset<2 * maxn> bs;

int n;
bs reach[2 * maxn];

vi find_dissimilar(const vector<pii> &a, const vector<pii> &b) {
    forn(i, 2 * n) reach[i].reset();
    forn(i, 2 * n) reach[i][i] = 1;
    vi no(2 * n);
    forn(i, 2 * n) no[i] = (i + n) % (2 * n);
    for (auto [x, y]: a) {
        x = (x > 0 ? x - 1 : -x - 1 + n);
        y = (y > 0 ? y - 1 : -y - 1 + n);
        reach[no[x]][y] = 1;
        reach[no[y]][x] = 1;
    }
    forn(k, 2 * n) forn(i, 2 * n) if (reach[i][k]) reach[i] |= reach[k];
    forn(i, 2 * n) if (reach[i][no[i]] && reach[no[i]][i]) return {};
    
    for (auto [x, y]: b) {
        x = (x > 0 ? x - 1 : -x - 1 + n);
        y = (y > 0 ? y - 1 : -y - 1 + n);
        auto b = reach[no[x]] | reach[no[y]];
        if ((b & (b >> n)).any()) continue;
        vi pc(2 * n);
        forn(i, 2 * n) pc[i] = reach[i].count();
/*        forn(i, 2 * n) {
            forn(j, 2 * n) cerr << reach[i][j];
            cerr << '\n';
        }*/
        vi ord(2 * n);
        iota(all(ord), 0);
        sort(all(ord), [&](int v, int u){return pc[v] < pc[u];});
        for (int v: ord) {
            if (reach[v][no[v]]) continue;
            if (b[v] || b[no[v]]) continue;
            b |= reach[v];
        }
//        forn(i, 2 * n) cerr << b[i];
//        cerr << '\n';
        vi ans(n);
        forn(i, n) {
            assert(b[i] ^ b[no[i]]);
            ans[i] = b[i];
        }
        return ans;
    }
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int m1, m2;
    cin >> n >> m1 >> m2;
    vector<pii> a(m1), b(m2);
    forn(i, m1 + m2) {
        auto &p = (i < m1 ? a[i] : b[i - m1]);
        cin >> p.fi >> p.se;
    }

    vi ans = find_dissimilar(a, b);
    if (ans.empty()) ans = find_dissimilar(b, a);
    if (ans.empty()) cout << "SIMILAR\n";
    else {
        for (int x: ans) cout << x << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}