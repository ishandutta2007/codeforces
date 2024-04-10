#include <bits/stdc++.h>
using namespace std;
int n;
vector < int > x[200010], y[200010];
vector < int > son[200010];
char col[200010];
inline void dfs(int now) {
    for (auto i : son[now])
        if (col[i] == 0) col[i] = 'b' + 'r' - col[now], dfs(i);
}
#define addedge(a, b) son[a].push_back(b)
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        x[a].push_back(i), y[b].push_back(i);
    }
    for (int i = 1; i <= 200000; i++) {
        for (int j = 0; j + 1 < x[i].size(); j += 2) {
            addedge(x[i][j], x[i][j + 1]);
            addedge(x[i][j + 1], x[i][j]);
        }
    }
    for (int i = 1; i <= 200000; i++) {
        for (int j = 0; j + 1 < y[i].size(); j += 2) {
            addedge(y[i][j], y[i][j + 1]);
            addedge(y[i][j + 1], y[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) if (!col[i]) col[i] = 'b', dfs(i);
    puts(col + 1);
}