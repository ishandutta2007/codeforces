#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, m, fa[maxn];
char s[maxn][maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    iota(fa + 1, fa + n + m + 1, 1);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#') fa[find(i)] = find(j + n);
        }
    }
    for (int i = 1; i <= n + m; i++) if (i == find(i)) {
        int l = 0, r = 0, e = 0;
        for (int j = 1; j <= n; j++) if (i == find(j)) {
            l++;
            for (int k = 1; k <= m; k++) {
                if (s[j][k] == '#' && i == find(n + k)) e++;
            }
        }
        for (int j = n + 1; j <= n + m; j++) {
            if (i == find(j)) r++;
        }
        if (e != l * r) puts("No"), exit(0);
    }
    puts("Yes");
    return 0;
}