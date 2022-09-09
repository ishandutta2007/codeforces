#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (auto& si : s) cin >> si;
        vector<int> b(4, -n - m);
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j < m; j += 1)
                if (s[i][j] == 'B') {
                    b[0] = max(b[0], i + j);
                    b[1] = max(b[1], i - j);
                    b[2] = max(b[2], -i + j);
                    b[3] = max(b[3], -i - j);
                }
        auto f = [&](int i, int j) {
            return max({
                b[0] - i - j,
                b[1] - i + j,
                b[2] + i - j,
                b[3] + i + j
            });
        };
        int x = 0, y = 0;
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j < m; j += 1)
                if (f(i, j) < f(x, y))
                    tie(x, y) = make_pair(i, j);
        cout << x + 1 << " " << y + 1 << "\n";
    }
    return 0;
}