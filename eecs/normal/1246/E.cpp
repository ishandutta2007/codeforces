#include <bits/stdc++.h>
using namespace std;

int n, K, a[16], coef[16];
bitset<2010> f[1 << 16];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    f[0][0] = 1;
    for (int S = 0; S < 1 << n; S++) {
        for (int i = 2000 / K * K; i; i -= K) {
            if (f[S][i]) f[S][i / K] = 1;
        }
        for (int i = 0; i < n; i++) if (!(S >> i & 1)) {
            f[S | (1 << i)] |= f[S] << a[i];
        }
    }
    if (!f[(1 << n) - 1][1]) puts("NO"), exit(0);
    vector<int> V;
    int cur = 0;
    function<void(int, int)> print = [&](int S, int i) {
        if (__builtin_popcount(S) == 1) { coef[__lg(S)] = cur; return; }
        while (1) {
            for (int j = 0; j < n; j++) if (S >> j & 1) {
                if (i >= a[j] && f[S ^ (1 << j)][i - a[j]]) {
                    coef[j] = cur, print(S ^ (1 << j), i - a[j]); return;
                }
            }
            cur++, i *= K;
        }
    };
    print((1 << n) - 1, 1);
    priority_queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) {
        Q.emplace(coef[i], a[i]);
    }
    puts("YES");
    while (Q.size() > 1) {
        auto x = Q.top(); Q.pop();
        auto y = Q.top(); Q.pop();
        printf("%d %d\n", x.second, y.second);
        int z = x.second + y.second;
        while (!(z % K)) z /= K, x.first--;
        Q.emplace(x.first, z);
    }
    return 0;
}