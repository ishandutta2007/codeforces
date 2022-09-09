#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        for (int i = 0, a; i < m; i += 1) {
            cin >> a;
            mp[a] += 1;
        }
        int L = 0, R = 2 * m;
        while (L < R) {
            int M = (L + R) >> 1;
            LL k = M / 2LL * (n - mp.size());
            for (auto [x, y] : mp) {
                if (y > M) k += M;
                else k += y + (M - y) / 2;
            }
            if (k >= m) R = M;
            else L = M + 1;
        }
        cout << L << "\n";
    }
}