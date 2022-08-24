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

const int maxn = 1100000;
const i64 P = 998244353;

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

i64 fact[maxn + 1], tcaf[maxn + 1];

i64 cnk(i64 n, i64 k) {
    if (k == 0 || k == n) return 1;
    if (k < 0 || k > n) return 0;
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    fact[0] = 1;
    for1(i, maxn) fact[i] = i * fact[i - 1] % P;
    tcaf[maxn] = deg(fact[maxn], -1);
    ford(i, maxn) tcaf[i] = (i + 1) * tcaf[i + 1] % P;

    string s;
    cin >> s;
    int n = s.size();

    int opl = 0, clr = 0, ql = 0, qr = 0;
    for (char c: s) {
        if (c == ')') ++clr;
        if (c == '?') ++qr;
    }

    i64 ans = 0;
    forn(i, n + 1) {
        (ans += cnk(ql + qr - 1, opl + ql - clr - 1) * qr) %= P;
        (ans += cnk(ql + qr, opl + ql - clr) * clr) %= P;

        if (i == n) break;
        if (s[i] == '(') ++opl;
        else if (s[i] == ')') --clr;
        else ++ql, --qr;
    }

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}