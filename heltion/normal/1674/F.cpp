#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q, s = 0;
    cin >> n >> m >> q;
    vector<int> bit(n * m), a(n * m);
    auto add = [&](int x, int y) {
        for (x += 1; x <= n * m; x += x & -x)
            bit[x - 1] += y;
    };
    auto sum = [&](int x) {
        int y = 0;
        for (x += 1; x; x -= x & -x)
            y += bit[x - 1];
        return y;
    };
    for (int i = 0; i < n; i += 1) {
        string t;
        cin >> t;
        for (int j = 0; j < m; j += 1)
            if (t[j] == '*') {
                s += a[j * n + i] = 1;
                add(j * n + i, 1);
            }
    }
    for (int i = 0, x, y; i < q; i += 1) {
        cin >> x >> y;
        int j = (y - 1) * n + x - 1;
        if (a[j]) {
            s -= 1;
            add(j, -1);
            a[j] = 0;
        }
        else {
            s += 1;
            add(j, 1);
            a[j] = 1;
        }
        cout << s - sum(s - 1) << "\n";
    }
}