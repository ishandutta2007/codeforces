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
        int pv = -1, q = 0;
        vi a;
        forn(i, n) {
            int x;
            cin >> x;
            if (x == pv) ++q;
            else {
                if (q) a.pb(q);
                pv = x;
                q = 1;
            }
        }

        a.pb(q);

        int K = a.size();

        vi ps(K + 1);
        forn(i, K) ps[i + 1] = ps[i] + a[i];

        int g = a[0], s = 0, b = 0;
        int i = 1;
        while (i < K && s <= g) s += a[i++];
        while (i < K && (2 * ps[i + 1] <= ps[K] || b <= g)) b += a[i++];

        if (s <= g || b <= g || 2 * (g + s + b) > n) g = s = b = 0;

        cout << g << ' ' << s << ' ' << b << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}