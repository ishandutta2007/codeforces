#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> g[100000];
int deg[100000] = {};
queue<int> q;
int d[100000] = {};
bool deleted[100000] = {};

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
        ++deg[from];
        ++deg[to];
    }
    REP(i, n) if (deg[i] == 1) {
        d[i] = 1;
        q.push(i);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (d[v] > 2) continue;
        deleted[v] = true;
        for (int to : g[v]) if (!deleted[to]) {
            d[to] += d[v];
            if (d[v] == 2) ++d[to];
            --deg[to];
            if (deg[to] == 1) {
                q.push(to);
            }
        }
    }
    REP(i, n) if (!deleted[i] && deg[i] <= 1) {
        deleted[i] = true;
        while (true) {
            int cnt = 0, v = -1;
            for (int to : g[i]) if (!deleted[to]) {
                ++cnt;
                v = to;
            }
            if (cnt == 0) break;
            if (cnt > 1) {
                printf("No\n");
                return 0;
            }
            i = v;
            deleted[i] = true;
        }
        break;
    }
    REP(i, n) if (!deleted[i]) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}