#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int K, n, ans, tim, cur, vis[maxn], ax[7], ay[7], p[7], bx[maxn], by[maxn];
vector<int> V[7][maxn];

int main() {
    scanf("%d %d", &K, &n);
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &ax[i], &ay[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bx[i], &by[i]);
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) if (j ^ k) {
                int x1 = ax[i] - bx[k], y1 = ay[i] - by[k];
                int x2 = bx[j] - bx[k], y2 = by[j] - by[k];
                if (1LL * x1 * y2 == 1LL * x2 * y1 && 1LL * x1 * x2 + 1LL * y1 *
                    y2 <= 0) V[i][j].push_back(k);
            }
        }
    }
    function<bool(int)> dfs = [&](int i) {
        if (cur >= K) return 0;
        int k = p[cur++];
        vis[i] = tim;
        for (int j : V[k][i]) if (vis[j] ^ tim) {
            if (!dfs(j)) return 0;
        }
        return 1;
    };
    for (int i = 0; i < n; i++) {
        iota(p, p + K, 0);
        do {
            tim++, cur = 0;
            if (dfs(i)) { ans++; break; }
        } while (next_permutation(p, p + K));
    }
    printf("%d\n", ans);
    return 0;
}