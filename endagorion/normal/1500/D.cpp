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

const int maxn = 1510;
bool isin[maxn * maxn];
int a[maxn][maxn];
vector<pii> cell[2][maxn], clv[maxn];

vector<pii> shift(vector<pii> a, int sh) {
    for (auto &[x, y]: a) x += sh;
    return a;
}

int LIM;

vector<pii> vmerge(const vector<pii> &a, const vector<pii> &b) {
    for (auto [x, y]: a) isin[y] = 0;
    for (auto [x, y]: b) isin[y] = 0;
    size_t pa = 0, pb = 0;
    vector<pii> res;
    while (pa < a.size() || pb < b.size()) {
        if (res.size() > LIM) break;
        pii nxt;
        if (pa < a.size() && (pb == b.size() || a[pa] < b[pb])) nxt = a[pa++];
        else nxt = b[pb++];
        if (!isin[nxt.se]) res.pb(nxt);
        isin[nxt.se] = 1;
    }
    return res;
}

int ans[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n >> LIM;
    forn(i, n) forn(j, n) cin >> a[i][j];
    ford(i, n) {
        vector<pii> clh;
        ford(j, n) {
            vector<pii> tcell = {{0, a[i][j]}};
            clh = vmerge(tcell, shift(clh, 1));
            clv[j] = vmerge(tcell, shift(clv[j], 1));
            auto &res = cell[0][j] = vmerge(shift(cell[1][j + 1], 1), vmerge(clh, clv[j]));

            int ms = (res.size() > LIM ? res.back().fi : (int)1e9);
            uin(ms, min(n - i, n - j));
            ++ans[1]; --ans[ms + 1];
        }

        forn(j, n) cell[1][j] = cell[0][j];
    }

    
/*    fore(d, -(n - 1), n - 1) {
        vector<pii> res;
        ford(i, n) {
            int j = i - d;
            if (j < 0 || j >= n) continue;
            res = vmerge(vmerge(clh[i][j], clv[i][j]), shift(res, 1));
            int ms = (res.size() > LIM ? res.back().fi : (int)1e9);
            uin(ms, min(n - i, n - j));
//            cerr << i << ' ' << j << '\n';
//            for (auto [x, y]: res) cerr << x << ' ' << y << ", ";
//            cerr << '\n';
            ++ans[1]; --ans[ms + 1];
        }
    }*/

    for1(i, n - 1) ans[i + 1] += ans[i];
    for1(i, n) cout << ans[i] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}