#include <bits/stdc++.h>
using namespace std;
struct edge {
    int u, v, w;
} e[200010];
int fa[200010], n, m;
inline int getf(int a) {return fa[a] == a ? a : fa[a] = getf(fa[a]);}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    sort(e + 1, e + 1 + m, [](const edge &a, const edge &b) {return a.w < b.w;});
    int ans = 0;
    for(int l = 1, r; l <= m; l = r + 1) {
        for(r = l; r < m && e[r + 1].w == e[l].w; r++);
        int cnt1 = 0, cnt2 = 0;
        for(int i = l; i <= r; i++) if(getf(e[i].u) != getf(e[i].v)) cnt1++;
        for(int i = l; i <= r; i++) if(getf(e[i].u) != getf(e[i].v)) cnt2++, fa[getf(e[i].u)] = e[i].v;
        ans += cnt1 - cnt2;
    }
    return cout << ans << endl, 0;
}