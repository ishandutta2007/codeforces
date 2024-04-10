#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    vector<pair<int, int>> p(n * n);
    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < n; j += 1) {
            cin >> a[i][j];
            a[i][j] -= 1;
            p[a[i][j]] = {i, j};
        }
    vector<int> r(n, n), c(n, n);
    LL zero = 0;
    for (int i = 0; i < n * n; i += 1) {
        auto [x, y] = p[i];
        r[x] -= 1;
        c[y] -= 1;
        zero += r[x] * c[y];
    }
    cout << ((LL)n * (n - 1) / 2) * ((LL)n * (n - 1) / 2) * 2 - zero << "\n";
}