#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > e;
vector<int> son[100010];
int n, m;
int tag[100010];
int fa[100010];
inline int gf(int a) {return fa[a] == a ? a : fa[a] = gf(fa[a]);}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        son[u].push_back(v);
        son[v].push_back(u);
        e.push_back(make_pair(u, v));
    }
    int id = 1;
    for(int i = 2; i <= n; i++) {
        if(son[id].size() > son[i].size()) id = i;
    }
    for(auto i : son[id]) {
        fa[i] = i;
    }
    for(int i = 1; i <= n; i++) if(fa[i] == 0) fa[i] = id;
    for(auto i : son[id]) {
        for(int d = 1; d <= n; d++) tag[d] = 0;
        for(auto j : son[i]) {
            tag[j] = 1;
        }
        for(int d = 1; d <= n; d++) if(tag[d] == 0) fa[gf(d)] = gf(i);
    }
    int cnt = 0;
    for(auto i : e) if(gf(i.first) == gf(i.second)) return puts("-1"), 0;
    for(int i = 1; i <= n; i++) if(gf(i) == i) tag[i] = ++cnt;
    if(cnt != 3) return puts("-1"), 0;
    for(int i = 1; i <= n; i++) {
        printf("%d ", tag[gf(i)]);
    }
    return 0;
}