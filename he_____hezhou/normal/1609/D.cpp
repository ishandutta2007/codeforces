#include <bits/stdc++.h>
using namespace std;
int fa[1010], n, d, sze[1010];
int ans2;
inline int gf(int a) {
    return fa[a] == a ? a : fa[a] = gf(fa[a]);
}
int main() {
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++) sze[i] = 1, fa[i] = i;
    for (int i = 1; i <= d; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u = gf(u), v = gf(v);
        if (u == v) ans2++;
        else {
            sze[u] += sze[v];
            fa[v] = u;
        }
        vector < int > qwq;
        for (int j = 1; j <= n; j++) if (fa[j] == j) qwq.push_back(sze[j]);
        sort(qwq.begin(), qwq.end());
        reverse(qwq.begin(), qwq.end());
        int ans = 0;
        for (int i = 0; i < ans2 + 1 && i < qwq.size(); i++) ans += qwq[i];
        printf("%d\n", ans - 1);
    }
}