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

    int n;
    cin >> n;
    vector<pii> p(n);
    forn(i, n) cin >> p[i].fi >> p[i].se;

    auto sortby = [&](const auto &f) {
        vi ord(n);
        iota(all(ord), 0);
        sort(all(ord), f);
        return ord;
    };



    vi ordx = sortby([&](int i, int j){return p[i].fi < p[j].fi;});
    vi ordy = sortby([&](int i, int j){return p[i].se < p[j].se;});
    
    i64 ans = 0;
    forn(i, n / 2) {
        ans += p[ordx[n - i - 1]].fi - p[ordx[i]].fi;
        ans += p[ordy[n - i - 1]].se - p[ordy[i]].se;
    }
    if (n % 2 == 0) {
        int quad = 0;
        int mx = p[ordx[n / 2]].fi, my = p[ordy[n / 2]].se;
        forn(i, n) {
            if ((p[i].fi < mx) != (p[i].se < my)) ++quad;
        }

        if (quad && quad < n) ans -= min(
            p[ordx[n / 2]].fi - p[ordx[n / 2 - 1]].fi,
            p[ordy[n / 2]].se - p[ordy[n / 2 - 1]].se
        );
    } else if (ordx[n / 2] == ordy[n / 2]) {
        int quad = 0;
        int mx = p[ordx[n / 2]].fi, my = p[ordy[n / 2]].se;
        forn(i, n) {
            if (i == ordx[n / 2]) continue;
            if ((p[i].fi < mx) != (p[i].se < my)) ++quad;
        }
        if (quad && quad < n - 1) {
            int res = 2e9;
            uin(res, abs(mx - p[ordx[n / 2 - 1]].fi));
            uin(res, abs(mx - p[ordx[n / 2 + 1]].fi));
            uin(res, abs(my - p[ordy[n / 2 - 1]].se));
            uin(res, abs(my - p[ordy[n / 2 + 1]].se));
            ans -= res;
        }
    }

    cout << 2 * ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}