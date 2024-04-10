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
    vi init(n);
    forn(i, n) cin >> init[i];
    vi a = init;
//    set<pii> invs;
//    forn(i, n) forn(j, i) if (a[j] > a[i]) invs.insert({j, i});
    vi ord(n);
    iota(all(ord), 0);
    stable_sort(all(ord), [&](int i, int j){return init[i] < init[j];});

    vector<pii> ans;
    for (int p: ord) {
        int x = a[p];
        fore(q, p + 1, n - 1) if (a[p] == a[q] && init[p] > init[q]) ans.pb({p, q});
        for (int q = n - 1; q > p; --q) {
            if (a[q] < x) {
                ans.pb({p, q});
                swap(a[p], a[q]);
            }
        }
    }

    assert(is_sorted(all(a)));
//    set<pii> sans(all(ans));
//    assert(sans == invs && sans.size() == ans.size());
    cout << ans.size() << '\n';
    for (auto w: ans) cout << w.fi + 1 << ' ' << w.se + 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}