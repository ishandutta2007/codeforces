#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
set<int> se[100000];
int from[100000], to[100000];
queue<int> q;
bool used[100000] = {};

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        scanf("%d%d", from + i, to + i), --from[i], --to[i];
        se[from[i]].insert(i);
        se[to[i]].insert(i);
    }
    REP(i, n) if ((int)se[i].size() == 1) {
        q.push(i);
    }
    for (int i = -1; i < n; ++i) {
        if (i != -1 && !used[i] && !se[i].empty()) {
            q.push(i);
        }
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (se[v].empty()) continue;
            int e = *se[v].begin();
            se[from[e]].erase(e);
            se[to[e]].erase(e);
            used[v] = true;
            if (!used[from[e]] && (int)se[from[e]].size() == 1) {
                q.push(from[e]);
            }
            if (!used[to[e]] && (int)se[to[e]].size() == 1) {
                q.push(to[e]);
            }
        }
    }
    int ans = 0;
    REP(i, n) ans += !used[i];
    printf("%d\n", ans);
    return 0;
}