#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1000;

int n, q;
bool black[N + 2][N + 2];

int main() {
    scanf("%d%d", &n, &q);
    memset(black, 0, sizeof(black));
    for (int k = 1; k <= q; ++ k) {
        int x, y;
        scanf("%d%d", &x, &y);
        x --, y --;
        black[x][y] = true;
        bool found = false;
        for (int i = std::max(x - 2, 0); i <= x; ++ i) {
            for (int j = std::max(y - 2, 0); j <= y; ++ j) {
                bool valid = true;
                for (int dx = 0; dx < 3; ++ dx) {
                    for (int dy = 0; dy < 3; ++ dy) {
                        valid &= black[i + dx][j + dy];
                    }
                }
                found |= valid;
            }
        }
        if (found) {
            printf("%d\n", k);
            return 0;
        }
    }
    puts("-1");
    return 0;
}