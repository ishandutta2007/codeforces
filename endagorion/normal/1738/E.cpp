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

const int maxn = 110000;
const i64 P = 998244353;
i64 d2[maxn];
i64 fact[maxn], tcaf[maxn], inv[maxn];

i64 cnk(int n, int k) {
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

    d2[0] = 1;
    for1(i, maxn - 1) d2[i] = 2 * d2[i - 1] % P;

    inv[1] = 1;
    fore(i, 2, maxn - 1) inv[i] = P - P / i * inv[P % i] % P;
    fact[0] = tcaf[0] = 1;
    for1(i, maxn - 1) {
        fact[i] = i * fact[i - 1] % P;
        tcaf[i] = inv[i] * tcaf[i - 1] % P;
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi64 ps(n + 1);
        forn(i, n) {
            i64 x;
            cin >> x;
            ps[i + 1] = ps[i] + x;
        }
        map<i64, i64> cnt;
        for1(i, n - 1) ++cnt[ps[i]];

        i64 ans = 1;
        i64 S = ps[n];
        for (auto [s, cl]: cnt) {
            if (2 * s > S) break;
            i64 w;
            if (2 * s == S) {
                w = d2[cl];
            } else {
                w = 0;
                i64 cr = (cnt.count(S - s) ? cnt[S - s] : 0LL);
                forn(c, min(cl, cr) + 1) {
                    (w += cnk(cl, c) * cnk(cr, c)) %= P;
                }
//                cerr << s << ' ' << cl << ' ' << cr << ' ' << w << '\n';
            }
            (ans *= w) %= P;
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}