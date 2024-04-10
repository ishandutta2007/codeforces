#include <bits/stdc++.h>
using namespace std;

int n, K, fir[40], a[40], pre[40], lst[10];
long long tar[41], mask[10];
vector<long long> V[10];

int main() {
    scanf("%d %d", &n, &K);
    if (n == 1) puts("ACCEPTED"), exit(0);
    memset(fir, -1, sizeof(fir));
    for (int i = 0, q; i < K; i++) {
        scanf("%d", &q);
        while (q--) {
            int j; scanf("%d", &j), j--;
            mask[i] |= 1LL << j;
            if (!~fir[j]) fir[j] = i;
        }
    }
    for (int k = 0; k <= n; k++) {
        for (int i = n - k; i < n; i++) {
            tar[k] |= 1LL << i;
        }
    }
    for (int i = 0; i < K; i++) {
        V[i].push_back(0);
        for (int j = n - 1; ~j; j--) if (mask[i] >> j & 1) {
            V[i].push_back(V[i].back() | (1LL << j));
        }
    }
    memset(lst, -1, sizeof(lst));
    for (int i = 0; i < n; i++) {
        if (!~fir[i]) puts("REJECTED"), exit(0);
        pre[i] = lst[fir[i]], lst[fir[i]] = i;
    }
    memset(a, -1, sizeof(a));
    function<void(int, long long)> dfs = [&](int p, long long S) {
        if (p == n) {
            for (int i = 0; i < K; i++) {
                int cnt = __builtin_popcountll(S & mask[i]);
                S = (S & ~mask[i]) | V[i][cnt];
            }
            if (S ^ tar[__builtin_popcountll(S)]) puts("REJECTED"), exit(0);
            return;
        }
        if (!~pre[p] || !a[pre[p]]) a[p] = 0, dfs(p + 1, S), a[p] = -1;
        a[p] = 1, dfs(p + 1, S | (1LL << p)), a[p] = -1;
    };
    dfs(0, 0), puts("ACCEPTED");
    return 0;
}