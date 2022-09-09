#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        priority_queue<int> a, b;
        for (int i = 0, ai; i < n; i += 1) {
            cin >> ai;
            a.push(ai);
        }
        for (int i = 0, bi; i < n; i += 1) {
            cin >> bi;
            b.push(bi);
        }
        int ans = 0;
        auto f = [&](int n) {
            return to_string(n).size();
        };
        while (a.size()) {
            int am = a.top(); a.pop();
            int bm = b.top(); b.pop();
            if (am != bm) {
                if (am > bm) {
                    a.push(f(am));
                    b.push(bm);
                }
                else {
                    a.push(am);
                    b.push(f(bm));
                }
                ans += 1;
            }
        }
        cout << ans << "\n";
    }
}