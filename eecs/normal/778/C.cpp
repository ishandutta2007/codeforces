#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, tot, ch[maxn * 2][26], sz[maxn], ans[maxn];
vector<pair<int, int>> pos;

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        char c[2]; scanf("%d %d %s", &u, &v, c);
        ch[u][c[0] - 'a'] = v;
    }
    fill(ans, ans + n + 1, n);
    function<void(int, int, int)> chk = [&](int d, int v, int k) {
        for (int c = 0; c < 26; c++) if (ch[v][c]) {
            if (!ch[k][c]) pos.emplace_back(k, c), ch[k][c] = ++tot, ans[d]++;
            chk(d, ch[v][c], ch[k][c]);
        }
    };
    function<void(int, int)> dfs = [&](int v, int dep) {
        sz[v] = 1;
        int mx = 0;
        for (int c = 0; c < 26; c++) if (ch[v][c]) {
            dfs(ch[v][c], dep + 1), sz[v] += sz[ch[v][c]];
            if (sz[ch[v][c]] > sz[mx]) mx = ch[v][c];
        }
        pos.clear(), tot = n;
        if (mx) ans[dep]--;
        for (int c = 0; c < 26; c++) if (ch[v][c] && ch[v][c] ^ mx) {
            ans[dep] -= sz[ch[v][c]];
            chk(dep, ch[v][c], mx);
        }
        for (auto p : pos) ch[p.first][p.second] = 0;
    };
    dfs(1, 1);
    int p = min_element(ans, ans + n + 1) - ans;
    printf("%d\n%d\n", ans[p], p);
    return 0;
}