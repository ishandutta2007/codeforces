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
//    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vvi a(k);
        forn(i, k) {
            int c;
            cin >> c;
            a[i].resize(c);
            forn(j, c) cin >> a[i][j];
        }
        cout << "? " << n << ' ' ;
        for1(i, n) cout << i << ' ';
        cout << endl;
        int mx;
        cin >> mx;
        int L = 0, R = n;
        while (R - L > 1) {
            int M = (L + R) / 2;
            cout << "? " << M << ' ';
            for1(i, M) cout << i << ' ';
            cout << endl;
            int res;
            cin >> res;
            (res == mx ? R : L) = M;
        }
        vi ans(k, mx);
        forn(i, k) {
            if (!count(all(a[i]), R)) continue;
            vi toQ(n, 1);
            for (int x: a[i]) toQ[x - 1] = 0;
            cout << "? " << n - a[i].size() << ' ';
            forn(i, n) if (toQ[i]) cout << i + 1 << ' ';
            cout << endl;
            cin >> ans[i];
        }
        cout << "! ";
        forn(i, k) cout << ans[i] << ' ';
        cout << endl;
        string trash;
        cin >> trash;
        assert(trash == "Correct");
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}