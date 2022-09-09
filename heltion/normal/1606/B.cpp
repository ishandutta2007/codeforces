#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, k, cur = 1, ans = 0;
        cin >> n >> k;
        while (n > cur and k >= cur) {
            cur *= 2;
            ans += 1;
        }
        cout << ans + (n - cur + k - 1) / k << "\n";
    }
    return 0;
}