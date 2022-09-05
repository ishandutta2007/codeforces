#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, m;
bool mark[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        fill(mark + 1, mark + n + 1, 0);
        while (m--) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c), mark[b] = 1;
        }
        for (int i = 1; i <= n; i++) if (!mark[i]) {
            for (int j = 1; j <= n; j++) {
                if (i ^ j) printf("%d %d\n", i, j);
            }
            break;
        }
    }
    return 0;
}