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
    vi a(m);
    forn(i, m) cin >> a[i];

    if (m - 1 + a[m - 1] > n || accumulate(all(a), 0LL) < n) {
        cout << -1 << '\n';
        return 0;
    }

    int L = 0, R = m;
    while (R - L > 1) {
        int M = (L + R) / 2;
        i64 sum = a[m - 1];
        forn(i, m - 1) sum += (i < M ? 1 : a[i]);
        (sum >= n ? L : R) = M;
    }

    vi p(m);
    forn(i, R) p[i] = i;
    p[m - 1] = n - a[m - 1];
    for (int i = m - 1; i > R; --i) p[i - 1] = p[i] - a[i - 1];
    bool ok = true;
    forn(i, m) ok &= p[i] + a[i] <= n;
    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }
    forn(i, m) cout << p[i] + 1 << ' ';
    cout << '\n';
    
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}