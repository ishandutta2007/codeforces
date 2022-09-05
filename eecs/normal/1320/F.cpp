#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
const int dx[] = {1, -1, 0, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};
int A, B, C, a[maxn], b[maxn];

int main() {
    scanf("%d %d %d", &A, &B, &C);
    function<void(int, int, int, int, int)> dfs = [&](int k, int x, int y, int z, int t) {
        if (!x || !y || !z || x > A || y > B || z > C) {
            if (t) puts("-1"), exit(0);
            return;
        }
        int cur = (x - 1) * B * C + (y - 1) * C + z;
        if (t) {
            if (!~a[cur] || a[cur] == t) {
                a[cur] = t, b[cur] |= 1 << k; return;
            }
            if (!a[cur]) {
                dfs(k, x + dx[k], y + dy[k], z + dz[k], t); return;
            }
        }
        if (a[cur] > 0) {
            for (int i = 0; i < 6; i++) if (b[cur] >> i & 1) {
                b[cur] ^= 1 << i;
                dfs(i, x + dx[i], y + dy[i], z + dz[i], a[cur]);
            }
        }
        a[cur] = 0, dfs(k, x + dx[k], y + dy[k], z + dz[k], t);
    };
    int n = A * B * C;
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= B; i++) {
        for (int j = 1, x; j <= C; j++) {
            scanf("%d", &x), dfs(0, 1, i, j, x);
        }
    }
    for (int i = 1; i <= B; i++) {
        for (int j = 1, x; j <= C; j++) {
            scanf("%d", &x), dfs(1, A, i, j, x);
        }
    }
    for (int i = 1; i <= A; i++) {
        for (int j = 1, x; j <= C; j++) {
            scanf("%d", &x), dfs(2, i, 1, j, x);
        }
    }
    for (int i = 1; i <= A; i++) {
        for (int j = 1, x; j <= C; j++) {
            scanf("%d", &x), dfs(3, i, B, j, x);
        }
    }
    for (int i = 1; i <= A; i++) {
        for (int j = 1, x; j <= B; j++) {
            scanf("%d", &x), dfs(4, i, j, 1, x);
        }
    }
    for (int i = 1; i <= A; i++) {
        for (int j = 1, x; j <= B; j++) {
            scanf("%d", &x), dfs(5, i, j, C, x);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i] > 0 ? a[i] : 0);
    }
    return 0;
}