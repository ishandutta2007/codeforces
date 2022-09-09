#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        if ((sx - d <= 1 or sy + d >= m) and (sx + d >= n or sy - d <= 1)) cout << "-1\n";
        else cout << n + m - 2 << "\n";
    }
}