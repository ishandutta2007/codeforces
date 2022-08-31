#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int MAXN = 210000;
const i64 P = 1000000000 + 7;
vi e[MAXN];
i64 dp[MAXN], ans[MAXN];
vi64 dpp[MAXN], dps[MAXN];

void dfs(int v, int p) {
    dp[v] = 1;
    dpp[v].pb(1);
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[v] *= dp[u] + 1;
        dp[v] %= P;
        dpp[v].pb(dp[v]);
    }
    dps[v].pb(1);
    ford(i, e[v].size()) {
        int u = e[v][i];
        if (u == p) continue;
        i64 x = dps[v].back() * (dp[u] + 1) % P;
        dps[v].pb(x);
    }
}

void dfs2(int v, int p) {
    ans[v] = dp[v];
    if (p != -1) ans[v] *= dp[p] + 1, ans[v] %= P;
    i64 org = dp[v];
    int m = e[v].size() - (p != -1);
    int i = 0;
    for (int u: e[v]) {
        if (u == p) continue;
        dp[v] = dpp[v][i] * dps[v][m - i - 1] % P;
        if (p != -1) dp[v] *= dp[p] + 1, dp[v] %= P;
        dfs2(u, v);
        ++i;
    }
    dp[v] = org;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    forn(i, N - 1) {
        int p;
        cin >> p;
        --p;
        e[i + 1].pb(p);
        e[p].pb(i + 1);
    }
    dfs(0, -1);
    dfs2(0, -1);
    forn(i, N) cout << ans[i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}