#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        LL ans = 0;
        multiset<int> s;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            ans += a / k;
            s.insert(a % k);
        }
        while (not s.empty()) {
            int u = *s.begin();
            s.erase(s.begin());
            auto it = s.lower_bound(k - u);
            if (it != s.end()) {
                s.erase(it);
                ans += 1;
            }
            else s.erase(s.begin());
        }
        cout << ans << "\n";
    }
    return 0;   
}