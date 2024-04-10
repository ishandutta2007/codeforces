#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        LL B, x, y, a = 0, ans = 0;
        cin >> n >> B >> x >> y;
        for (int i = 1; i <= n; i += 1) {
            if (a + x <= B) a += x;
            else a -= y;
            ans += a;
        }
        cout << ans << "\n";
    }
    return 0;
}