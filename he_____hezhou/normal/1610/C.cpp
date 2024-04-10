#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010], b[200010];
inline int check(int x) {
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (cur <= b[i] && x - cur - 1 <= a[i]) cur++;
    }
    return cur >= x;
}
inline void rmain() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    int ans = 0, l = 1, r = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
}
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) rmain();
}