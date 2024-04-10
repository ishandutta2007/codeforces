#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, K, f[maxn][maxn];
char s[maxn][maxn];
bool vis[maxn][maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    auto chk = [&](int x) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = s[i][j] != 'a';
                if (i == 1) f[i][j] += f[i][j - 1];
                else if (j == 1) f[i][j] += f[i - 1][j];
                else f[i][j] += min(f[i][j - 1], f[i - 1][j]);
                if (i + j == x + 1 && f[i][j] <= K) return 1;
            }
        }
        return 0;
    };
    int l = 1, r = 2 * n - 1, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? l = (ans = mid) + 1 : r = mid - 1;
    }
    for (int i = 1; i <= ans; i++) {
        putchar('a');
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = s[i][j] != 'a';
            if (i == 1) f[i][j] += f[i][j - 1];
            else if (j == 1) f[i][j] += f[i - 1][j];
            else f[i][j] += min(f[i][j - 1], f[i - 1][j]);
            if (i + j == ans + 1 && f[i][j] <= K) vis[i][j] = 1;
        }
    }
    for (int i = ans + 1; i <= 2 * n - 1; i++) {
        if (!ans) vis[1][1] = 1;
        for (int j = 1; j <= n; j++) {
            int k = i - j;
            if (k < 1 || k > n || !vis[j][k]) continue;
            if (j < n) vis[j + 1][k] = 1;
            if (k < n) vis[j][k + 1] = 1;
        }
        char mn = 'z';
        for (int j = 1; j <= n; j++) {
            int k = i + 1 - j;
            if (k < 1 || k > n || !vis[j][k]) continue;
            mn = min(mn, s[j][k]);
        }
        putchar(mn);
        for (int j = 1; j <= n; j++) {
            int k = i + 1 - j;
            if (k < 1 || k > n || !vis[j][k]) continue;
            if (s[j][k] != mn) vis[j][k] = 0;
        }
    }
    return 0;
}