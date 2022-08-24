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

    int n, k;
    cin >> n >> k;
    vi tr(k - 1);
    iota(all(tr), 0);
    vi a(n, -1);
    fore(i, k - 1, n - 1) {
        tr.pb(i);
        cout << "?";
        for (int x: tr) cout << ' ' << x + 1;
        cout << endl;
        int p;
        cin >> p;
        --p;
        cin >> a[p];
        tr.erase(find(all(tr), p));
    }
    int i = 0;
    while (a[i] < 0) ++i;
    int j = i + 1;
    while (a[j] < 0) ++j;
    if (a[i] > a[j]) swap(i, j);
    
    tr.pb(i);
    tr.pb(j);
    int ans = 1;
    forn(x, k - 1) {
        cout << "?";
        forn(y, k + 1) if (x != y) cout << ' ' << tr[y] + 1;
        cout << endl;
        int p, z;
        cin >> p >> z;
        if (p == j + 1) ++ans;
    }
    cout << "! " << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}