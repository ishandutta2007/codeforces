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

int a[2000][2000];

bool vis[2000];
int N;

int dfs(int v, int r) {
    if (vis[v]) return 0;
    vis[v] = true;
    int res = 1;
    forn(i, N) {
        if ((r && a[v][i]) || (!r && a[i][v])) {
            res += dfs(i, r);
        }
    }
    return res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d", &N);
    forn(i, N) forn(j, N) scanf("%d", &a[i][j]);
    int m = 0;
    while (!a[m][m]) ++m;
    bool ok = dfs(m, 1) == N;
    forn(i, N) vis[i] = false;
    ok &= dfs(m, 0) == N;
    cout << (ok ? "YES" : "NO") << '\n';


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}