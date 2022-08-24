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

bool cover(i64 n, i64 m, i64 x) {
    int c = 0;
    forn(i, 4) {
        i64 s = (i % 2 ? m : n) - c;
        if (s % x > 1) return false;
        c = 1 - s % x;
    }
    return c == 0;
}

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
        i64 n, m;
        cin >> n >> m;
        i64 p = 2 * (n + m - 2);
        set<i64> ans;
        vi64 cands;

        for (i64 x = 1; x * x <= p; ++x) if (p % x == 0) cands.pb(x), cands.pb(p / x);
        for (i64 x: cands) {
            if (x <= 2) {
                ans.insert(x);
                continue;
            }
            bool ok = cover(n, m, x);
            ok |= cover(m, n, x);
            if (ok) ans.insert(x);
        }
        cout << ans.size();
        for (int x: ans) cout << ' ' << x;
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}