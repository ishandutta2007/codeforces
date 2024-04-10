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
    int ans = 0;
    for (int len = 1; len <= 9; ++len) {
        for (char c = '1'; c <= '9'; ++c) {
            if (stoi(string(len, c)) <= n) {
                ++ans;
            }
        }
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