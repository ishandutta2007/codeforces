#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010, P = 998244353;
int n, K, m, ans = 1, l[maxn], r[maxn], x[maxn], pos[maxn], tag[maxn], f[maxn];

int main() {
    scanf("%d %d %d", &n, &K, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &l[i], &r[i], &x[i]), r[i]++;
    }
    for (int b = 0; b < K; b++) {
        memset(pos, 0, sizeof(pos));
        memset(tag, 0, sizeof(tag));
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; i++) {
            if (x[i] >> b & 1) tag[l[i]]++, tag[r[i]]--;
            else pos[r[i]] = max(pos[r[i]], l[i]);
        }
        for (int i = 1; i <= n + 1; i++) {
            tag[i] += tag[i - 1], pos[i] = max(pos[i], pos[i - 1]);
        }
        int cur = 1;
        for (int i = f[0] = 1, j = 0; i <= n + 1; i++) {
            while (j < pos[i]) cur = (cur - f[j] + P) % P, f[j++] = 0;
            f[i] = tag[i] ? 0 : cur, (cur += f[i]) %= P;
        }
        ans = 1LL * ans * f[n + 1] % P;
    }
    printf("%d\n", ans);
    return 0;
}