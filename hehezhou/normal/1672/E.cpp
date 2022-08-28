#include <bits/stdc++.h>
using namespace std;
int n;
int query(int x) {
    if (x == 0) return 0;
    cout << "? " << x << endl;
    int ans;
    cin >> ans;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int l = 0, r = 4020000, ans = 4020000;
    while (l <= r) {
        int mid = l + r >> 1;
        if (query(mid) == 1) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    for (int i = 1; i <= n; i++) {
        int cur = query(ans / i);
        if (cur) ans = min(ans, ans / i * cur);
    }
    cout << "! " << ans << endl;
}