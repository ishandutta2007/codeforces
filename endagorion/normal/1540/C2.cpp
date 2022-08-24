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

const i64 P = 1000000000 + 7;

i64 eval(const vi &a, const vi &b) {
    i64 ls = 1e9;
    i64 sb = 0, psa = 0;
    forn(i, a.size()) {
        i64 ai = a[i] - sb;
        psa += ai;
        i64 x = psa / (i + 1);
        if (x * (i + 1) > psa) --x;
//        cerr << ai << ' ' << i + 1 << ' ' << psa << ' ' << x << '\n';;
        uin(ls, x);
        if (i < b.size()) sb += b[i];
    }
//    cerr << '\n';
    return ls;
}

i64 ars_at_least(i64 x, const vi &c, const vi &b) {
    vi64 dp = {1};
//    vi64 pdp = {0, 1};
    i64 sb = 0, shpa = 0;
    
    forn(i, c.size()) {
        vi64 ndp(dp.size() + c[i]);
        vi64 pdp(dp.size() + 1);
        forn(j, dp.size()) (pdp[j + 1] = pdp[j] + dp[j]) %= P;
        i64 lbas = (i + 1) * x;
        forn(j, ndp.size()) {
            if (j < lbas + shpa) continue;
            i64 L = max(0, j - c[i]);
            i64 R = min((i64)dp.size() - 1, (i64)j);
            if (L <= R) ndp[j] = (pdp[R + 1] - pdp[L]) % P;
        }
        if (i < b.size()) {
            sb += b[i];
            shpa += sb;
        }
        dp = ndp;
    }

    i64 ans = 0;
    forn(i, dp.size()) (ans += dp[i]) %= P;
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

    int n;
    cin >> n;
    vi c(n), b(n - 1);
    forn(i, n) cin >> c[i];
    forn(i, n - 1) cin >> b[i];

    i64 L = eval(vi(n, 0), b), R = eval(c, b);
    cerr << L << ' ' << R << '\n';

    vi64 ans(R - L + 2);
    forn(i, ans.size()) ans[i] = ars_at_least(L + i, c, b);

    int Q;
    cin >> Q;
    while (Q--) {
        i64 x;
        cin >> x;
        uin(x, R + 1);
        uax(x, L);
        cout << ans[x - L] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}