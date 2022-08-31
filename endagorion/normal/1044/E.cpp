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

vvi shifts = {{0, 1, 4, 3}, {3, 4, 1, 0}, {1, 2, 5, 4}, {4, 5, 2, 1}, {0, 1, 2, 5, 4, 3}, {3, 4, 5, 2, 1, 0}};
map<vi, int> prv;
map<vi, vi> prvv;

int n, m;

void precalc() {
    vi init(6);
    iota(all(init), 0);
    set<vi> vis = {init};
    map<vi, int> dist;
    dist[init] = 0;
    vvi q = {init};
    forn(cur, q.size()) {
        auto v = q[cur];
        forn(j, shifts.size()) {
            auto &sh = shifts[j];
            auto u = v;
            forn(i, sh.size()) u[sh[(i + 1) % sh.size()]] = v[sh[i]];
            if (vis.count(u)) continue;
            dist[u] = dist[v] + 1;
            prv[u] = j;
            prvv[u] = v;
            vis.insert(u);
            q.pb(u);
        }
    }
    assert(q.size() == 720);
}

const int maxn = 21;
int a[maxn][maxn];

vvi ops;

void apply_shift(int rx, int ry, int j) {
    vector<pii> sh;
    for (int op: shifts[j]) {
        int x = rx + op / 3, y = ry + op % 3;
        sh.pb(mp(x, y));
    }
    reverse(all(sh));
    vi vals;
    for (auto [x, y]: sh) {
        vals.pb(a[x][y]);
    }
    ops.pb(vals);
    rotate(vals.begin(), vals.begin() + 1, vals.end());
    while (!vals.empty()) {
        auto [x, y] = sh.back();
        a[x][y] = vals.back();
        vals.pop_back();
        sh.pop_back();
    }
}

void perform(int rx, int ry, vi perm) {
/*    cerr << "Before\n";
    forn(i, n) {
        forn(j, m) cerr << a[i][j] << ' ';
        cerr << '\n';
    }
    cerr << rx << ' ' << ry << '\n';
    for (int j: perm) cerr << j << ' ';
    cerr << '\n';*/
    vi shs;
    while (prv.count(perm)) {
        shs.pb(prv[perm]);
        perm = prvv[perm];
    }
    reverse(all(shs));
    for (int j: shs) apply_shift(rx, ry, j);
/*    cerr << "After\n";
    forn(i, n) {
        forn(j, m) cerr << a[i][j] << ' ';
        cerr << '\n';
    }*/
}

bool shift(int rx, int ry, int sx1, int sy1, int sx2, int sy2) {
    if (min(rx, ry) < 0) return false;
    if (min(n - rx - 2, m - ry - 3) < 0) return false;
    if (min(sx1, sx2) < rx) return false;
    if (max(sx1, sx2) >= rx + 2) return false;
    if (min(sy1, sy2) < ry) return false;
    if (max(sy1, sy2) >= ry + 3) return false;
    int i1 = (sx1 - rx) * 3 + (sy1 - ry);
    int i2 = (sx2 - rx) * 3 + (sy2 - ry);
    if (i1 == i2) return true;
    vi perm(6);
    iota(all(perm), 0);
    swap(perm[i1], perm[i2]);
    perform(rx, ry, perm);
    return true;
}

void try_shift(int sx1, int sy1, int sx2, int sy2) {
//    cerr << sx1 << ' ' << sy1 << ' ' << sx2 << ' ' << sy2 << '\n';
    forn(dx, 2) forn(dy, 3) if (shift(sx1 - dx, sy1 - dy, sx1, sy1, sx2, sy2)) return;
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    precalc();

    cin >> n >> m;
    forn(i, n) forn(j, m) cin >> a[i][j], --a[i][j];

    forn(i, n * m) {
        int sx = -1, sy = -1;
        forn(x, n) forn(y, m) if (a[x][y] == i) sx = x, sy = y;
        int tox = i / m, toy = i % m;
        while (sx != tox || sy != toy) {
            int bx = -1, by = -1;
            int D = 1e9;
            fore(dx, -1, 1) fore(dy, -2, 2) {
                int x = sx + dx, y = sy + dy;
                if (min(x, y) < 0 || min(n - x, m - y) <= 0) continue;
                if (x * m + y < i) continue;
                int nd = abs(tox - x) + abs(toy - y);
                if (uin(D, nd)) bx = x, by = y;
            }
            assert(D < 1e8);
            try_shift(sx, sy, bx, by);
            sx = bx, sy = by;
        }
/*        while (sy < toy) try_shift(sx, sy, sx, sy + 1), ++sy;
        while (sy > toy) try_shift(sx, sy, sx, sy - 1), --sy;
        while (sx < tox) try_shift(sx, sy, sx + 1, sy), ++sx;
        while (sx > tox) try_shift(sx, sy, sx - 1, sy), --sx;*/
    }

    forn(i, n * m) assert(a[i / m][i % m] == i);

    cout << ops.size() << '\n';
    int S = 0;
    for (auto &v: ops) {
        S += v.size();
        assert(S <= 100000);
        cout << v.size();
        reverse(all(v));
        for (auto x: v) cout << ' ' << x + 1;
        cout << '\n';
    }
    cerr << S << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}