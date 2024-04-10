#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010, P = 998244353;
int n, K, ans = 1, fact[maxn], finv[maxn];
char s[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %s", &n, &K, s + 1);
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    for (int i = 1, lst = 0; i <= n; i++) {
        for (int j = i, cnt = 0; ; j++) {
            if (j > n || cnt + s[j] - '0' > K) {
                if (cnt ^ K) break;
                ans = (ans + 1LL * fact[j - i] * finv[cnt] % P * finv[j - i - cnt] % P + P - 1) % P;
                int cnt0 = 0, cnt1 = 0;
                if (lst >= i) {
                    for (int k = i; k <= lst; k++) cnt0 += s[k] == '0', cnt1 += s[k] == '1';
                    ans = (ans - 1LL * fact[cnt0 + cnt1] * finv[cnt0] % P * finv[cnt1] % P + P + 1) % P;
                }
                lst = j - 1; break;
            }
            cnt += s[j] - '0';
        }
    }
    printf("%d\n", ans);
    return 0;
}