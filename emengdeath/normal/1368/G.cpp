#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
vector<int>e[2][N];
bool have_in[2][N];
int n, m;
char s[N];
int bel[N];
int tot, dfn_cnt;
int l[N], r[N];
#define id(x, y) (((x) - 1) * m + y)
struct node{
    int tag;
    int sum;
}f[N * 4];
void merge(int l, int r, int s) {
    if (f[s].tag)
        f[s].sum = r - l + 1;
    else {
        if (l == r) f[s].sum = 0;
        else
            f[s].sum = f[s + s].sum + f[s + s + 1].sum;
    }
}
void add(int l, int r, int s, int ll, int rr, int v) {
    if (r < ll || rr < l) return;
    if (ll <= l && r<= rr) {
        f[s].tag += v;
        merge(l, r, s);
        return;
    }
    add(l, (l + r) / 2 , s + s, ll, rr, v);
    add((l + r) / 2 + 1, r, s + s + 1, ll, rr, v);
    merge(l, r, s);
}
char op(char c) {
    switch (c) {
        case 'U':
            return 'D';
        case 'D':
            return 'U';
        case 'L':
            return 'R';
        case 'R':
            return 'L';

    }
}
void dfs(int x) {
    l[x] = ++dfn_cnt;
    for (auto u:e[0][x])
        dfs(u);
    r[x] = dfn_cnt;
}
long long ans = 0;
void dfs1(int x) {
    add(1, dfn_cnt, 1, l[x], r[x], 1);
    ans += f[1].sum;
    for (auto u:e[1][x])
        dfs1(u);
    add(1, dfn_cnt, 1, l[x], r[x], - 1);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i =1; i <= n;i ++)
        for (int j = 1; j <= m; j ++)
            scanf(" %c", &s[id(i, j)]);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j++)
            if (!bel[id(i, j)]) {
                bel[id(i, j)] = ++ tot;
                if (s[id(i, j)] == 'L')
                    bel[id(i, j + 1)] = tot;
                else
                    bel[id(i + 1, j)] = tot;
            }
    for (int i = 1; i <= n;i ++)
        for (int j = 1; j <= m;j ++) {
            bool sig = ((i + j) & 1);
            if (j - 2 > 0 && op(s[id(i, j)]) != s[id(i, j - 2)] && s[id(i, j - 2)] == 'L')
                e[sig][bel[id(i, j)]].push_back(bel[id(i, j - 2)]), have_in[sig][bel[id(i, j - 2)]] = 1;
            if (i - 2 > 0 && op(s[id(i, j)]) != s[id(i - 2, j)] && s[id(i - 2, j)] == 'U')
                e[sig][bel[id(i, j)]].push_back(bel[id(i - 2, j)]), have_in[sig][bel[id(i - 2, j)]] = 1;
            if (j + 2 <= m && op(s[id(i, j)]) != s[id(i, j + 2)] && s[id(i, j + 2)] == 'R')
                e[sig][bel[id(i, j)]].push_back(bel[id(i, j + 2)]), have_in[sig][bel[id(i, j + 2)]] = 1;
            if (i + 2 <= n && op(s[id(i, j)]) != s[id(i + 2, j)] && s[id(i + 2, j)] == 'D')
                e[sig][bel[id(i, j)]].push_back(bel[id(i + 2, j)]), have_in[sig][bel[id(i + 2, j)]] = 1;;
        }
    for (int i = 1; i <= tot; i ++)
        if (!have_in[0][i])
            dfs(i);
    for (int i = 1; i <= tot; i ++)
        if (!have_in[1][i])
            dfs1(i);
    printf("%lld\n", ans);
    return 0;
}