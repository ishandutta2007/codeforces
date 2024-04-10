#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010, P = 1000000007;
int K, m, ans = 1, cnt[maxn], ways[maxn];
bool vis[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &m, &K);
    if (!K) {
        printf("%d\n", qp(m, m - 1)), exit(0);
    }
    for (int i = 0; i < m; i++) if (!vis[i]) {
        int num = 0;
        for (int j = i; !vis[j]; j = 1LL * K * j % m) num++, vis[j] = 1;
        cnt[num]++;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j += i) {
            ways[j] = (ways[j] + 1LL * i * cnt[i]) % P;
        }
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++) if (!vis[i]) {
        int num = 0;
        for (int j = i; !vis[j]; j = 1LL * K * j % m) num++, vis[j] = 1;
        ans = 1LL * ans * ways[num] % P;
    }
    printf("%d\n", ans);
    return 0;
}