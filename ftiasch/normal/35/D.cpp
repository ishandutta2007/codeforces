#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100;
const int M = 10000;

int n, m, c[N], maximum[M + 1];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", c + i);
    }
    memset(maximum, 0, sizeof(maximum));
    for (int i = 0; i < n; ++ i) {
        int cost = c[i] * (n - i);
        for (int j = m; j >= cost; -- j) {
            maximum[j] = std::max(maximum[j - cost] + 1, maximum[j]);
        }
    }
    printf("%d\n", maximum[m]);
    return 0;
}