#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> c(10);
        for (int i = 0, b, d; i < n; i += 1) {
            cin >> b >> d;
            c[d - 1] = max(c[d - 1], b);
        }
        if (ranges::count(c, 0)) cout << "MOREPROBLEMS\n";
        else cout << reduce(c.begin(), c.end(), 0LL) << "\n";
    }
}