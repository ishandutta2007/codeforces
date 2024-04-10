#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
const int INF = 1e6;
const int MAX_N = 105;

queue <int> Q;
vector <int> path;

bool chk[2*MAX_N];
int n, m, a[MAX_N], b[MAX_N];
int min_wgt = INF, ans = 0, sum_a = 0, sum_b = 0;
int f[2*MAX_N][2*MAX_N], prv[2*MAX_N];

bool BFS() {
    memset(chk, 0, sizeof(chk));
    Q.push(0); chk[0] = true;
    while (!Q.empty()) {
        for (int i = 1; i <= 2*n+1; ++i)
            if (f[Q.front()][i] > 0 && !chk[i]) {
                Q.push(i); chk[i] = true;
                prv[i] = Q.front();
            }
        Q.pop();
    }
    if (!chk[2*n+1]) return false;
    int tmp = 2*n+1; path.push_back(tmp);
    while (tmp) {
        min_wgt = min(min_wgt, f[prv[tmp]][tmp]);
        tmp = prv[tmp]; path.push_back(tmp);
    }
    return true;
}

bool Solve() {
    while (BFS()) {
        ans += min_wgt;
        while (path.size() != 1) {
            f[path[path.size() - 1]][path[path.size() - 2]] -= min_wgt;
            f[path[path.size() - 2]][path[path.size() - 1]] += min_wgt;
            path.pop_back();
        }
        path.pop_back();
    }
    return (ans == sum_a && ans == sum_b);
}

int main() {
    memset(f, 0, sizeof(f));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) f[i][i+n] = INF;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum_a += a[i];
        f[0][i] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        sum_b += b[i];
        f[i+n][2*n+1] = b[i];
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        f[u][v+n] = f[v][u+n] = INF;
    }
    if (Solve()) {
        printf("YES\n");
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                printf("%d ", f[j+n][i]);
            printf("\n");
        }
    }
    else printf("NO");
    return 0;
}