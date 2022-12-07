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

int n, m, k;
vector<int> g[3000];
int dist[3000][3000], pre[3000][3000];
vector<int> bad[3000][3000];
queue<PII> q;
vector<int> ans;

inline bool check(int &a, int &b, int &c) {
    int pos = lower_bound(bad[a][b].begin(), bad[a][b].end(), c) - bad[a][b].begin();
    return pos >= (int)bad[a][b].size() || bad[a][b][pos] != c;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    REP(i, k) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c), --a, --b, --c;
        bad[a][b].pb(c);
    }
    REP(i, n) REP(j, n) sort(bad[i][j].begin(), bad[i][j].end());
    REP(i, n) REP(j, n) dist[i][j] = -1;
    for (int to : g[0]) {
        dist[0][to] = 1;
        q.push(mp(0, to));
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int curDist = dist[x][y] + 1;
        for (int to : g[y]) if (dist[y][to] == -1 && check(x, y, to)) {
            dist[y][to] = curDist;
            pre[y][to] = x;
            q.push(mp(y, to));
        }
    }
    int best = -1;
    REP(i, n) if (dist[i][n - 1] != -1 && (best == -1 || dist[best][n - 1] > dist[i][n - 1])) {
        best = i;
    }
    if (best == -1) {
        printf("-1\n");
        return 0;
    }
    int x = best;
    int y = n - 1;
    printf("%d\n", dist[x][y]);
    ans.pb(y), ans.pb(x);
    while (x != 0) {
        int ny = x;
        x = pre[x][y];
        y = ny;
        ans.pb(x);
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) printf("%d ", x + 1);
    printf("\n");
    return 0;
}