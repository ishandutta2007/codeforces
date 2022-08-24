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

const int maxn = 210000;
const i64 P = 998244353;
vi e[maxn];
i64 dp[maxn][3];
i64 buf[3];

void add(i64 &x, i64 y) {
    x += y;
    x %= P;
}

void dfs(int v) {
    if (e[v].empty()) {
        dp[v][2] = 1;
        return;
    }
    dp[v][0] = 1;
    for (int u: e[v]) {
        dfs(u);
        forn(z, 3) buf[z] = 0;
        forn(z, 3) if (z != 1) add(buf[0], dp[v][0] * dp[u][z]); // no root color
        for1(z, 2) add(buf[z], dp[v][z] * dp[u][0]); // root color, no child color
        for1(z, 2) add(buf[1], dp[v][0] * dp[u][z]); // new root color
        for1(z, 2) add(buf[z], dp[v][z] * dp[u][2]); // don't use child color
        for1(z, 2) add(buf[2], dp[v][2] * dp[u][z]); // already full root color
        for1(z, 2) add(buf[2], dp[v][1] * dp[u][z]); // root color becomes full
        forn(z, 3) dp[v][z] = buf[z];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    for1(i, n - 1) {
        int p;
        cin >> p;
        e[--p].pb(i);
    }

    dfs(0);
    cout << (dp[0][0] + dp[0][2]) % P << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}