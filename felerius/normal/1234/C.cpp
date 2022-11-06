#include <bits/stdc++.h>

// Contest: Codeforces Round #590 (Div. 3) (https://codeforces.com/contest/1234)
// Problem: C: Pipes (https://codeforces.com/contest/1234/problem/C)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        array<vector<int>, 2> a;
        a[0].resize(n);
        a[1].resize(n);
        for (auto& ai : a[0]) {
            char c; cin >> c; ai = c - '0';
        }
        for (auto& ai : a[1]) {
            char c; cin >> c; ai = c - '0';
        }

        int x = 0, y = 0;
        bool left = true;
        while (x < n && y < 2) {
            if (a[y][x] <= 2) {
                if (left) {
                    x++;
                } else {
                    break;
                }
            } else {
                if (left) {
                    y = 1 - y;
                    left = false;
                } else {
                    x++;
                    left = true;
                }
            }
        }

        if (x == n && y == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}