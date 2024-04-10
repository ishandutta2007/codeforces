#include <bits/stdc++.h>

using namespace std;

constexpr int kA = 1.5e7 + 1;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int g = accumulate(a.begin(), a.end(), a[0], gcd<int, int>);
    array<int, kA> f = {};
    for (int x : a) f[x / g]++;

    int ans = n;
    bitset<kA> composite = {};
    for (int i = 2; i < kA; i++) if (!composite[i]) {
        int cur = n;
        for (int j = i; j < kA; j += i) {
            composite[j] = true;
            cur -= f[j];
        }
        ans = min(ans, cur);
    }
    if (ans == n) cout << -1;
    else cout << ans;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}