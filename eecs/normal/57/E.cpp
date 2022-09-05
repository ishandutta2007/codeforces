#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P = 1000000007;
const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int n, ans, dist[210][210], res[50];
ll K;
bool ban[210][210];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%lld %d", &K, &n);
    memset(dist, -1, sizeof(dist));
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        ban[x + 100][y + 100] = 1;
    }
    memset(dist, -1, sizeof(dist));
    queue<array<int, 2>> Q;
    Q.push({100, 100}), dist[100][100] = 0;
    while (!Q.empty()) {
        auto p = Q.front(); Q.pop();
        for (int i = 0; i < 8; i++) {
            int x = p[0] + dx[i], y = p[1] + dy[i];
            if (x < 0 || x > 200 || y < 0 || y > 200) continue;
            if (!ban[x][y] && !~dist[x][y]) {
                Q.push({x, y}), dist[x][y] = dist[p[0]][p[1]] + 1;
            }
        }
    }
    for (int i = 0; i < 50; i++) {
        for (int x = 0; x <= 200; x++) {
            for (int y = 0; y <= 200; y++) {
                if (~dist[x][y] && dist[x][y] <= i) res[i]++;
            }
        }
    }
    if (K < 50) printf("%d\n", res[K]), exit(0);
    for (int i = 45; i < 50; i++) {
        int prod = 1;
        for (int j = 45; j < 50; j++) if (i ^ j) {
            prod = (K - j) % P * prod % P * qp(i - j + P, P - 2) % P;
        }
        ans = (ans + 1LL * res[i] * prod) % P;
    }
    printf("%d\n", ans);
    return 0;
}