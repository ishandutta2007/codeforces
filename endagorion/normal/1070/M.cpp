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
    int x, y;
    int w, id;

    TPoint operator-(const TPoint &p) const {
        return {x - p.x, y - p.y, -1, -1};
    }

    TPoint operator-() const {
        return {-x, -y, -1, -1};
    }

    int operator%(const TPoint &p) const {
        return x * p.y - y * p.x;
    }

    bool half() const {
        if (!y) return x > 0;
        return y > 0;
    }

    bool cmp(const TPoint &p) const {
        if (half() != p.half()) return half();
        return *this % p > 0;
    }
};

void solve(vector<TPoint> a) {
    int n = a.size();
    int bi = 0, ci = 0, c1 = 0;
    int sw = 0;
    forn(i, a.size()) {
        sw += a[i].w;
        if (a[i].w > 0) ++c1;
        if (a[i].w < a[bi].w) bi = i; 
        if (a[i].w > a[ci].w) ci = i;
    }
    assert(sw == 1);
    if (c1 + 1 == (int)a.size()) {
        forn(i, a.size()) if (a[i].w == 1) cout << a[bi].id << ' ' << a[i].id << '\n';
//        cout << '\n';
        return;
    }
    if (c1 == 1) {
        forn(i, a.size()) if (a[i].w == 0) cout << a[i].id << ' ' << a[ci].id << '\n';
//        cout << '\n';
        return;
    }
    TPoint b0 = a[bi];
    swap(a[bi], a.back());
    a.pop_back();
    sort(all(a), [&](TPoint a, TPoint b){return (a - b0).cmp(b - b0);});
    int wins = 0;
//    cerr << "---\n";
//    cerr << b0.x << ' ' << b0.y << ' ' << b0.w << ' ' << b0.id << ":\n";
//    for (auto p: a) cerr << p.x << ' ' << p.y << ' ' << p.w << ' ' << p.id << '\n';
    forn(i, a.size() - 1) assert((a[i] - b0).cmp(a[i + 1] - b0));
    int L = 0, R = 0;
    while (R < a.size() && (a[R] - b0).half()) wins += a[R++].w;
    while (1) {
//        cerr << L << ' ' << R << ' ' << wins << '\n';
        if (wins >= 1 && wins <= -b0.w) {
            vector<TPoint> lh, rh;
            forn(i, a.size()) {
                if (i >= L && i < R) lh.pb(a[i]);
                else rh.pb(a[i]);
            }
            TPoint lhb = b0, rhb = b0;
            lhb.w = 1 - wins;
            rhb.w = b0.w + wins;
            lh.pb(lhb);
            solve(lh);
            rh.pb(rhb);
            solve(rh);
            return;
        }
        if (L < R && (R == a.size() || (a[L] - b0) % (a[R] - b0) < 0)) wins -= a[L++].w;
        else {
            assert(R < a.size());
            wins += a[R++].w;
        }
    }
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

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<TPoint> a(n + m);
        forn(i, n + m) {
            a[i].w = 1;
            a[i].id = (i < n ? i + 1 : i - n + 1);
        }
        forn(i, m) {
            int x;
            cin >> x;
            a[n + i].w -= x;
        }
        forn(i, n + m) cin >> a[i].x >> a[i].y;
        cout << "YES\n";
        solve(a);
    }
    
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}