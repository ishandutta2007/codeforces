#include <bits/stdc++.h>
using namespace std;

int T, n, m, K;
bitset<10010> b[110][110];

int main() {
    scanf("%d", &T);
    b[1][1].set(0);
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (j > 1) b[i][j] |= (b[i][j - 1] << i);
            if (i > 1) b[i][j] |= (b[i - 1][j] << j);
        }
    }
    while (T--) {
        scanf("%d %d %d", &n, &m, &K);
        puts(b[n][m][K] ? "YES" : "NO");
    }
    return 0;
}