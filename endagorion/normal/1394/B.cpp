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

const int maxn = 210000, maxm = 210000;

int ub[10];
int u[maxm], v[maxm], ind[maxm];
vi e[maxn], re[maxn];
i64 a[maxn];
i64 b[10][10];

int n, m, k;
int ans = 0;

void rec(int d, i64 x) {
    if (d == k + 1) {
//        cerr << x << '\n';
        if (!x) ++ans;
        return;
    }
    forn(i, d) rec(d + 1, x ^ b[d][i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m >> k;
    mt19937 rng;
    forn(i, n) a[i] = rng();
    forn(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        u[w] = x;
        v[w] = y;
        e[x].pb(w);
        re[y].pb(w);
    }

    forn(i, n) {
//        sort(all(e[i]));
        forn(j, e[i].size()) {
            int ei = e[i][j];
            b[e[i].size()][j] ^= a[u[ei]] ^ a[v[ei]];
        }
    }
    rec(1, 0);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}