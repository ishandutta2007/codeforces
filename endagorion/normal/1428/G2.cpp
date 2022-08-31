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

const i64 maxa = 1000000;
const i64 INF = 1e18;
i64 dp[2][maxa];

struct TMaxQueue {
    vi64 L, R, Lm, Rm;

    TMaxQueue()
        : L()
        , R()
        , Lm(1, -INF)
        , Rm(1, -INF)
    {
    }

    void push(i64 x) {
        Lm.pb(max(Lm.back(), x));
        L.pb(x);
    }

    i64 getMax() const {
        return max(Lm.back(), Rm.back());
    }

    void pop() {
        if (R.empty()) {
            while (!L.empty()) {
                i64 x = L.back();
                L.pop_back();
                Lm.pop_back();
                Rm.pb(max(Rm.back(), x));
                R.pb(x);
            }
        }
        R.pop_back();
        Rm.pop_back();
    }

    int size() const {
        return L.size() + R.size();
    }
};

void qupdate(i64 step, i64 shift, i64 cap, i64 c) {
//    cerr << step << ' ' << shift << ' ' << cap << ' ' << c << '\n';
    forn(z, step) {
        TMaxQueue q;
        for (i64 i = z + shift; i < maxa; i += step) {
            q.push(dp[0][i - shift] - c * (i / step));
            if (q.size() > cap) q.pop();
            uax(dp[1][i], q.getMax() + c * (i / step));
        }
    }
//    cerr << "done\n";
}

void supdate(i64 shift, i64 c) {
    if (shift > maxa) return;
//    cerr << shift << ' ' << c << '\n';
    forn(i, maxa - shift) uax(dp[1][i + shift], dp[0][i] + c);
//    cerr << "done\n";
}

i64 f[6];
i64 d10[] = {1, 10, 100, 1000, 10000, 100000};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 k;
    cin >> k;
    forn(i, 6) cin >> f[i];
    forn(i, maxa) dp[0][i] = -INF;
    dp[0][0] = 0;
    forn(p, 6) {
        forn(i, maxa) dp[1][i] = -INF;    
        qupdate(3 * d10[p], 0, 3 * k + 1, f[p]);
        for1(z, 2) qupdate(3 * d10[p], z * d10[p], 3 * (k - 1) + 1, f[p]);
        fore(z, 4, 9) {
            if (z % 3 == 0) continue;
            supdate((9 * (k - 1) + z) * d10[p], 3 * (k - 1) * f[p]);
        }
        forn(i, maxa) dp[0][i] = dp[1][i];
    }

    int q;
    cin >> q;
    while (q--) {
        int sum;
        cin >> sum;
        cout << dp[0][sum] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}