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

    int n, k;
    cin >> n >> k;
    map<pii, vector<double> > s;
    forn(i, n) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) continue;
        int g = __gcd(abs(x), abs(y));
        s[{x / g, y / g}].pb(hypot(x, y));
    }
    for (auto &w: s) sort(rall(w.se));
    ld sum = 0.0;
    vector<double> opts = {0.0};
    for (auto &w: s) {
        auto &v = w.se;
        int mul = k - 1;
        ld psum = 0.0, psum2 = 0.0;
        ld prevsum2 = 0.0;
        int psz = 0;
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            if (mul > 0) opts.pb(v[l++] * mul), mul -= 2;
            else {
                if (psz == 0) psum = v[r], psum2 = mul * v[r];
                else psum2 += mul * v[r] - 2 * psum, psum += v[r];
                --r, ++psz;
                opts.pb(psum2 - prevsum2);
                prevsum2 = psum2;
            }
        }
    }
    assert(opts.size() == n);

    sort(rall(opts));
    double sum1 = 0.0;
    forn(i, k) sum1 += opts[i];

    cout << sum1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}