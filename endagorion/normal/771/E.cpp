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

const int maxn = 310000;
int dp[maxn];
map<int, int> minr[2][maxn];
i64 a[2][maxn], ps[3][maxn];
int cr[3][maxn];

int n;

void update(int l, int r, int v) {
//    cerr << l << ' ' << r << ' ' << v << '\n';
    if (max(l, r) > n) return;
    if (l == r) uax(dp[l], v);
    else if (l < r) {
        if (minr[0][l].count(v)) uin(minr[0][l][v], r);
        else minr[0][l][v] = r;
    } else {
        if (minr[1][r].count(v)) uin(minr[1][r][v], l);
        else minr[1][r][v] = l;
    }
}

void update2(int z, int l, int r, int v) {
    if (max(l, r) > n) return;
    int p;
    if (z == 0) p = cr[0][l];
    else if (z == 1) p = cr[1][r];
    else p = cr[2][max(l, r)];
    if (p < 1e8) update(z == 1 ? l : p, z == 0 ? r : p, v + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;
    forn(z, 2) forn(i, n) cin >> a[z][i];

    forn(i, n) {
        forn(z, 2) ps[z][i + 1] = ps[z][i] + a[z][i];
        ps[2][i + 1] = ps[0][i + 1] + ps[1][i + 1];
    }

    forn(z, 3) {
        map<i64, int> last;
        ford(i, n + 1) {
            i64 s = ps[z][i];
            if (!last.count(s)) cr[z][i] = 1e9;
            else cr[z][i] = last[s];
            last[s] = i;
        }
    }

    forn(i, n) {
//        cerr << i << ' ' << dp[i] << '\n';
        update(i, i + 1, dp[i]);
        update(i + 1, i, dp[i]);
        update(i + 1, i + 1, dp[i]);
        forn(z, 3) update2(z, i, i, dp[i]);
        if (minr[0][i].count(dp[i] + 1)) {
            int l = minr[0][i][dp[i] + 1];
//            cerr << "L " << i << ' ' << l << '\n';
            forn(z, 3) update2(z, i, l, dp[i] + 1);
            update(i + 1, l, dp[i] + 1);
        }
        if (minr[1][i].count(dp[i] + 1)) {
            int r = minr[1][i][dp[i] + 1];
//            cerr << "R " << i << ' ' << r << '\n';
            forn(z, 3) update2(z, r, i, dp[i] + 1);
            update(r, i + 1, dp[i] + 1);
        }
    }
    cout << dp[n] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}