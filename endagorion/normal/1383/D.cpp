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
    vvi a(n, vi(m));
    vi rmax(n), cmax(m);
    forn(i, n) forn(j, m) {
        cin >> a[i][j];
        uax(rmax[i], a[i][j]);
        uax(cmax[j], a[i][j]);
    }
    sort(all(rmax));
    sort(all(cmax));
    vvi ans(n, vi(m));
    vector<pii> ruord, lbord;
    int rp = 0, cp = 0;
    vi used(n * m + 1);
    while (rp < n || cp < m) {
        int x = 1e9;
        if (rp < n) uin(x, rmax[rp]);
        if (cp < m) uin(x, cmax[cp]);
        used[x] = 1;
        ans[rp][cp] = x;
        if (cmax[cp] == x) {
            for (int i = n - 1; i > rp; --i) lbord.pb(mp(i, cp));
        }
        if (rmax[rp] == x) {
            for (int j = m - 1; j > cp; --j) ruord.pb(mp(rp, j));
        }
        if (rmax[rp] == x) ++rp;
        if (cmax[cp] == x) ++cp;
    }

    rp = n - 1;
    cp = m - 1;
    int lbptr = 0, ruptr = 0;
    reverse(all(lbord));
    reverse(all(ruord));
/*    for (auto [x, y]: lbord) cerr << x << ' ' << y << ", ";
    cerr << '\n';
    for (auto [x, y]: ruord) cerr << x << ' ' << y << ", ";
    cerr << '\n';*/
    for (int i = n * m; i >= 1; --i) {
        if (used[i]) continue;
        if (lbptr < lbord.size() && i < cmax[lbord[lbptr].se]) {
            pii p = lbord[lbptr++];
            ans[p.fi][p.se] = i;
        } else if (ruptr < ruord.size() && i < rmax[ruord[ruptr].fi]) {
            pii p = ruord[ruptr++];
            ans[p.fi][p.se] = i;
        } else assert(false);
    }

    forn(i, n) {
        forn(j, m) cout << ans[i][j] << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}