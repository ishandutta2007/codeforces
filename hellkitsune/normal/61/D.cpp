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
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<PII> g[100000];
LL ans = 0;
int dist[100000];
int best;

void dfs(int v, int p, int cur) {
    dist[v] = cur;
    if (dist[v] > dist[best]) {
        best = v;
    }
    for (PII to : g[v]) if (to.first != p) {
        dfs(to.first, v, cur + to.second);
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n - 1) {
        int from, to, w;
        scanf("%d%d%d", &from, &to, &w), --from, --to;
        g[from].pb(mp(to, w));
        g[to].pb(mp(from, w));
        ans += w;
    }
    best = 0;
    dfs(0, -1, 0);
    ans = 2 * ans - dist[best];
    cout << ans << endl;
    return 0;
}