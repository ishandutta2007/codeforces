#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int a;
        cin >> a;
        int ans = 15;
        for (int i = 1; i <= 15; i += 1) {
            int x = a & ((1 << i) - 1);
            if (x) x = (1 << i) - x;
            ans = min(ans, x + 15 - i);
        }
        cout << ans << " ";
    }
    return 0;
}