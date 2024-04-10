#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010, P = 998244353;
int r, c, ans, a[maxn * 2], fa[maxn * 2], xors[maxn * 2];
char str[maxn][maxn];
bool mark[maxn * 2];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &r, &c);
    int num = 0;
    for (int i = 1; i <= r; i++) {
        scanf("%s", str[i] + 1);
        for (int j = 1; j <= c; j++) num += str[i][j] == '?';
    }
    if (r % 2 == 0 && c % 2 == 0) printf("%d\n", qp(2, num)), exit(0);
    for (int sum : {0, 1}) {
        fill(a + 1, a + r + c + 1, sum);
        iota(fa + 1, fa + r + c + 1, 1);
        int e = 0, cnt = 0, all = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (str[i][j] == '1') {
                    a[i] ^= 1, a[r + j] ^= 1;
                } else if (str[i][j] == '?') {
                    int u = find(i), v = find(r + j);
                    if (u ^ v) fa[u] = v;
                    else e++;
                    all++;
                }
            }
        }
        memset(xors, 0, sizeof(xors));
        memset(mark, 0, sizeof(mark));
        bool flag = 1;
        for (int i = 1; i <= r + c; i++) {
            xors[find(i)] ^= a[i];
            if (i <= r && c % 2 == 0) {
                mark[find(i)] = 1;
            } else if (i <= r && r % 2 == 0) {
                int f = 0;
                for (int j = 1; j <= c; j++) if (str[i][j] == '?') f++;
                if (a[i] && !f) flag = 0;
                else if (f) all--;
            }
            if (i > r && r % 2 == 0) {
                mark[find(i)] = 1;
            } else if (i > r && c % 2 == 0) {
                int f = 0;
                for (int j = 1; j <= r; j++) if (str[j][i - r] == '?') f++;
                if (a[i] && !f) flag = 0;
                else if (f) all--;
            }
        }
        for (int i = 1; i <= r + c; i++) {
            if (i == find(i) && !mark[i] && xors[i]) flag = 0;
        }
        if (flag) {
            if (r % 2 && c % 2) {
                (ans += qp(2, e)) %= P;
            } else {
                (ans += qp(2, all)) %= P;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}