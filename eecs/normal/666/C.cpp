#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int m, cur, fact[maxn], finv[maxn], pw[maxn];
char s[maxn];
map<int, vector<int>> mp;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &m);
    fact[0] = finv[0] = pw[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
        pw[i] = 25LL * pw[i - 1] % P;
    }
    auto binom = [&](int n, int m) {
        return 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
    };
    auto solve = [&]() {
        int n = cur = strlen(s + 1);
        if (mp.count(n)) return;
        vector<int> ans(100001);
        for (int i = n; i <= 100000; i++) {
            ans[i] = (26LL * ans[i - 1] + binom(i - 1, n - 1) * pw[i - n]) % P;
        }
        mp[n] = ans;
    };
    scanf("%s", s + 1), solve();
    while (m--) {
        int op, n; scanf("%d", &op);
        if (op == 1) scanf("%s", s + 1), solve();
        else scanf("%d", &n), printf("%d\n", mp[cur][n]);
    }
    return 0;
}