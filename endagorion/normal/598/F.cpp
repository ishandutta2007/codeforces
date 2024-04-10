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

    TPoint operator+(const TPoint &p) const {
        return {x + p.x, y + p.y};
    }

    TPoint operator-(const TPoint &p) const {
        return {x - p.x, y - p.y};
    }

    i64 operator*(const TPoint &p) const {
        return x * p.x + y * p.y;
    }

    i64 operator%(const TPoint &p) const {
        return x * p.y - y * p.x;
    }

    ld operator~() const {
        return hypot(x, y);
    }

    void read() {
        ld xf, yf;
        cin >> xf >> yf;
        x = 100 * xf;
        y = 100 * yf;
    }
};

int sgn(i64 x) {
    if (x) return x > 0 ? 1 : -1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    vector<TPoint> ps(n);
    for (auto &p: ps) p.read();
    forn(i, m) {
        TPoint A, B;
        A.read();
        B.read();
        vector<pair<ld, int> > evs;
        forn(i, n) {
            if ((B - A) % (ps[i] - A) == 0) {
                for (int d: {-1, 1}) {
                    int j = (i + d + n) % n;
                    TPoint v = ps[j] - ps[i];
                    evs.pb({ps[i] * (B - A), sgn(v % (B - A))});
                }
            }
            int j = (i + 1) % n;
            i64 vi = (ps[i] - A) % (B - A), vj = (ps[j] - A) % (B - A);
            if (sgn(vi) * sgn(vj) == -1) {
                i64 si = ps[i] * (B - A), sj = ps[j] * (B - A);
                ld x = si + 1.0 * (sj - si) * vi / (vi - vj);
                for (int z: {-1, 1}) evs.pb({x, z});
            }
        }
        sort(all(evs));
        ld ans = 0.0;
        int mask = 0;
        forn(i, evs.size()) {
            if (mask) ans += evs[i].fi - evs[i - 1].fi;
            mask ^= 1 << evs[i].se;
        }
        cout << 1e-2 * ans / ~(B - A) << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}