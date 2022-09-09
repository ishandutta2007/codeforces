#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i += 1) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    vector f(m + 1, vector<int>(m + 1, n * m));
    f[0][m] = 0;
    for (int i = 1; i <= n; i += 1) {
        vector g(m + 1, vector<int>(m + 1, n * m));
        for (int j = 0; j <= m; j += 1) 
            for (int k = 0; k <= m; k += 1)
                if (f[j][k] < n * m and (m - j) <= (n - i + 1) * k) {
                    for (int x = 0; x <= k and j + x <= m; x += 1)
                        g[j + x][x] = min(g[j + x][x], f[j][k] + abs(s[i] - j - x));
                }
        f.swap(g);
    }
    cout << ranges::min(f[m]) << "\n";
}