#include <bits/stdc++.h>

using namespace std;

const int kA = 2e5 + 5;
const int kK = 20;
array<array<int, kK>, kA> bit_pre;

void solve() {
    int l, r;
    cin >> l >> r;

    int ans = 0;
    for (int k = 0; k < kK; k++) {
        ans = max(ans, bit_pre[r + 1][k] - bit_pre[l][k]);
    }
    cout << r - l + 1 - ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < kA - 1; i++) {
        for (int k = 0; k < kK; k++) {
            bit_pre[i + 1][k] = bit_pre[i][k] + (i >> k & 1);
        }
    }

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}