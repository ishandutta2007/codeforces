#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int n, K, f[5010][5010];

int& mp(pair<int, int> p) {
    return f[n - p.first][p.second];
}

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int k = 0; k <= K; k++) {
        for (int i = max(0, n - K); i <= n; i++) {
            if (!k) mp({i, k}) = qp(2, i);
            else mp({i, k}) = 1LL * i * (mp({i, k - 1}) - mp({i - 1, k - 1}) + P) % P;
        }
    }
    printf("%d\n", mp({n, K}));
    return 0;
}