#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;
int n, x[maxn], y[maxn], cnt[maxn][maxn][maxn];
bitset<maxn> tmp, b[maxn][maxn];
long long ans1, ans2;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    ans1 = 1LL * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120;
    auto cross = [&](int i, int j, int k) {
        int x1 = x[j] - x[i], y1 = y[j] - y[i];
        int x2 = x[k] - x[i], y2 = y[k] - y[i];
        return 1LL * x1 * y2 - 1LL * x2 * y1;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) if (i ^ k && j ^ k) {
                if (cross(i, j, k) < 0) b[i][j][k] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                tmp = cross(i, j, k) < 0 ? b[i][j] : b[j][i];
                tmp &= cross(j, k, i) < 0 ? b[j][k] : b[k][j];
                tmp &= cross(i, k, j) < 0 ? b[i][k] : b[k][i];
                cnt[i][j][k] = tmp.count();
                ans1 -= 1LL * cnt[i][j][k] * (cnt[i][j][k] - 1) / 2;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (i ^ j) {
            for (int k = 1; k <= n; k++) if (i ^ k && j ^ k) {
                vector<int> V = {i, j, k};
                sort(V.begin(), V.end());
                cnt[i][j][k] = cnt[V[0]][V[1]][V[2]];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            bitset<maxn> b1, b2;
            for (int k = 1; k <= n; k++) if (i ^ k && j ^ k) {
                if (cross(i, j, k) < 0) b1.set(k);
                else b2.set(k);
            }
            for (int k = 1; k <= n; k++) if (i ^ k && j ^ k) {
                if (cross(i, j, k) < 0) {
                    tmp = b2;
                    tmp &= cross(i, k, j) < 0 ? b[i][k] : b[k][i];
                    tmp &= cross(j, k, i) < 0 ? b[j][k] : b[k][j];
                    ans2 += 1LL * tmp.count() * cnt[i][j][k];
                } else {
                    tmp = b1;
                    tmp &= cross(i, k, j) < 0 ? b[i][k] : b[k][i];
                    tmp &= cross(j, k, i) < 0 ? b[j][k] : b[k][j];
                    ans2 += 1LL * tmp.count() * cnt[i][j][k];
                }
            }
        }
    }
    printf("%lld\n", ans1 - ans2 / 2);
    return 0;
}