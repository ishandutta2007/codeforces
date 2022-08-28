#include <bits/stdc++.h>
using namespace std;
int T;
const int m = 1000000;
int np[1000010], prime[200010], cnt;
int n, e, a[200010];
inline void rmain() {
    scanf("%d%d", &n, &e);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (a[i] == 1) a[i] = 0;
        else if (np[a[i]]) a[i] = 2;
        else a[i] = 1;
    }
    int lst = 0;
    long long ans = 0;
    vector < pair < int, int > > qwq;
    for (int i = 1; i <= e; i++) {
        qwq.clear();
        for (int l = i, r; l <= n; l = r + e) {
            int cnt = 1;
            for (r = l; r + e <= n && a[r + e] == 0 && a[l] == 0; r += e) cnt++;
            qwq.push_back({a[l], cnt});
        }
        for (int i = 0; i < qwq.size(); i++) if (qwq[i].first == 1) {
            int l, r;
            if (i == 0 || qwq[i - 1].first != 0) l = 1;
            else l = qwq[i - 1].second + 1;
            if (i == qwq.size() - 1 || qwq[i + 1].first != 0) r = 1;
            else r = qwq[i + 1].second + 1;
            ans += 1ll * l * r - 1;
        }
    }
    printf("%lld\n", ans);
    
}
int main() {
    for (int i = 2; i <= m; i++) {
        if (!np[i]) prime[++cnt] = i;
        for (int j = 1; prime[j] * i <= m; j++) {
            np[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    scanf("%d", &T);
    while (T--) rmain();
}