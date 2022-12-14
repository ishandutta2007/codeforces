#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve() {
    ll k, n, a, b;
    cin >> k >> n >> a >> b;

    ll num = k - b * n - 1;
    if (num < 0) return -1;
    return min(num / (a - b), n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << "\n";
    }
}