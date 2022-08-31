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

    TPoint operator-(const TPoint &p) const {
        return {x - p.x, y - p.y};
    }

    i64 operator%(const TPoint &p) const {
        return x * p.y - y * p.x;
    }

    void read() {
        cin >> x >> y;
    }
};

const int maxn = 301;
i64 dp[maxn][maxn][6];

ostream &operator<<(ostream &out, const TPoint &p) {
    return out << p.x << ' ' << p.y;
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
    vector<TPoint> p(n);
    forn(i, n) p[i].read();
    sort(all(p), [&](TPoint a, TPoint b){return mp(a.x, a.y) < mp(b.x, b.y);});
    i64 ans = 0;
    forn(i, n) {
        vector<TPoint> q(i + all(p));
        TPoint O = p[i];
        sort(1 + all(q), [&](TPoint a, TPoint b){return (a - O) % (b - O) > 0;});

        int S = q.size();
        forn(j, S + 1) forn(k, S + 1) forn(l, 6) dp[j][k][l] = 0;
        for1(j, S - 1) {
            dp[j][0][2] = 1;
            vi under, over;
            forn(k, S) {
                if (k < j) under.pb(k);
                if (k > j) over.pb(k);
            }
            auto comp = [&](int x, int y) {
                return (q[x] - q[j]) % (q[y] - q[j]) > 0;
            };
            sort(all(under), comp);
            sort(all(over), comp);
            vi64 sum(6);
            int up = 0, op = 0;
            while (op < (int)over.size()) {
                bool gou = up < (int)under.size() && !comp(under[up], over[op]);
                if (gou) {
                    forn(l, 6) sum[l] += dp[j][under[up]][l];
                    ++up;
                } else {
                    forn(l, 5) dp[over[op]][j][l + 1] += sum[l];
                    ++op;
                }
            }
        }
        forn(j, S + 1) forn(k, S + 1) forn(l, 6) {
            auto V = dp[j][k][l];
            if (!V) continue;
//            cerr << p[i] << ' ' << q[j] << ' ' << q[k] << ' ' << l << ' ' << V << '\n';
        }
        forn(j, S + 1) forn(k, S + 1) ans += dp[j][k][5];
    }

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}