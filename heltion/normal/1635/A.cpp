#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, ans = 0;
        cin >> n;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            ans |= a;
        }
        cout << ans << "\n";
    }

}