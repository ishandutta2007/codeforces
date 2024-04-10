#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        int ans = 0;
        set<int> s;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            ans += s.count(a);
            s.insert(a);
        }
        cout << n - (ans + 1) / 2 * 2 << "\n";
    }
}