#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, m, fa[maxn], G[maxn][maxn];
char ans[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int _ = 1, u, v; _ <= m; _++) {
        scanf("%d %d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
    iota(fa + 1, fa + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) if (G[i][j]) {
            bool flag = 1;
            for (int k = 1; k <= n; k++) if (k ^ i && k ^ j) {
                flag &= G[i][k] == G[j][k];
            }
            if (flag) fa[find(i)] = find(j);
        }
    }
    int cnt = 0;
    vector<int> V;
    for (int i = 1; i <= n; i++) if (i == find(i)) {
        cnt++, V.push_back(i);
    }
    if (cnt > 3) {
        puts("No"), exit(0);
    }
    if (V.size() == 3 && G[V[0]][V[1]] && G[V[0]][V[2]] && G[V[1]][V[2]]) {
        puts("No"), exit(0);
    }
    if (V.size() == 1) {
        ans[V[0]] = 'a';
    } else if (V.size() == 2 && G[V[0]][V[1]]) {
        ans[V[0]] = 'a', ans[V[1]] = 'b';
    } else if (V.size() == 2) {
        ans[V[0]] = 'a', ans[V[1]] = 'c';
    } else if (G[V[0]][V[1]] && G[V[0]][V[2]]) {
        ans[V[0]] = 'b', ans[V[1]] = 'a', ans[V[2]] = 'c';
    } else if (G[V[0]][V[1]] && G[V[1]][V[2]]) {
        ans[V[0]] = 'a', ans[V[1]] = 'b', ans[V[2]] = 'c';
    } else if (G[V[0]][V[2]] && G[V[1]][V[2]]) {
        ans[V[0]] = 'a', ans[V[1]] = 'c', ans[V[2]] = 'b';
    } else {
        ans[V[0]] = 'a', ans[V[1]] = 'b', ans[V[2]] = 'c';
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[find(i)];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (G[i][j] ^ (abs(ans[i] - ans[j]) <= 1)) puts("No"), exit(0);
        }
    }
    printf("Yes\n%s\n", ans + 1);
    return 0;
}