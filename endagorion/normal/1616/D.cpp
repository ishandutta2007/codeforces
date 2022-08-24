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

struct TQ {
    vi L, R, Lm, Rm;
    int minx;

    TQ()
        : L()
        , R()
        , Lm({(int)1e9})
        , Rm({(int)1e9})
        , minx((int)1e9)
    {
    }

    void push(int x) {
        L.pb(x);
        Lm.pb(min(Lm.back(), x));
        uin(minx, x);
    }

    void pop() {
        if (R.empty()) {
            while (!L.empty()) {
                int x = L.back();
                L.pop_back();
                Lm.pop_back();
                R.pb(x);
                Rm.pb(min(Rm.back(), x));
            }
        }
        R.pop_back();
        Rm.pop_back();
        minx = min(Lm.back(), Rm.back());
    }
};

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
        int n;
        cin >> n;
        vi a(n);
        forn(i, n) cin >> a[i];
        int x;
        cin >> x;
        forn(i, n) a[i] -= x;
        vi64 p(n + 1);
        forn(i, n) p[i + 1] = p[i] + a[i];
        vi dp(n + 1);

        TQ q;
        q.push(0);
        int L = 0;
        for1(i, n) {
            int nL = L;
            if (i >= 2 && p[i] < p[i - 2]) uax(nL, max(1, i - 2));
            if (i >= 3 && p[i] < p[i - 3]) uax(nL, max(1, i - 3));
            while (L < nL) {
                q.pop();
                ++L;
            }
            dp[i] = q.minx;
//            cerr << i << ' ' << L << ' ' << dp[i] << '\n';
            q.push(dp[i] + 1);
        }
        cout << n - dp[n] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}