#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000010, P = 1000000007;
int n, ans1, ans2 = 1, c[maxn], fact[maxn], num[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        num[1000001 - c[i]]++, num[1000001 + c[i]]--;
    }
    for (int i = fact[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
    }
    int cur = 1;
    for (int i = 0; i < maxn; i++) {
        if (i > 1) num[i] += num[i - 2];
        int coef = 1LL * (cur + cur + num[i] - 1) * num[i] / 2 % P;
        ans1 = (ans1 + 1LL * (i - 1000000 + P) * coef) % P, (cur += num[i]) %= P;
        ans2 = 1LL * ans2 * fact[num[i]] % P;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}