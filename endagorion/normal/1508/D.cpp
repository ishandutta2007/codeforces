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

struct TPoint {
    i64 x, y;
    int id;

    TPoint operator-(const TPoint &p) const {
        return {x - p.x, y - p.y, -1};
    }

    i64 operator%(const TPoint &p) const {
        return x * p.y - y * p.x;
    }
};

const int maxn = 2100;
int perm[maxn];

bool on_cycle(int v, int u) {
    if (v == u) return true;
    for (int w = perm[v]; w != v; w = perm[w]) if (w == u) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    vector<TPoint> ps;
    forn(i, n) {
        TPoint p;
        cin >> p.x >> p.y >> perm[i];
        --perm[i];
        p.id = i;
        if (perm[i] != i) ps.pb(p);
    }

    if (ps.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    sort(all(ps), [&](TPoint a, TPoint b){return mp(a.x, a.y) < mp(b.x, b.y);});
    sort(1 + all(ps), [&](TPoint a, TPoint b){return (b - ps[0]) % (a - ps[0]) > 0;});

    vector<pii> ops;
    for1(i, ps.size() - 2) if (!on_cycle(ps[i].id, ps[i + 1].id)) {
        ops.pb({ps[i].id, ps[i + 1].id});
        swap(perm[ps[i].id], perm[ps[i + 1].id]);
    }
    forn(i, ps.size()) assert(on_cycle(ps[i].id, ps[0].id));
    while (perm[ps[0].id] != ps[0].id) {
        int v = perm[ps[0].id];
        ops.pb({ps[0].id, v});
        swap(perm[ps[0].id], perm[v]);
        assert(perm[v] == v);
    }
    forn(i, n) assert(perm[i] == i);
    cout << ops.size() << '\n';
    for (auto [x, y]: ops) cout << x + 1 << ' ' << y + 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}