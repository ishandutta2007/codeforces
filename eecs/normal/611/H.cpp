#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, e[7][7], sz[7];
vector<int> nums[7];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int j = i, len = 0;
        while (j) len++, j /= 10;
        nums[len - 1].push_back(i);
    }
    for (int _ = 1; _ < n; _++) {
        static char foo[10], bar[10];
        scanf("%s %s", foo, bar);
        e[strlen(foo) - 1][strlen(bar) - 1]++;
    }
    int mx = (int)log10(n) + 1;
    for (int i = 0; i < mx; i++) {
        sz[i] = nums[i].size();
    }
    auto hall = [&]() {
        for (int i = 1; i < 1 << mx; i++) {
            int V = 0, E = 0;
            for (int j = 0; j < mx; j++) if (i >> j & 1) {
                V += sz[j];
                for (int k = 0; k < mx; k++) {
                    if (i >> k & 1) E += e[j][k];
                }
            }
            if (V <= E) return 0;
        }
        return 1;
    };
    if (!hall()) printf("-1\n"), exit(0);
    while (1) {
        bool flag = 0;
        for (int i = 0; i < mx && !flag; i++) {
            for (int j = 0; j < mx; j++) if (e[i][j]) {
                if (sz[i] > 1) {
                    sz[i]--, e[i][j]--;
                    if (hall()) {
                        printf("%d %d\n", nums[i].back(), nums[j][0]);
                        nums[i].pop_back(), flag = 1; break;
                    }
                    sz[i]++, e[i][j]++;
                }
                if (sz[j] > 1) {
                    sz[j]--, e[i][j]--;
                    if (hall()) {
                        printf("%d %d\n", nums[j].back(), nums[i][0]);
                        nums[j].pop_back(), flag = 1; break;
                    }
                    sz[j]++, e[i][j]++;
                }
            }
        }
        if (!flag) break;
    }
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < mx; j++) if (e[i][j]) {
            printf("%d %d\n", nums[i][0], nums[j][0]);
        }
    }
    return 0;
}