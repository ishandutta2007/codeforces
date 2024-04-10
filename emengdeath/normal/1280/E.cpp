#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int N = 2e6;
int T;
long long v;
vector<int>g[N];
bool type[N];
int n;
int d[N], du[N];
vector<int> b;
int fa[N];
long long w[N], ans[N];
void dfs(int x, long long v) {
    if (type[x] == 0) {
        if (!g[x].size()) {
            ans[x] = v;
            return;
        }
        for (auto u:g[x])
            if (w[u] == w[x]) {
                dfs(u, v);
                return ;
            }
    } else {
        for (auto u:g[x])
            dfs(u, v);
    }
}
int main() {
  //  freopen("input", "r" , stdin);
    scanf("%d", &T);
    while (T --) {
        scanf("%lld", &v);
        while (n --) g[n].clear(), fa[n] = -1, type[n] = 0;
        g[0].clear(), fa[0] = -1, type[0] = 0;
        vector<int>f;
        bool single = 0;
        n = 0;
        b.clear();
        do {
            char c;
            scanf(" %c", &c);
            if (c == '(') {
                if (!f.empty())
                    g[f[f.size() - 1]].push_back(n);
                f.push_back(n++);
            }else
                if (c == ')')
                    f.pop_back();
                else
                    if (c == '*') {
                        if (f.empty()) {
                            single = 1;
                            break;
                        }
                        b.push_back(n);
                        g[f[f.size() - 1]].push_back(n ++);
                    } else
                        if (c == 'S') {
                            type[f[f.size() - 1]] = 0;
                        } else
                            if (c == 'P')
                                type[f[f.size() - 1]] = 1;
        } while (!f.empty());
        if (single) {
            printf("REVOLTING %lld\n", v);
            continue;
        }
        for (int i = 0; i < n; i ++) {
            du[i] = g[i].size(), ans[i] = 0;
            for (auto u:g[i])
                fa[u] = i;
        }
        d[0] = 0;
        for (int i = 0; i < n ; i ++)
            if (!du[i])
                d[++d[0]] = i;
        for (int i = 1; i <= d[0]; i ++)
        {
            int x = d[i];
            if (fa[x] != -1 && !(--du[fa[x]]))
                d[++d[0]] = fa[x];
            if (type[x] == 0) {
                w[x] = 1e18;
                if (!g[x].size())
                    w[x] = 1;
                for (auto u:g[x])
                    w[x] = min(w[x], w[u]);
            } else {
                w[x] = 0;
                for (auto u:g[x])
                    w[x] += w[u];
            }
        }
        dfs(0, v * w[0]);
        printf("REVOLTING ");
        for (int i = 0; i < b.size(); i ++)
            printf("%lld%c", ans[b[i]], " \n"[i == b.size() - 1]);
    }
    return 0;
}