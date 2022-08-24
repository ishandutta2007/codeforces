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

    i64 n, d, m;
    cin >> n >> d >> m;
    vi64 lrg, sm;
    forn(i, n) {
        i64 x;
        cin >> x;
        (x > m ? lrg : sm).pb(x);
    }
    sort(rall(lrg));
    sort(rall(sm));
    vi64 psm(sm.size() + 1);
    partial_sum(all(sm), psm.begin() + 1);
    for (auto x: psm) cerr << x << ' ';
    cerr << '\n';
    i64 ans = 0;
    if (lrg.empty()) ans = accumulate(all(sm), 0LL);
    else {
        i64 res = 0;
        for1(k, lrg.size()) {
            res += lrg[k - 1];
            if (1 + (k - 1) * (d + 1) > n) break;
//            if (lrg.size() - k > (k - 1) * d) continue;
            i64 waste = min(n - k, k * d);
            if (lrg.size() - k > waste) continue;
            i64 uWaste = max((i64)lrg.size() - k, (k - 1) * d);
//            cerr << k << ' ' << waste << ' ' << uWaste << '\n';
            assert(n - k - uWaste <= sm.size());
            uax(ans, res + psm[n - k - uWaste]);
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}