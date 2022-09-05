#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 17;
int n, K, f[maxn][4];
bool a[maxn];

void chk(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    scanf("%d %d", &n, &K);
    while (K--) {
        int x; scanf("%d", &x), a[--x] = 1;
    }
    function<void(int, int, int)> solve = [&](int k, int l, int r) {
        if (r - l == 2) {
            if (!a[l] && !a[l + 1]) f[k][0] = 0;
            else if (a[l] && a[l + 1]) f[k][3] = 1;
            else f[k][1] = f[k][2] = 1;
        } else {
            int mid = (l + r) >> 1, ls = k << 1, rs = k << 1 | 1;
            solve(ls, l, mid), solve(rs, mid, r);
            for (int i = 0; i < 4; i++) if (~f[ls][i]) {
                for (int j = 0; j < 4; j++) if (~f[rs][j]) {
                    int w1 = i >> 1, l1 = i & 1;
                    int w2 = j >> 1, l2 = j & 1;
                    chk(f[k][(w1 << 1) | w2 | l1 | l2], f[ls][i] + f[rs][j] + (w1 | w2) + (l1 | l2) + (w2 | l1 | l2));
                    swap(w1, w2);
                    chk(f[k][(w1 << 1) | w2 | l1 | l2], f[ls][i] + f[rs][j] + (w1 | w2) + (l1 | l2) + (w2 | l1 | l2));
                }
            }
        }
    };
    memset(f, -1, sizeof(f)), solve(1, 0, 1 << n);
    printf("%d\n", max({f[1][0], f[1][1] + 1, f[1][2] + 1, f[1][3] + 1}));
    return 0;
}