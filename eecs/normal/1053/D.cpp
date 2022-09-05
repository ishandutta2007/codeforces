#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, V = 2000001, P = 1000000007;
int n, ans = 1, a[maxn], ok[maxn];
int mn[V], e[V], nxt[V], cur[V], cnt[V];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 2; i < V; i++) if (!mn[i]) {
        for (int j = i; j < V; j += i) mn[j] = i;
    }
    for (int i = 2; i < V; i++) {
        nxt[i] = i;
        while (!(nxt[i] % mn[i])) e[i]++, nxt[i] /= mn[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        if (!cur[a[i]]) {
            cur[a[i]] = cnt[a[i]] = ok[i] = 1;
        } else {
            for (int j = a[i] - 1; j > 1; j = nxt[j]) {
                if (cur[mn[j]] < e[j]) cur[mn[j]] = e[j], cnt[mn[j]] = 1;
                else if (cur[mn[j]] == e[j]) cnt[mn[j]]++;
            }
        }
    }
    for (int i = 2; i < V; i++) {
        for (int j = 0; j < cur[i]; j++) ans = 1LL * i * ans % P;
    }
    auto test = [&](int p, int e) { return cnt[p] > 1 || cur[p] > e; };
    for (int i = 1; i <= n; i++) {
        if (ok[i]) {
            flag |= test(a[i], 1);
        } else {
            bool all = 1;
            for (int j = a[i] - 1; j > 1; j = nxt[j]) all &= test(mn[j], e[j]);
            flag |= all;
        }
    }
    printf("%d\n", (ans + flag) % P);
    return 0;
}