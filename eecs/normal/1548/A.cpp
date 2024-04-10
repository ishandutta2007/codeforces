#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, q, ans, cnt[maxn];

int main() {
    scanf("%d %d", &n, &m), ans = n;
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        if (!cnt[u]++) ans--;
    }
    scanf("%d", &q);
    while (q--) {
        int op, u, v;
        scanf("%d", &op);
        if (op < 3) scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        if (op == 1) {
            if (!cnt[u]++) ans--;
        } else if (op == 2) {
            if (!--cnt[u]) ans++;
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}