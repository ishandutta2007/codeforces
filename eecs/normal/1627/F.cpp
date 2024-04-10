#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int T, n, K, dist[maxn][maxn], v[maxn][maxn][4];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &K);
        memset(dist, 0x3f, sizeof(dist));
        memset(v, 0, sizeof(v));
        for (int i = 1, r1, c1, r2, c2; i <= n; i++) {
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            if (make_pair(r1, c1) > make_pair(r2, c2)) swap(r1, r2), swap(c1, c2);
            if (r1 == r2) v[r1 - 1][c1][0]++, v[r1][c1][1]++;
            else v[r1][c1 - 1][2]++, v[r1][c1][3]++;
        }
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> Q;
        Q.push({dist[K / 2][K / 2] = 0, K / 2, K / 2});
        while (!Q.empty()) {
            auto p = Q.top(); Q.pop();
            if (p[0] ^ dist[p[1]][p[2]]) continue;
            int x1 = p[1], y1 = p[2], x2 = K - p[1], y2 = K - p[2];
            if (!x1 || x1 == K || !y1 || y1 == K) {
                printf("%d\n", n - p[0]); break;
            }
            for (int k = 0; k < 4; k++) {
                int _x1 = x1 + dx[k], _y1 = y1 + dy[k];
                if (_x1 < 0 || _x1 > K || _y1 < 0 || _y1 > K) continue;
                int w = p[0] + v[x1][y1][k] + v[x2][y2][k ^ 1];
                if (w < dist[_x1][_y1]) Q.push({dist[_x1][_y1] = w, _x1, _y1});
            }
        }
    }
    return 0;
}