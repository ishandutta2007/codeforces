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

const int maxn = 1100000;
int par[maxn];

int root(int x) {
    return par[x] == x ? x : par[x] = root(par[x]);
}

void unite(int i, int j) {
    par[root(i)] = root(j);
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
        vi a(n);
        forn(i, n) {
            cin >> a[n - i - 1];
            a[n - i - 1] += n - i - 1;
        }
        vi vis(n, -1);
        vi seq;
        int v;
        for (v = 0; vis[v] == -1; v = a[v]) vis[v] = seq.size(), seq.pb(v);
/*        for (int x: seq) cerr << x << ' ';
        cerr << '\n';
        cerr << v << ' ' << vis[v] << '\n';*/
        vi ans(seq.begin() + vis[v], seq.end());
        cout << ans.size() << '\n';
        i64 sum = 0;
        for (int x: ans) {
            cout << n - x << ' ';
            sum += a[x] - x;
        }
        cout << '\n';
        assert(sum == 0);
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}