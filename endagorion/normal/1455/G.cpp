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

struct TOp {
    int type, x;
    i64 v;

    void read() {
        string s;
        cin >> s;
        if (s == "set") {
            type = 1;
            cin >> x >> v;
        } else if (s == "if") {
            type = 2;
            cin >> x;
        } else type = 3;
    }
};

const int maxn = 210000;
TOp ops[maxn];

int n, s;

struct TLazyMap {
    map<int, i64> m;
    multiset<i64> vs;
    i64 lazy;

    TLazyMap()
        : m()
        , vs()
        , lazy(0)
    {
    }

    void set(int x, i64 v) {
        if (m.count(x)) vs.erase(vs.find(m[x]));
        m[x] = v;
        vs.insert(v);
    }

    void erase(int x) {
        if (!m.count(x)) return;
        vs.erase(vs.find(m[x]));
        m.erase(x);
    }

    i64 get(int x) {
        if (!m.count(x)) return 1e18;
        return m[x] + lazy;
    }

    void swap(TLazyMap &r) {
        m.swap(r.m);
        vs.swap(r.vs);
        ::swap(lazy, r.lazy);
    }
};

void mmerge(TLazyMap &a, TLazyMap &b) {
    if (a.m.size() < b.m.size()) a.swap(b);
    for (auto [x, y]: b.m) {
        i64 efv = y + b.lazy - a.lazy;
        if (a.m.count(x) && a.m[x] <= efv) continue;
        a.set(x, efv);
    }
}

int opi;

TLazyMap parse(int init, i64 x) {
    TLazyMap res;
    res.set(init, x);
    while (1) {
        auto op = ops[opi++];
//        cerr << opi << ' ' << op.type << ' ' << op.x << ' ' << op.v << '\n';
        if (op.type == 3) return res;
        if (op.type == 1) {
            res.lazy += op.v;
            if (op.x != s) res.set(op.x, *res.vs.begin() - op.v);
        }
        if (op.type == 2) {
            auto nm = parse(op.x, res.get(op.x));
            res.erase(op.x);
            mmerge(res, nm);
        }
//        for (auto [x, y]: res.m) cerr << x << ' ' << y + res.lazy << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> s;
    forn(i, n) ops[i].read();
    ops[n++].type = 3;

    auto m = parse(0, 0);
    i64 ans = 1e18;
    for (auto [x, y]: m.m) uin(ans, y + m.lazy);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}