#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int t;
int n, k;
int a[200010], b[200010], pos[200010];
int qwq[200010];
int lst[200010], nxt[200010];
inline void rmain() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), pos[a[i]] = i, qwq[i] = 0;
    for (int i = 1; i <= k; i++) scanf("%d", b + i), qwq[b[i]] = 1;
    for (int i = 0; i <= n; i++) nxt[i] = i + 1, lst[i + 1] = i, a[i] = qwq[a[i]];
    int ans = 1;
    for (int i = 1; i <= k; i++) {
        int cur = pos[b[i]], qwq = 0;
        if (lst[cur] != 0 && a[lst[cur]] == 0) qwq++;
        if (nxt[cur] != n + 1 && a[nxt[cur]] == 0) qwq++;
        ans = ans * qwq % mod;
        nxt[lst[cur]] = nxt[cur];
        lst[nxt[cur]] = lst[cur];
    }
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &t);
    while (t--) rmain();
}