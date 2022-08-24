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

const int maxn = 1001;
int par[maxn], sz[maxn];

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

    int n, d;
    cin >> n >> d;
    forn(i, n) par[i] = i, sz[i] = 1;
    int nc = 1;
    forn(i, d) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        x = root(x); y = root(y);
        if (x != y) {
            par[x] = y;
            sz[y] += sz[x];
        } else ++nc;
        vi szs;
        forn(i, n) if (par[i] == i) szs.pb(sz[i]);
        sort(rall(szs));
        cout << accumulate(szs.begin(), szs.begin() + min(nc, (int)szs.size()), -1) << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}