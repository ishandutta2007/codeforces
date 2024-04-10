#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, p, mx, cnt[1 << 15], id[60], tmp[15];
char s[60];
long long ans, a[maxn];
mt19937 rnd(time(0));

int main() {
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') a[i] |= 1LL << j;
        }
    }
    double st = clock();
    while ((clock() - st) / CLOCKS_PER_SEC < 2.5) {
        int s = rnd() % n + 1, tot = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(id, -1, sizeof(id));
        for (int i = 0; i < m; i++) {
            if (a[s] >> i & 1) tmp[tot] = i, id[i] = tot++;
        }
        for (int i = 1; i <= n; i++) {
            int x = 0;
            for (int j = 0; j < m; j++) if (a[i] >> j & 1) {
                if (~id[j]) x |= 1 << id[j];
            }
            cnt[x]++;
        }
        for (int i = 0; i < tot; i++) {
            for (int j = 0; j < 1 << tot; j++) {
                if (j >> i & 1) cnt[j ^ (1 << i)] += cnt[j];
            }
        }
        for (int i = 0; i < 1 << tot; i++) if (cnt[i] >= (n + 1) / 2) {
            if (__builtin_popcount(i) > mx) {
                mx = __builtin_popcount(i), ans = 0;
                for (int j = 0; j < tot; j++) {
                    if (i >> j & 1) ans |= 1LL << tmp[j];
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (ans >> i & 1) putchar('1');
        else putchar('0');
    }
    return 0;
}