#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, K, ans, cur, fa[maxn * maxn], sz[maxn * maxn], cnt[maxn * maxn];
char s[maxn][maxn];

inline int id(int x, int y) {
    return (x - 1) * n + y;
}

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '.') fa[id(i, j)] = id(i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (s[i][j] == '.') {
            if (s[i - 1][j] == '.') unite(id(i - 1, j), id(i, j));
            if (s[i][j - 1] == '.') unite(id(i, j - 1), id(i, j));
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == '.') sz[find(id(i, j))]++;
        }
    }
    auto ins = [&](int x, int y) {
        if (s[x][y] == 'X') {
            cur++;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (s[nx][ny] ^ '.') continue;
                int z = find(id(nx, ny));
                if (!cnt[z]++) cur += sz[z];
            }
            return;
        }
        x = find(id(x, y));
        if (!cnt[x]++) cur += sz[x];
    };
    auto del = [&](int x, int y) {
        if (s[x][y] == 'X') {
            cur--;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (s[nx][ny] ^ '.') continue;
                int z = find(id(nx, ny));
                if (!--cnt[z]) cur -= sz[z];
            }
            return;
        }
        x = find(id(x, y));
        if (!--cnt[x]) cur -= sz[x];
    };
    for (int i = 1; i <= n - K + 1; i++) {
        cur = 0, memset(cnt, 0, sizeof(cnt));
        for (int j = i; j <= i + K - 1; j++) {
            for (int k = 1; k <= K; k++) ins(j, k);
        }
        for (int j = 1; j <= n - K + 1; j++) {
            if (j > 1) {
                for (int k = 1; k <= K; k++) ins(i + k - 1, j + K - 1);
                for (int k = 1; k <= K; k++) del(i + k - 1, j - 1);
            }
            ans = max(ans, cur);
        }
    }
    printf("%d\n", ans);
    return 0;
}