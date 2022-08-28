#include <bits/stdc++.h>
using namespace std;
int prime[200010], n, m = 200000, np[200010], tot, minp[200010], _min[200010], sec_min[200010], sze[200010];
int main() {
    for (int i = 2; i <= m; i++) {
        if (!np[i]) prime[++tot] = i, minp[i] = i;
        for (int j = 1; prime[j] * i <= m; j++) {
            np[i * prime[j]] = 1;
            minp[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= m; i++) _min[i] = sec_min[i] = 1e9;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        while (a > 1) {
            int now = minp[a], cnt = 0;
            while (minp[a] == now) cnt++, a /= now;
            if (cnt < sec_min[now]) sec_min[now] = cnt;
            if (sec_min[now] < _min[now]) swap(sec_min[now], _min[now]);
            sze[now]++;
        }
    }
    long long ans = 1;
    for (int i = 1; i <= m; i++) {
        if (sze[i] <= n - 2) continue;
        if (sze[i] == n - 1) {
            for (int j = 1; j <= _min[i]; j++) ans = ans * i;
        }
        else {
            for (int j = 1; j <= sec_min[i]; j++) ans = ans * i;
        }
    }
    return cout << ans << endl, 0;
}