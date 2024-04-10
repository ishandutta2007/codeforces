#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, q, tot, a[maxn], mu[maxn], vis[maxn], p[maxn], cur[maxn], num[maxn];
vector<int> d[maxn];

int main() {
    scanf("%d %d", &n, &q), mu[1] = 1;
    for (int i = 2; i <= 500000; i++) {
        if (!vis[i]) p[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot && i * p[j] <= 500000; j++) {
            vis[i * p[j]] = 1;
            if (i % p[j]) mu[i * p[j]] = -mu[i];
            else break;
        }
    }
    for (int i = 1; i <= 500000; i++) if (mu[i]) {
        for (int j = i; j <= 500000; j += i) d[j].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    long long ans = 0;
    while (q--) {
        int t; scanf("%d", &t);
        int x = a[t];
        if (cur[t]) {
            for (int i : d[x]) ans -= mu[i] * --num[i];
        } else {
            for (int i : d[x]) ans += mu[i] * num[i]++;
        }
        printf("%lld\n", ans), cur[t] ^= 1;
    }
    return 0;
}