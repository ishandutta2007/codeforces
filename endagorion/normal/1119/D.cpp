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
    vi64 a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));
    vi64 d(n);
    forn(i, n - 1) d[i] = a[i + 1] - a[i];
    d[n - 1] = 2e18;
    sort(all(d));

    int q;
    cin >> q;
    vector<pi64> qs(q);
    forn(i, q) {
        i64 l, r;
        cin >> l >> r;
        qs[i] = {r - l + 1, i};
    }
    sort(all(qs));

    vi64 ans(q);
    i64 A = 0, B = n;
    int i = 0, j = 0;
    while (j < q) {
        if (d[i] <= qs[j].fi) {
            A += d[i++];
            --B;
        } else {
            ans[qs[j].se] = A + B * qs[j].fi;
            ++j;
        }
    }

    forn(i, q) cout << ans[i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}