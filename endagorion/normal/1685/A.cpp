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

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        map<int, int> cnt;
        forn(i, n) {
            cin >> a[i];
            ++cnt[a[i]];
        }
        bool ok = n % 2 == 0;
        sort(all(a));
        for (auto [x, y]: cnt) {
            if (2 * y > n) ok = false;
            if (x != a[0] && x != a.back() && 2 * y >= n) ok = false;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int p0 = 0, p1 = n - n / 2;
        vi b;
//        cout << a[0] ' ' << a[n / 2] << ' ';
        forn(i, n) {
            if (i & 1) b.pb(a[p1++]);
            else b.pb(a[p0++]);
//            cout << ' ';
        }
//        cout << '\n';
        forn(i, n) {
            int j = (i - 1 + n) % n, k = (i + 1) % n;
            assert(b[i] > max(b[j], b[k]) || b[i] < min(b[j], b[k]));
        }

        for (int x: b) cout << x << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}