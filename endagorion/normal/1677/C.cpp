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
        vvi a(2, vi(n));
        forn(z, 2) for (int &x: a[z]) cin >> x, --x;

        vi p(n);
        forn(i, n) p[a[0][i]] = a[1][i];

        vi clen;
        vi vis(n);
        forn(i, n) {
            if (vis[i]) continue;
            int L = 0;
            for (int j = i; !vis[j]; j = p[j], ++L) vis[j] = 1;
            clen.pb(L);
        }

        i64 ans = 0;
        sort(rall(clen));
        i64 R = n - 1;
        for (int l: clen) {
            l -= l & 1;
            for1(i, l / 2) {
                ans += 2 * R;
                R -= 2;
            }
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}