#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, tmp[11][11], num[maxn][11][11];
char s[maxn];
long long ans;

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 0; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= j; k++) tmp[i][j] += i + k;
            tmp[i][j] %= 11;
        }
    }
    auto calc = [&](int x) { return x & 1 ? 10 : 1; };
    for (int i = n; i; i--) {
        for (int a = 0; a <= 10; a++) {
            for (int b = 0; b <= 10; b++) {
                int rk = a, all = b;
                for (int j = i; j <= n; j++) {
                    if (s[j] - '0' >= (all + rk) % 11) break;
                    if (j == i + 2) { num[i][a][b] += num[j][rk][all]; break; }
                    rk = (s[j] - '0' + 1 + tmp[all][(rk + 10) % 11]) % 11;
                    num[i][a][b]++, (all += calc(j - i)) %= 11;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) if (s[i] != '0') {
        ans++;
        int rk = s[i] - '0', j = i + 1;
        if (i == n || s[j] - '0' >= rk) continue;
        rk = (s[j] - '0' + 1 + tmp[0][(rk + 10) % 11]) % 11;
        ans += num[i + 2][rk][9] + 1;
    }
    printf("%lld\n", ans);
    return 0;
}