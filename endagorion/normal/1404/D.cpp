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

    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "First" << endl;
        forn(z, 2) for1(j, n) cout << j << ' ';
        cout << endl;
    } else {
        cout << "Second" << endl;
        vi vis(n);
        vi match(2 * n);
        vvi ps(n);
        for1(i, 2 * n) {
            int x;
            cin >> x;
            --x;
            ps[x].pb(i % (2 * n));
        }
        forn(i, n) forn(x, 2) match[ps[i][x]] = ps[i][x ^ 1];

        vi take(2 * n);

        int sum = 0;
        int oddV = -1;
        forn(i, 2 * n) {
            if (vis[i % n]) continue;
            int v = i;
            int len = 0;
            while (!vis[v % n]) {
                ++len;
                vis[v % n] = 1;
                take[v] = 1;
                (sum += v) %= (2 * n);
                v = match[v] + n;
                v %= (2 * n);
            }
            if (len % 2) oddV = v;
        }
        assert(sum % n == 0 && oddV != -1);

        if (sum == n) {
            int v = oddV;
            while (1) {
                take[v] = 0;
                take[(v + n) % (2 * n)] = 1;
                (sum += n) %= (2 * n);
                v = match[v] + n;
                v %= (2 * n);
                if (v == oddV) break;
            }
        }
//      assert(sum == 0 && accumulate(all(take), 0) == n);
        forn(i, 2 * n) if (take[i]) cout << (i == 0 ? 2 * n : i) << ' ';
        cout << endl;
    }
    int verd;
    cin >> verd;
    assert(verd == 0);

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}