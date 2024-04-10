#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 65;
int R, C;
ll mn = LLONG_MAX, ans, binom[maxn][maxn], coef[maxn][maxn], f[maxn], g[maxn];
map<ll, int> mp[22];
set<ll> S[22];
char str[maxn];

int main() {
    scanf("%d %d %s", &R, &C, str + 1);
    for (int i = 0; i <= 2 * (R + C); i++) {
        for (int j = binom[i][0] = 1; j <= i; j++) {
            binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
    }
    for (int i = 1; i <= R + C; i++) {
        for (int j = 0; j <= R + C; j++) {
            coef[i][j] = binom[i - 1][R - 1] * binom[j][R];
        }
    }
    for (int i = 0, st = 2 * R + C; i < 1 << (C + 1); i++) {
        ll ans = 0;
        bool flag = 1;
        for (int j = 0, k = R + C - __builtin_popcount(i); j <= C; j++) {
            if (str[st + j] != '?' && (i >> j & 1) ^ (str[st + j] == 'A')) flag = 0;
            if (i >> j & 1) k++, ans += coef[k][st + j - k];
            else ans -= coef[st + j - k][k];
        }
        S[__builtin_popcount(i)].insert(ans);
        if (flag) mp[__builtin_popcount(i)][ans]++;
    }
    for (int i = 1; i <= C + 1; i++) {
        int cntA = 0, cntB = 0;
        for (int j = 1; j <= i + 2 * R - 2; j++) {
            cntA += (str[j] == 'A'), cntB += (str[j] == 'B');
        }
        if (cntA <= R - 1 + i && cntB <= R - 1) {
            f[i] = binom[i + 2 * R - 2 - cntA - cntB][R - 1 - cntB];
        }
        if (cntA <= R - 1 && cntB <= R - 1 + i) {
            g[i] = binom[i + 2 * R - 2 - cntA - cntB][R - 1 - cntA];
        }
    }
    for (int i = 0, st = 2 * R - 1; i < 1 << (C + 1); i++) {
        bool same = 1, flag = 1;
        int cnt = 1;
        for (int j = 1; j <= C; j++) {
            if ((i >> (j - 1) & 1) ^ (i >> j & 1)) same = 0;
            if (same) cnt++;
            if (!same && str[st + j] ^ '?' && (i >> j & 1) ^ (str[st + j] == 'A')) flag = 0;
        }
        ll s = 0;
        for (int j = 0, k = R - 1; j <= C; j++) {
            if (i >> j & 1) k++, s += coef[k][j + st - k];
            else s -= coef[j + st - k][k];
        }
        int id = C + 1 - __builtin_popcount(i);
        auto it = S[id].lower_bound(-s);
        if (it != S[id].end()) {
            if (mn > abs(*it + s)) mn = abs(*it + s), ans = 0;
            if (flag && mn == abs(*it + s)) ans += 1LL * mp[id][*it] * (i & 1 ? f[cnt] : g[cnt]);
        }
        if (it != S[id].begin()) {
            if (mn > abs(*--it + s)) mn = abs(*it + s), ans = 0;
            if (flag && mn == abs(*it + s)) ans += 1LL * mp[id][*it] * (i & 1 ? f[cnt] : g[cnt]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}