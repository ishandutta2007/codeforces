#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL l, r, a;
        cin >> l >> r >> a;
        LL ans = r / a + r % a;
        if (r / a * a - 1 >= l)
            ans = max(ans, r / a - 1 + a - 1);
        cout << ans << "\n";
    }
    return 0;
}