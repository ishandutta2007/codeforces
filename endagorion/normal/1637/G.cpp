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

const int maxn = 1 << 17;
int cnt[maxn];
vector<pii> ops;

void op(int x, int y) {
//    cerr << x << ' ' << y << '\n';
    assert(cnt[x]);
    --cnt[x];
    assert(cnt[y]);
    --cnt[y];
    ++cnt[x + y];
    ++cnt[abs(x - y)];
    ops.pb({x, y});
}

void pref(int l, int step) {
    assert(l >= 0);
    if (l <= 1) return;
    int k = 1;
    while (2 * k <= l) k *= 2;
//    cerr << "P " << l << ' ' << k << ' ' << step << '\n';
    for1(i, l - k) op((k - i) * step, (k + i) * step);
    pref(l - k, 2 * step);
    pref(l - 2 * (l - k) - 1, step);
}

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << '\n';
        return;
    }
    ops.clear();
//    cerr << n << '\n';
    int ans = 1;
    while (ans < n) ans *= 2;
    forn(i, ans + 1) cnt[i] = 0;
    for1(i, n) cnt[i] = 1;
    pref(n, 1);
    if (!cnt[0]) {
        for1(i, ans - 1) {
            if (cnt[i] > 1) {
                op(i, i);
                break;
            }
        }
    }
    assert(cnt[0]);

    for1(i, ans - 1) {
        while (cnt[i]) {
            op(i, 0);
            op(i, i);
        }
    }
    assert(cnt[ans]);
    while (cnt[0]) op(ans, 0);
    assert(cnt[ans] == n);
    assert(ops.size() <= 20 * n);
    cout << ops.size() << '\n';
    for (auto [x, y]: ops) cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

/*    int n, A;
    cin >> n >> A;
    vi a(n);
    iota(all(a), 1);
    set<vi> vis = {a};
    vvi q = {a};
    int ans = 1e9;
    forn(cur, q.size()) {
        vi v = q[cur];
        if (v == vi(n, v[0])) {
            cerr << ans << '\n';
            for (int x: v) cerr << x << ' ';
            cerr << '\n';
            uin(ans, v[0]);
//            cout << ans << '\n';
        }
        forn(i, n) forn(j, i) {
            int x = v[i], y = v[j];
            vi u = v;
            u[i] = x + y;
            u[j] = abs(x - y);
            sort(all(u));
            if (u.back() > A || vis.count(u)) continue;
            vis.insert(u);
            q.pb(u);
        }
    }
    assert(q.size() == vis.size());
    cout << ans << '\n';*/

    int T;
    cin >> T;
    while (T--) solve();

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}