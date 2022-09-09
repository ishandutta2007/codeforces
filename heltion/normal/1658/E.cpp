#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector v(n, vector<int>(n));
    vector g(n, string(n, 'G'));
    vector<pair<int, int>> vp(n * n + 1);
    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < n; j += 1) {
            cin >> v[i][j];
            vp[v[i][j]] = {i, j};
        }
    int xL = INT_MIN, xR = INT_MAX, yL = xL, yR = xR;
    for (int i = n * n; i >= 1; i -= 1) {
        auto [tx, ty] = vp[i];
        auto [x, y] = pair(tx - ty, tx + ty);
        //cout << i << " " << tx << " " << ty << " " << x << " " << y << "\n";
        if (x >= xL and x <= xR and y >= yL and y <= yR) {
            g[tx][ty] = 'M';
            xL = max(xL, x - k);
            xR = min(xR, x + k);
            yL = max(yL, y - k);
            yR = min(yR, y + k);
        }
    }
    for (auto gi : g) cout << gi << "\n";
    return 0;
}