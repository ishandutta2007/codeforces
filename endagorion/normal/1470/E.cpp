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

const int maxn = 31000, maxc = 6, maxq = 310000, LOG = 20;
const i64 LIM = 2e18;
int p[maxn];
i64 ways[maxc][maxn], wl[maxc][maxn], wg[maxc][maxn];
i64 skl[maxc][LOG + 1][maxn], skg[maxc][LOG + 1][maxn];
vi ordl[maxc][maxn], ordr[maxc][maxn];
int ans[maxq];

struct TQuery {
    i64 k;
    int i, id;
};

vector<TQuery> qs;
int ptr;
i64 sc;

int n, c, q;

i64 next_ev() {
    return ptr == qs.size() ? LIM - 1 : qs[ptr].k;
}

void dfs(int v, int k) {
    if (k < 0) return;
//    cerr << v << ' ' << k << '\n';
    if (ptr == (int)qs.size()) return;
    int i = v;
    while (1) {
        ford(j, LOG) {
            if (i + (1 << j) <= n && sc + skl[k][j][i] <= next_ev()) {
                sc += skl[k][j][i];
                i += 1 << j;
            }
        }
        if (i == n) break;
        for (int j: ordl[k][i]) {
            reverse(p + i, p + j);
            dfs(j, k - j + i + 1);
            reverse(p + i, p + j);
        }
        ++i;
    }
    while (next_ev() == sc) {
        ans[qs[ptr].id] = p[qs[ptr].i];
        ++ptr;
    }
    ++sc;
    while (i >= v) {
        ford(j, LOG) {
            if (i - (1 << j) >= v && sc + skg[k][j][i] <= next_ev()) {
                sc += skg[k][j][i];
                i -= 1 << j;
            }
        }
        for (int j: ordr[k][i]) {
            reverse(p + i, p + j);
            dfs(j, k - j + i + 1);
            reverse(p + i, p + j);
        }
        if (i == v) break;
        --i;
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

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> c >> q;
        forn(i, n) cin >> p[i];
        forn(k, c + 1) {
            ways[k][n] = 1;
            ford(i, n) {
                ordl[k][i].clear();
                ordr[k][i].clear();
                forn(j, k + 1) {
                    if (i + j >= n) break;
                    uin(ways[k][i] += ways[k - j][i + j + 1], LIM);
                    if (p[i + j] < p[i]) uin(wl[k][i] += ways[k - j][i + j + 1], LIM), ordl[k][i].pb(i + j + 1);
                    if (p[i + j] > p[i]) uin(wg[k][i] += ways[k - j][i + j + 1], LIM), ordr[k][i].pb(i + j + 1);
                }
                sort(all(ordl[k][i]), [&](int a, int b){return p[a - 1] < p[b - 1];});
                sort(all(ordr[k][i]), [&](int a, int b){return p[a - 1] < p[b - 1];});
            }
        }

        forn(k, c + 1) {
            forn(i, n + 1) skl[k][0][i] = wl[k][i];
            forn(j, LOG) forn(i, n + 1) {
                skl[k][j + 1][i] = skl[k][j][i];
                if (i + (1 << j) <= n) uin(skl[k][j + 1][i] += skl[k][j][i + (1 << j)], LIM);
            }
        }
        forn(k, c + 1) {
            forn(i, n + 1) skg[k][0][i] = wg[k][i];
            forn(j, LOG) forn(i, n + 1) {
                skg[k][j + 1][i] = skg[k][j][i];
                if ((1 << j) <= i) uin(skg[k][j + 1][i] += skg[k][j][i - (1 << j)], LIM);
            }
        }

        forn(i, q) ans[i] = -1;
        qs.resize(q);
        forn(i, q) {
            qs[i].id = i;
            cin >> qs[i].i >> qs[i].k;
            --qs[i].k; --qs[i].i;
        }
        sort(all(qs), [&](TQuery q1, TQuery q2){return q1.k < q2.k;});

        ptr = 0;
        sc = 0;
        dfs(0, c);

        forn(i, q) cout << ans[i] << '\n';

        forn(k, c + 1) {
            forn(i, n + 1) ways[k][i] = wl[k][i] = wg[k][i] = 0;
            forn(j, LOG + 1) forn(i, n + 1) skl[k][j][i] = skg[k][j][i] = 0;
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}