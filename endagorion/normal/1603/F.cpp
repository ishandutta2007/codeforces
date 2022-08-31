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
const int maxk = 10'000'000 + 10;
int d2[maxk];

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

i64 solve1(i64 n, i64 k) {
    vi64 dp(k + 1);
    dp[0] = 1;
    forn(i, n) {
        vi64 ndp(k + 1);
        forn(j, i + 1) {
            if (j >= k) break;
            (ndp[j] += dp[j] * d2[j]) %= P;
            (ndp[j + 1] += dp[j] * (d2[k] - d2[j + 1])) %= P;
        }
        dp = ndp;
    }
//    for (auto x: dp) cerr << x << ' ';
//    cerr << '\n';
    i64 ans = accumulate(all(dp), 0LL) % P;
    if (ans < 0) ans += P;
    return ans;
}

void print_mu(i64 k) {
    vi64 inex(k + 1);
    for1(i, k) {
        i64 coef = 1 - inex[i];
        if (coef > P / 2) coef -= P;
        if (coef < -P / 2) coef += P;
        cerr << i << ' ' << coef << '\n';
        fore(j, i + 1, k) {
            i64 C = coef;
            forn(z, j - i) {
                (C *= d2[j] - d2[z + 1]) %= P;
                (C *= deg(d2[j - i] - d2[z], -1)) %= P;
            }
            (inex[j] += C) %= P;
        }
    }
}

i64 solve2(i64 n, i64 k) {
    i64 d2n1 = deg(2, n + 1);
    i64 id2n1 = deg(d2n1, -1);
    i64 C = deg(d2n1, k - 1);
    i64 ans = 0;
    for1(i, k) {
//        cerr << i << ' ' << C << '\n';
        (ans += C) %= P;
        (C *= -id2n1) %= P;
        (C *= d2[k - i] - 1) %= P;
//        C = -C;
    }
    if (ans < 0) ans += P;
    return ans;
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
    forn(i, maxk - 1) d2[i + 1] = d2[i] * 2 % P;

//    print_mu(10);

    int T;
    cin >> T;
    while (T--) {
        i64 n, k, x;
        cin >> n >> k >> x;
        if (x == 0) {
            i64 ans = 1;
            forn(i, n) {
                (ans *= d2[k] - d2[i]) %= P;
                if (!ans) break;
            }
            if (ans < 0) ans += P;
            cout << ans << '\n';
        } else {
//            cout << solve1(n, k) << ' ' << solve2(n, k) << '\n';
            cout << solve2(n, k) << '\n';
        }          
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}