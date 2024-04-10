#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int e[400][400] = {};
queue<int> q;
int dist[400];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        e[from][to] = e[to][from] = 1;
    }
    if (e[0][n - 1] == 1) {
        REP(i, n) REP(j, n) e[i][j] ^= 1;
    }
    REP(i, n) dist[i] = -1;
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        REP(i, n) if (e[v][i] && dist[i] == -1) {
            dist[i] = dist[v] + 1;
            q.push(i);
        }
    }
    printf("%d\n", dist[n - 1]);
    return 0;
}