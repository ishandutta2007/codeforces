#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int nxt() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = nxt();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    if (n == 2) {
        cout << "-1\n";
        return;
    }
    for (int off = 0; off < n; ++off) {
        for (int i = 0; i < n; ++i) {
            ans[i][(off + i) % n] = off * n + i + 1;
        }
    }
    for (auto v : ans) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t = nxt();
    while (t--) {
        solve();
    }

    return 0;
}