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

const int maxn = 1 << 20;
int a[maxn];

int h, g;

vector<pii> solve(int v) {
    if (v >= (1 << h)) return {};
    auto w1 = solve(2 * v), w2 = solve(2 * v + 1);
    int L = 0, R = 0;
    vector<pii> res;
    while (L < w1.size() || R < w2.size()) {
        bool goL = R == w2.size() || (L < w1.size() && w1[L].fi > w2[R].fi);
        int x = a[v];
        if (goL) {
            bool canEx = w1[L].se == 2 * v && (R < w2.size() || w1[L].fi > a[2 * v + 1]);
            if (canEx) a[v] = w1[L].fi, w1[L].se = v;
            res.pb({x, w1[L].se});
            ++L;
        } else {
            bool canEx = w2[R].se == 2 * v + 1 && (L < w1.size() || w2[R].fi > a[2 * v]);
            if (canEx) a[v] = w2[R].fi, w2[R].se = v;
            res.pb({x, w2[R].se});
            ++R;
        }
    }
    if (v >= (1 << g)) res.pb({a[v], v}), a[v] = 0;
//    cerr << v << ' ' << res.size() << '\n';
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        cin >> h >> g;
        int n = (1 << h) - 1;
        for1(i, n) cin >> a[i];
        auto w = solve(1);
        i64 sum = 0;
        for1(i, (1 << g) - 1) sum += a[i];
        cout << sum << '\n';
        for (auto p: w) cout << p.se << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}