#include <bits/stdc++.h>
using namespace std;
int n, T;
int a[200010], cnt[32];
inline void rmain() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int l = 1; l < n; l++) {
        int cur = 2, r = n;
        while (1) {
            if (a[l] == a[r]) {
                cur += r - l - 1;
                break;
            }
            int mid = (a[l] + a[r]) / 2;
            r = upper_bound(a + 1, a + 1 + n, mid) - a - 1;
            cur++;
        }
        ans = max(ans, cur);
    }
    cout << n - ans << endl;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) rmain();
}