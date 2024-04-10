#include <bits/stdc++.h>
using namespace std;
int n, p[200010], c[200010];
void add(int x) {
    for (; x <= n; x += x & -x) c[x]++;
}
int query(int x) {
    int ans = 0;
    for (; x; x -= x & -x) ans += c[x];
    return ans;
}
void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        p[x] = i;
        c[i] = 0;
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        int cur;
        cur = query(p[i + 1]) - query(p[i]);
        if (p[i] > p[i + 1]) cur += i - 1;
        ans += 1ll * cur * (n - i);
        add(p[i]);
    }
    cout << ans << endl;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}