#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, a, ans = (1 << 30) - 1;
        for (cin >> n; n; n -= 1) {
            cin >> a;
            ans &= a;
        }
        cout << ans << "\n";
    }
    return 0;
}