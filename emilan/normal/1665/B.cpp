#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

int ceil_div(int x, int d) {
    return (x + d - 1) / d;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    map<int, int> freq;
    for (int x : a) freq[x]++;

    int most = a[0];
    for (auto [x, f] : freq) {
        if (freq[most] < f) most = x;
    }

    int f = freq[most];
    int ans = (n - f) + __lg(2 * ceil_div(n, f) - 1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}