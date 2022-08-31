#include <bits/stdc++.h>
using namespace std;
namespace treeArr {
    int sum[400010];
    inline void add(int x, int k) {
        for(; x <= 400000; x += x & -x) sum[x] += k;
    }
    inline int get(int x) {
        int ans = 0;
        for(; x; x -= x & -x) ans += sum[x];
        return ans;
    }
}
namespace AC {
    int son[400010][26], cnt;
    int fail[400010];
    vector<int> e[400010];
    int dfn[400010], sze[400010];
    int dfsnow;
    inline int add(char *s) {
        int now = 0;
        for(int i = 0, n = strlen(s); i < n; i++) {
            if(son[now][s[i] - 'a'] == 0) son[now][s[i] - 'a'] = ++cnt;
            now = son[now][s[i] - 'a'];
        }
        return now;
    }
    inline int getans(int id) {
        return treeArr :: get(dfn[id] + sze[id] - 1) - treeArr :: get(dfn[id] - 1);
    }
    inline void dfs(int now) {
        dfn[now] = ++dfsnow;
        sze[now] = 1;
        for(auto i : e[now]) dfs(i), sze[now] += sze[i];
    }
    inline void build() {
        queue<int> q;
        for(int i = 0; i < 26; i++) if(son[0][i]) q.push(son[0][i]);
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            e[fail[now]].push_back(now);
            for(int i = 0; i < 26; i++) {
                if(son[now][i]) fail[son[now][i]] = son[fail[now]][i], q.push(son[now][i]);
                else son[now][i] = son[fail[now]][i];
            }
        }
        dfs(0);
    }
    inline int f(int x, int k) {
        return son[x][k - 'a'];
    }
}
char c[400010];
int opt[400010];
vector<int> son[400010];
int ans[400010];
vector<pair<int, int> > que[400010];
void dfs(int now, int nowd) {
    nowd = AC :: f(nowd, c[now]);
    treeArr :: add(AC :: dfn[nowd], 1);
    for(auto i : son[now]) dfs(i, nowd);
    for(auto i : que[now]) {
        ans[i.second] = AC :: getans(i.first);
    }
    treeArr :: add(AC :: dfn[nowd], -1);
}
char s[400010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1, fa; i <= n; i++) {
        scanf("%d", opt + i);
        if(opt[i] == 2) scanf("%d", &fa), son[fa].push_back(i);
        scanf("%s", c + i);
    }
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        int id;
        scanf("%d%s", &id, s);
        que[id].push_back(make_pair(AC :: add(s), i));
    }
    AC :: build();
    for(int i = 1; i <= n; i++) if(opt[i] == 1) dfs(i, 0);
    for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}