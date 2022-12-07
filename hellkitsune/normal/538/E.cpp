#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> g[200000];
const int INF = 1e9;
int cnt = 0;

int dfs(int v, bool mx) {
    if (mx) {
        int ans = INF;
        for (int to : g[v]) {
            int ret = dfs(to, !mx);
            ans = min(ans, ret);
        }
        if (ans == INF) ans = 0;
        return ans;
    } else {
        int ans = -1;
        for (int to : g[v]) {
            ans += dfs(to, !mx) + 1;
        }
        if (ans == -1) ans = 0;
        return ans;
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
    }
    REP(i, n) if (g[i].empty()) ++cnt;
    printf("%d %d\n", cnt - dfs(0, true), 1 + dfs(0, false));
    return 0;
}