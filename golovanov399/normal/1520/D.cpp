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
    map<int, int> M;
    for (int i = 0; i < n; ++i) {
        M[nxt() - i] += 1;
    }
    long long ans = 0;
    for (auto [_, v] : M) {
        ans += 1ll * v * (v - 1) / 2;
    }
    cout << ans << "\n";
}

int main() {
    int t = nxt();
    while (t--) {
        solve();
    }

    return 0;
}