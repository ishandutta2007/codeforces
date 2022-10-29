#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
int n, m, q;
int v[N];
char s[N];
int to[N];
#define id(x, y) ((x - 1) * m + y)
int dfn[N], low[N], stack[N], tot, instack[N];
int belong[N];
int Next[N];
bool not_start[N];
int own[N];
int cnt;
int f[N];
vector<int>g[N];
void dfs(int x) {
    low[x] = dfn[x] = ++tot;
    instack[stack[++stack[0]] = x] = 1;
    int u = to[x];
    if (!dfn[u]) {
        dfs(u);
        low[x] = min(low[x], low[u]);
    }else
    if (instack[u])
        low[x] = min(low[x], dfn[u]);
    if (dfn[x] == low[x]) {
        ++cnt;
        do{
            belong[stack[stack[0]]] = cnt;
            instack[stack[stack[0]--]] = 0;
        } while (stack[stack[0] + 1] != x);
    }
}
bool dfs(int x, int st) {
    if (st < 0) return 1;
    if ((own[x] >> s[st]) & 1) st --;
    if (st < 0) return 1;
    for (auto u:g[x])
        if (dfs(u, st)) return 1;
    return 0;
}
int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            char c;
            scanf(" %c", &c);
            v[id(i, j)] = c - '0';
        }
    for (int i = 0; i <  10; i ++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        for (int j = 1; j <= n; j ++)
            for (int k = 1; k <= m; k ++)
            if (v[id(j, k)] == i){
                int xx = x + j, yy = y + k;
                if (xx <= 0 || yy <= 0 || xx > n || yy > m)
                    to[id(j, k)] = id(j, k);
                else
                    to[id(j, k)] = id(xx, yy);
            }
    }
    for (int i = 1; i <= n * m; i ++) {
        if (!dfn[i])
            dfs(i);
        own[belong[i]] |= (1 << v[i]);
        if (Next[belong[i]]|| to[i] == i) {
            Next[belong[i]] = -1;
        } else
            Next[belong[i]] = belong[to[i]];
        not_start[belong[to[i]]] = 1;
    }
    for (int i = 1; i <= cnt; i ++)
        if (Next[i] != -1)
            g[Next[i]].push_back(i);
    while (q --) {
        scanf("%s", s);
        bool sig = 0;
        int len = strlen(s);
        f[len] = 0;
        for (int i = len - 1; i >= 0; i --)
            f[i] = f[i + 1] | (1 << (s[i] -= '0'));
        for (int i = 1; i <= cnt && !sig; i ++)
            if (Next[i] == -1){
                int st = len - 1;
                for (int j = 20; j >= 0; j --)
                    while ((st - (1 << j)) + 1 >= 0 && (f[st - (1 << j) + 1] & own[i]) == f[st - (1 << j) + 1]) {
                        st -= (1 << j);
                    }
                sig |= dfs(i, st);
            }
        sig?puts("YES"):puts("NO");
    }
    return 0;
}