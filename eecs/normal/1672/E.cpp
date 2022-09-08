#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    auto ask = [&](int x) {
        cout << "? " << x << endl;
        return cin >> x, x;
    };
    int n;
    cin >> n;
    int l = 1, r = 5e6, p;
    while (l <= r) {
        int mid = (l + r) / 2;
        ask(mid) == 1 ? r = (p = mid) - 1 : l = mid + 1;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int w = p / i, h = ask(w);
        if (h) ans = min(ans, h * w);
    }
    cout << "! " << ans << endl;
    return 0;
}