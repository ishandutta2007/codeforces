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

const int maxn = 110000;
int a[maxn], p[maxn];
pi64 ps[maxn];

pi64 operator-(const pi64 &a, const pi64 &b) {
    return {a.fi - b.fi, a.se - b.se};
}

i64 operator%(const pi64 &a, const pi64 &b) {
    return a.fi * b.se - a.se * b.fi;
}

struct TQuery {
    int i, j;
    int L, R;
    i64 A;
    int id;
};

i64 ans[maxn];

vector<pi64> dnc(int L, int R, vector<TQuery> qs) {
    vector<TQuery> full, part;
    for (auto q: qs) {
        if (max(L, q.L) >= min(R, q.R)) continue;
        (q.L <= L && R <= q.R ? full : part).pb(q);
    }
    if (R - L == 1) {
        auto p = ps[L];
        for (auto q: full) {
            auto v = p.fi * q.A + p.se;
//            cerr << L << ' ' << R << ' ' << q.id << ' ' << p.fi << ' ' << p.se << ' ' << v << '\n';
            uax(ans[q.id], v);
        }
        return {p};
    }
    int M = (L + R) / 2;
    auto v1 = dnc(L, M, part), v2 = dnc(M, R, part);
    vector<pi64> v(v1.size() + v2.size());
    merge(all(v1), all(v2), v.begin());
    vector<pi64> st;
    for (auto p: v) {
        while (st.size() > 1) {
            auto prv = st.end()[-1], pprv = st.end()[-2];
            if ((prv - pprv) % (p - pprv) >= 0) st.pop_back();
            else break;
        }
        st.pb(p);
    }

/*    if (!full.empty()) {
        cerr << L << ' ' << R << ": ";
        for (auto [x, y]: st) cerr << x << ' ' << y << ", ";
        cerr << '\n';
    }*/

    int ptr = 0;
    for (auto q: full) {
        while (ptr + 1 < (int)st.size()) {
            auto p = st[ptr], np = st[ptr + 1];
            if (p.fi * q.A + p.se <= np.fi * q.A + np.se) ++ptr;
            else break;
        }
        auto p = st[ptr];
        auto v = p.fi * q.A + p.se;
        uax(ans[q.id], v);
//        cerr << L << ' ' << R << ' ' << q.id << ' ' << p.fi << ' ' << p.se << ' ' << v << '\n';
    }
    return st;
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
    forn(i, n) cin >> a[i];
    forn(i, n) p[i + 1] = p[i] + a[i];

    forn(i, n) {
        ps[i] = {a[i], p[i + 1] - i * a[i]};
//        cerr << i << ' ' << ps[i].fi << ' ' << ps[i].se << '\n';
    }

    int m;
    cin >> m;
    vector<TQuery> qs(m);
    forn(i, m) {
        auto &q = qs[i];
        q.id = i;
        cin >> q.i >> q.j;
        --q.j;
        q.R = q.j + 1;
        q.L = q.R - q.i;
        q.A = q.j - q.i;
//;        cerr << i << ' ' << q.i << ' ' << q.j << ' ' << q.L << ' ' << q.R << ' ' << q.A << '\n';

        ans[i] = -1e18;
    }
    sort(all(qs), [&](auto a, auto b){return a.A < b.A;});
    dnc(0, n, qs);
    for (auto q: qs) ans[q.id] = p[q.j + 1] - ans[q.id];
    forn(i, m) cout << ans[i] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}