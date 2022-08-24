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
    vector<pii> a(n);
    for (auto &[x, y]: a) cin >> x >> y;

    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j){return a[i].se < a[j].se;});

    vi ans;
    int L = -1, R = n + 1;
    while (R - L > 1) {
        int M = (L + R) / 2;

        vi used(n);
        vi ub(n, n);
        vector<set<int> > byub(n + 1);
        forn(i, n) byub[n].insert(i);

        vi perm;
        forn(i, n) {
            int k = i;
            int place = -1;
            for (int j = i; j <= n; ++j) {
                k += byub[j].size();
//                cerr << M << ' ' << i << ' ' << j << ' ' << k << '\n';
                if (k >= j + 1) {
//                    cerr << "TRIGGER " << M << ' ' << i << ' ' << j << '\n';
                    fore(jj, i, j) for (int x: byub[jj]) {
                        if (place == -1 || a[x].se < a[place].se) place = x;
                    }
                    assert(place != -1);
                    break;
                }
            }
            if (place == -1) forn(j, n) {
                if (used[j]) continue;
                if (place == -1 || a[j].se < a[place].se) place = j;
            }
            perm.pb(place);
            used[place] = 1;
            byub[ub[place]].erase(place);
            forn(j, n) {
                if (used[j]) continue;
                if (max(a[j].fi, a[place].fi) > min(a[j].se, a[place].se)) continue;
                int newub = min(ub[j], i + M);
                if (newub < ub[j]) {
                    byub[ub[j]].erase(j);
                    ub[j] = newub;
                    byub[ub[j]].insert(j);
                }
            }
        }

        int md = 0;
        forn(i, n) forn(j, i) {
            int x = perm[i], y = perm[j];
            if (max(a[x].fi, a[y].fi) <= min(a[x].se, a[y].se)) uax(md, i - j);
        }

        (md <= M ? R : L) = M;
        if (md <= M) ans = perm;
    }

//    cout << R << '\n';
    for (int x: ans) cout << x + 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}