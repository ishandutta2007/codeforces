#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    int n0 = n;

    vector<int> ans;
    for (; n >= 7; n -= 4) {
        ans.push_back(n);
        ans.push_back(n | (0b01 << 29));
        ans.push_back(n | (0b11 << 29));
        ans.push_back(n | (0b10 << 29));
    }

    if (n == 3) {
        ans.push_back(0b01 << 20);
        ans.push_back(0b11 << 20);
        ans.push_back(0b10 << 20);
    } else if (n == 4) {
        ans.push_back(0);
        ans.push_back(0b01 << 20);
        ans.push_back(0b11 << 20);
        ans.push_back(0b10 << 20);
    } else if (n == 5) {
        ans.push_back(0);
        ans.push_back(0b0011 << 20);
        ans.push_back(0b0110 << 20);
        ans.push_back(0b1100 << 20);
        ans.push_back(0b1001 << 20);
    } else {
        ans.push_back(0b0001 << 20);
        ans.push_back(0b0011 << 20);
        ans.push_back(0b0010 << 20);
        ans.push_back(0b0100 << 20);
        ans.push_back(0b1100 << 20);
        ans.push_back(0b1000 << 20);
    }

    for (int i = 0; i < n0; i++) {
        cout << ans[i] << " \n"[i == n0 - 1];
    }
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