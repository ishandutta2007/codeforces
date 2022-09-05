#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, P = 1000000007;
int n, ans, q, x, a[maxn], c[maxn], b[maxn], f[maxn][maxn * maxn];
map<int, int> mp;

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d", &n);
    int prod = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        prod = 1LL * prod * (c[i] + 1) % P;
    }
    for (int i = 2; i <= n; i++) {
        scanf("%d", &b[i]);
        b[i] += b[i - 1];
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &x);
        if (mp.count(x)) { printf("%d\n", mp[x]); continue; }
        bool flag = 0;
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += -b[i] - x;
            if (cur + i * 100 < 0) { flag = 1; break; }
        }
        if (flag) { printf("%d\n", mp[x] = 0); continue; }
        flag = 1, cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += -b[i] - x;
            if (cur < 0) { flag = 0; break; }
        }
        if (flag) { printf("%d\n", mp[x] = prod); continue; }
        memset(f, 0, sizeof(f));
        f[0][0] = 1, cur = ans = 0;
        for (int i = 1; i <= n; i++) {
            int l = -b[i] - x, r = c[i] - b[i] - x;
            cur += l;
            for (int j = 1; j <= i * 100; j++) {
                red(f[i - 1][j] += f[i - 1][j - 1] - P);
            }
            for (int j = 0; j <= i * 100; j++) {
                f[i][j] = f[i - 1][j];
                if (j >= c[i] + 1) red(f[i][j] -= f[i - 1][j - c[i] - 1]);
            }
            for (int j = 0; j <= i * 100; j++) {
                if (cur + j < 0) f[i][j] = 0;
                if (i == n) red(ans += f[i][j] - P);
            }
        }
        printf("%d\n", mp[x] = ans);
    }
    return 0;
}