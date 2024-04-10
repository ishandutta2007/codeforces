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

const i64 P = 998244353;

const int maxn = 4100;
i64 cnk[maxn][maxn];

i64 get_cnk(int n, int k) {
    if (n < 0 || k < 0) return 0;
    return cnk[n][k];
}

i64 fs0(int n, int m, int r) {
    i64 res = get_cnk(r + n, n) * get_cnk(m - r + n - 2, n - 1) % P;
//    cerr << n << ' ' << m << ' ' << r << ' ' << res << '\n';
    return res;
}

i64 f0(int n, int m) {
    i64 res = 0;
    forn(i, n - 1) {
        i64 psum = 0;
        forn(l2, m) { // forn(r1, l2 - 1) {
            if (l2 > 1) (psum += fs0(i + 1, m, l2 - 2)) %= P;
            i64 w = psum * fs0(n - i - 1, m, m - l2 - 1);
            (res += w) %= P;
        }
    }
//    cerr << "f0(" << n << ", " << m << ")=" << res << '\n';
    return res;
}

i64 f1(int n, int m) {
    i64 res = 0;
    forn(i, n - 1) {
        for1(l2, m - 1) {
            int r1 = l2 - 1;
            i64 w = fs0(i + 1, m, r1) * fs0(n - i - 1, m, m - l2 - 1);
            (res += w) %= P;
        }
    }
//    cerr << "f1(" << n << ", " << m << ")=" << res << '\n';
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

    cnk[0][0] = 1;
    forn(i, maxn - 1) forn(j, i + 1) forn(k, 2) (cnk[i + 1][j + k] += cnk[i][j]) %= P;

    int n, m;
    cin >> n >> m;
    i64 ans = f0(n, m) + f0(m, n) + f1(n, m);
    ans *= 2;
    ans %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}