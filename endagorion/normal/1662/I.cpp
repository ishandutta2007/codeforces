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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    vi64 cnt(n);
    forn(i, n) cin >> cnt[i];
    vi64 x(m);
    forn(i, m) cin >> x[i];
    x.pb(-5e9);
    x.pb(5e9);
    sort(all(x));
    m += 2;
    int ptr = 0;
    i64 ans = 0;
    forn(i, m - 1) {
        while (ptr < n && 100 * ptr == x[i]) ++ptr;
        vector<pi64> evs;
        while (ptr < n && 100 * ptr < x[i + 1]) {
            i64 L = max(x[i], 200 * ptr - x[i + 1]);
            i64 R = min(x[i + 1], 200 * ptr - x[i]);
            if (L < R) {
                evs.pb({L, cnt[ptr]});
                evs.pb({R, -cnt[ptr]});
            }
            ++ptr;
        }
        sort(all(evs));
        i64 b = 0;
        int L = 0;
        while (L < evs.size()) {
            i64 X = evs[L].fi;
            while (L < evs.size() && evs[L].fi == X) b += evs[L++].se;
            uax(ans, b);
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}