#include <bits/stdc++.h>
using namespace std;
vector <int> son[100010];
int fa[100010], maxdis[100010];
inline int cmp(int a, int b) {
    return maxdis[a] < maxdis[b];
}
int n;
vector <int> ans1, ans2;
inline void out() {
    for(int i = 0; i < ans1.size(); i++) printf("%d%c", ans1[i] - 1, " \n"[i == ans1.size() - 1]);
    printf("%d\n", (int)ans2.size());
    for(int i = 0; i < ans2.size(); i++) printf("%d%c", ans2[i] - 1, " \n"[i == ans2.size() - 1]);
}
inline int dfs(int now, int tag) {
    sort(son[now].begin(), son[now].end(), cmp);
    ans1.push_back(now);
    int last = 0;
    for(int j = 0; j < tag; j++) ans2.push_back(now);
    for(int i = 0; i < son[now].size(); i++) {
        last = dfs(son[now][i], last);
    }
    return last + 1;
}
int main() {
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        scanf("%d", fa + i);
        fa[i]++;
        son[fa[i]].push_back(i);
    }
    for(int i = n; i >= 1; i--) {
        maxdis[i] = 0;
        for(int j = 0; j < son[i].size(); j++) if(maxdis[i] < maxdis[son[i][j]] + 1) maxdis[i] = maxdis[son[i][j]] + 1;
    }
    dfs(1, 0);
    out();
}