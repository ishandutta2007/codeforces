#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int MAXN = 200000;
vi e[MAXN];
int c[MAXN];
const i64 P = 1000000000 + 7;
i64 dp[MAXN][2];

void dfs(int v) {
    if (c[v]) {
        dp[v][0] = 0;
        dp[v][1] = 1;
        forn(i, e[v].size()) {
            int u = e[v][i];
            dfs(u);
            dp[v][1] *= dp[u][0] + dp[u][1];
            dp[v][1] %= P;
        }
    } else {
        dp[v][0] = 1;
        vi64 pref(e[v].size() + 1), suf(e[v].size() + 1);
        pref[0] = suf[0] = 1;
        forn(i, e[v].size()) {
            int u = e[v][i];
            dfs(u);
            dp[v][0] *= dp[u][0] + dp[u][1];
            dp[v][0] %= P;
        }
        forn(i, e[v].size()) {
            int u = e[v][i];
            pref[i + 1] = pref[i] * (dp[u][0] + dp[u][1]) % P;
            u = e[v][e[v].size() - i - 1];
            suf[i + 1] = suf[i] * (dp[u][0] + dp[u][1]) % P;
        }
        forn(i, e[v].size()) {
            int u = e[v][i];
            dp[v][1] += dp[u][1] * pref[i] % P * suf[e[v].size() - i - 1];
            dp[v][1] %= P;
        }
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    forn(i, N - 1) {
        int x;
        cin >> x;
        e[x].pb(i + 1);
    }
    forn(i, N) {
        cin >> c[i];
    }
    dfs(0);
    cout << dp[0][1] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}