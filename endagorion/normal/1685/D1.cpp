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

const int maxn = 210;
int p[maxn], inv[maxn];
int d[maxn], q[maxn];
int par[maxn];

int root(int x) {
    return x == par[x] ? x : par[x] = root(par[x]);
}

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
        forn(i, n) par[i] = i;
        forn(i, n) {
            cin >> p[i];
            --p[i];
            inv[p[i]] = i;
            par[root(i)] = root(p[i]);
        }

        forn(i, n) d[i] = inv[i];
        int sw = 0;
        forn(i, n - 1) {
            if (root(i) != root(i + 1)) {
                swap(d[i], d[i + 1]);
                par[root(i)] = root(i + 1);
                ++sw;
            }
        }

        forn(i, n) q[i] = -1;
//        forn(i, n) cerr << d[i] << ' ';
//        cerr << '\n';
        for (int i = 0, v = 0; i < n; ++i, v = d[v]) {
            q[i] = v;
        }
        forn(i, n) assert(q[i] != -1);
//        forn(i, n) inv[q[i]] = i;
//        forn(i, n) q[i] = inv[i];
        int score = 0;
        forn(i, n) score += abs(q[i] - p[q[(i + 1) % n]]);
//        cerr << score << ' ' << 2 * sw << '\n';
        assert(score == 2 * sw);
        forn(i, n) cout << q[i] + 1 << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}