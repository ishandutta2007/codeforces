#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200010], cnt[200010];
void rmain() {
    scanf("%d%d", &n, &k);
    k = min(k, n);
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (a[i] > n) a[i] = mp.count(a[i]) ? mp[a[i]] : (mp[a[i]] = n + i);
    }
    for (int i = 0; i <= n + n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    int rest = k + 1, pos = n;
    for (int i = 0; i <= n + n; i++) {
        if (cnt[i] == 0 && --rest == 0) {
            pos = i;
            break;
        }
    }
    priority_queue < int, vector <int>, greater <int> > pq;
    for (int i = pos; i <= n + n; i++) if (cnt[i]) pq.push(cnt[i]);
    for (int i = 1; i <= k; i++) {
        if (pq.empty()) return puts("0"), void();
        int cur = pq.top();
        pq.pop();
        if (cur > 1) pq.push(cur - 1);
    }
    printf("%d\n", (int)pq.size());
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}