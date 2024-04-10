#include <bits/stdc++.h>
using namespace std;
int n, m;
int opt[500010];
int fa[500010], tag[500010];
int gf(int a) {return fa[a] == a ? a : fa[a] = gf(fa[a]);}
vector < int > ans;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) {
        int len;
        scanf("%d", &len);
        if (len == 1) {
            int u;
            scanf("%d", &u);
            if (tag[gf(u)]) continue;
            tag[gf(u)] = 1;
            ans.push_back(i);
        }
        else {
            int u, v;
            scanf("%d%d", &u, &v);
            if (gf(u) == gf(v) || tag[gf(u)] && tag[gf(v)]) continue;
            else ans.push_back(i), tag[gf(v)] |= tag[gf(u)], fa[gf(u)] = gf(v);
        }
    }
    int c = 1;
    for (int j = ans.size(); j --> 0; ) c = c * 2 % 1000000007;
    printf("%d %d\n", c, (int)ans.size());
    for (auto i : ans) printf("%d ", i);
}