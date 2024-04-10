#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, m;
set<int> col;
map<int, int> g[2];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &m);

    g[0].clear(); g[1].clear();
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a-1][b-1] = 1;
        col.insert(b-1);
    }

    ans = 1;
    for(int i = 0, nxt; ans && i < n; i = nxt) {
        auto ub = col.upper_bound(i);
        nxt = (ub == col.end()) ? n : *ub;
        int j = (nxt - i) % 2;

        if(!g[1][i] && !g[0][i]) continue;
        if(g[1][i] && g[0][i]) continue;

        if(g[1][i] && !g[0][i]) {
            j = 1 - j;
            if(nxt == n || g[j][nxt]) ans = 0;
            g[j][nxt] = 1;
        }
        if(!g[1][i] && g[0][i]) {
            if(nxt == n || g[j][nxt]) ans = 0;
            g[j][nxt] = 1;
        }
    }
    printf("%s\n", ans ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}