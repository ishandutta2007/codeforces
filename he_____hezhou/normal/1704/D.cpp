#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll qwq[100010];
void rmain() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        ll cur = 0;
        for (int j = 1; j <= m; j++) {
            ll x;
            scanf("%lld", &x);
            cur += x * j;
        }
        qwq[i] = cur;
    }
    qwq[0] = qwq[n], qwq[n + 1] = qwq[1];
    for (int i = 1; i <= n; i++) if (qwq[i] != qwq[i - 1] && qwq[i] != qwq[i + 1]) {
        printf("%d %lld\n", i, qwq[i] - qwq[i - 1]);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}