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

const int maxn = 21;
const int P = 31607;
int a[maxn][maxn];
int used[maxn][maxn];
int pc[maxn];
int inv[P];

int deg(int x, int d) {
    if (d < 0) d += P - 1;
    int y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

int n;

int rec(int i) {
    int res;
    int mul = 1;
    if (i < n) {
        res = rec(i + 1);
        forn(j, n) {
            if (!used[i][j]) (pc[j] *= inv[a[i][j]]) %= P, (mul *= a[i][j]) %= P;
            ++used[i][j];
        }
        res -= mul * rec(i + 1);
        res %= P;
        if (res < 0) res += P;
        forn(j, n) {
            --used[i][j];
            if (!used[i][j]) (pc[j] *= a[i][j]) %= P;
        }
    } else if (i == n) {
        res = rec(i + 1);
        forn(j, n) {
            if (!used[j][j]) (pc[j] *= inv[a[j][j]]) %= P, (mul *= a[j][j]) %= P;
            ++used[j][j];
        }
        res -= mul * rec(i + 1);
        res %= P;
        if (res < 0) res += P;
        forn(j, n) {
            --used[j][j];
            if (!used[j][j]) (pc[j] *= a[j][j]) %= P;
        }
    } else if (i == n + 1) {
        res = rec(i + 1);
        forn(j, n) {
            if (!used[n - j - 1][j]) (pc[j] *= inv[a[n - j - 1][j]]) %= P, (mul *= a[n - j - 1][j]) %= P;
            ++used[n - j - 1][j];
        }
        res -= mul * rec(i + 1);
        res %= P;
        if (res < 0) res += P;
        forn(j, n) {
            --used[n - j - 1][j];
            if (!used[n - j - 1][j]) (pc[j] *= a[n - j - 1][j]) %= P;
        }
    } else {
        res = 1;
        forn(j, n) (res *= 1 - pc[j]) %= P;
        if (res < 0) res += P;
    }
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

    for1(i, P - 1) inv[i] = deg(i, -1);
    cin >> n;
    forn(i, n) forn(j, n) {
        cin >> a[i][j];
        (a[i][j] *= inv[10000]) %= P;
    }
    
    forn(j, n) {
        pc[j] = 1;
        forn(i, n) (pc[j] *= a[i][j]) %= P;
    }
    int ans = 1 - rec(0);
    ans %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}