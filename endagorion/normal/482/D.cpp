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
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int MAXN = 100000;
const i64 P = 1000000000 + 7;

i64 ways[MAXN][2];
i64 w[MAXN][2][4];
i64 ww[2][4];
vi e[MAXN];

void dfs(int v) {
    w[v][1][0] = 1;
    forn(i, e[v].size()) {
        int u = e[v][i];
        dfs(u);
        forn(j, 2) forn(k, 4) ww[j][k] = 0;
        forn(s, 2) forn(j, 2) forn(k, 4) {
            ww[s ^ j][k | (1 << s)] += w[v][j][k] * ways[u][s];
            ww[s ^ j][k | (1 << s)] %= P;
        }
        forn(j, 2) forn(k, 4) {
            w[v][j][k] += ww[j][k];
            w[v][j][k] %= P;
        }
    }
    forn(j, 2) forn(k, 4) {
        int s = 1;
        if (k == 3 || j == 1 && k == 2) s = 2;
        ways[v][j] += s * w[v][j][k];
        ways[v][j] %= P;
    }
//    cerr << v << ' ' << ways[v][0] << ' ' << ways[v][1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    forn(i, N - 1) {
        int x;
        cin >> x;
        e[x - 1].pb(i + 1);
    }
    dfs(0);
    i64 ans = ways[0][0] + ways[0][1];
    cout << ans % P << '\n';


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}