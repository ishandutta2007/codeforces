#include <bits/stdc++.h>
using namespace std;

const int maxn = 4000010, P = 51123987;
int n, all, ans, p[maxn], pre[maxn], suf[maxn];
char s[maxn], t[maxn];

int main() {
    scanf("%d %s", &n, s + 1);
    for (int i = 1; i <= n; i++) {
        t[i * 2] = s[i], t[i * 2 + 1] = '#';
    }
    t[0] = '$', t[1] = '#', n = 2 * n + 1;
    int mx = 0, id;
    for (int i = 2; i < n; i++) {
        if (i < mx) p[i] = min(mx - i, p[2 * id - i]);
        while (t[i - p[i]] == t[i + p[i]]) p[i]++;
        if (i + p[i] > mx) mx = i + p[i], id = i;
        (all += p[i] / 2) %= P;
        if (i % 2 == 0) {
            pre[i - p[i] + 2]++, pre[i + 2]--;
            suf[i + p[i] - 2]++, suf[i - 2]--;
        } else {
            pre[i - p[i] + 2]++, pre[i + 1]--;
            suf[i + p[i] - 2]++, suf[i - 1]--;
        }
    }
    ans = 1LL * all * all % P;
    for (int i = 2; i < n; i++) {
        pre[i] += pre[i - 2];
    }
    for (int i = n; i; i--) {
        suf[i] += suf[i + 2];
    }
    for (int i = 2; i + 1 < n; i++) {
        (suf[i] += suf[i - 1]) %= P;
        ans = (ans - 2LL * suf[i] * pre[i + 1] % P + P) % P;
    }
    printf("%lld\n", 1LL * (P + 1) / 2 * (ans - all + P) % P);
    return 0;
}