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

    i64 operator%(const TPoint &p) const {
        return x * p.y - y * p.x;
    }
};

ostream &operator<<(ostream &out, const TPoint &p) {
    return out << p.x << ' ' << p.y;
}

const int maxn = 210, maxk = 51;
TPoint p[maxn];
i64 dp[maxk][maxn][maxn];
int under[maxn][maxn];

bool is_under(int i, int j, int k) {
    if (k < i) return false;
    if (p[i].x == p[j].x) return k == i;
    if (p[k].x < p[i].x || p[k].x >= p[j].x) return false;
    return (p[k] - p[i]) % (p[j] - p[i]) >= 0;
}

bool is_empty_tr(int i, int j, int k) {
    if (i > j) swap(i, j);
    if (j > k) swap(j, k);
    if (i > j) swap(i, j);
    if (i == j || j == k) return true;
    int ins = under[i][j] + under[j][k] + under[k][i];
    if (!is_under(i, k, j)) --ins;
    return ins == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(2);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, k;
    cin >> n >> k;
    forn(i, n) cin >> p[i].x >> p[i].y;
    sort(p, p + n, [](TPoint a, TPoint b){return mp(a.x, -a.y) < mp(b.x, -b.y);});

    forn(j, n) forn(i, j) {
        under[i][j] = 0;
        forn(k, n) if (is_under(i, j, k)) ++under[i][j];
        under[j][i] = -under[i][j];
    }

/*    forn(i, n) forn(j, n) cerr << p[i] << ' ' << p[j] << ' ' << under[i][j] << '\n';

    forn(i, n) forn(j, i) forn(k, j) {
        if (is_empty_tr(i, j, k)) cerr << p[i] << ' ' << p[j] << ' ' << p[k] << '\n';
    }*/

    i64 ans = 0;

    forn(l, n) {
        vi ord;
        fore(i, l + 1, n - 1) ord.pb(i);
        sort(all(ord), [&](int i, int j){return (p[i] - p[l]) % (p[j] - p[l]) > 0;});
        
        forn(c, k + 1) forn(i, n) forn(j, n) dp[c][i][j] = -1e18;
        forn(cur, ord.size()) {
            int i = ord[cur];
            vi prv = {l}, pos;
            forn(c2, ord.size()) {
                if (c2 < cur) prv.pb(ord[c2]);
                if (c2 > cur) pos.pb(ord[c2]);
            }
            auto comp = [&](int x, int y) {
                return (p[x] - p[i]) % (p[y] - p[i]) > 0;
            };
            sort(all(prv), comp);
            sort(all(pos), comp);
/*            cerr << p[l] << ' ' << p[i] << '\n';
            for (int j: prv) cerr << p[j] << ' ';
            cerr << '\n';
            for (int j: pos) cerr << p[j] << ' ';
            cerr << '\n';*/
            vi64 mx(k + 1, -1e18);
            dp[2][i][l] = 0;
            size_t pprv = 0, ppos = 0;
            while (ppos < pos.size()) {
                bool go_prv = pprv < prv.size() && (ppos == pos.size() || (p[prv[pprv]] - p[i]) % (p[pos[ppos]] - p[i]) < 0);
                if (go_prv) {
                    int j = prv[pprv++];
//                    cerr << "prv " << p[l] << ' ' << p[i] << ' ' << p[j] << '\n';
                    forn(c, k + 1) {
                        if (dp[c][i][j] >= 0 && uax(mx[c], dp[c][i][j])) {
//                            cerr << p[l] << ' ' << p[j] << ' ' << p[i] << ' ' << c << ' ' << mx[c] << '\n';
                        }
                    }
                } else {
                    int j = pos[ppos++];
//                    cerr << "pos " << p[l] << ' ' << p[i] << ' ' << p[j] << '\n';
                    if (!is_empty_tr(i, j, l)) {
//                        cerr << "non empty\n";
                        continue;
                    }
                    forn(c, k) {
                        if (mx[c] >= 0 && uax(dp[c + 1][j][i], mx[c] + (p[i] - p[l]) % (p[j] - p[l]))) {
//                            cerr << p[l] << ' ' << p[i] << ' ' << p[j] << ' ' << c + 1 << ' ' << dp[c + 1][j][i] << '\n';
                            if (c + 1 == k) uax(ans, dp[k][j][i]);
                        }
                    }
                }
            }
        }
    }
    cout << 0.5 * ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}