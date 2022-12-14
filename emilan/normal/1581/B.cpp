#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool solve() {
    int n, m, k;
    cin >> n >> m >> k;

    ll M = n * ll(n - 1) / 2;
    if (m < n - 1 || m > M) return false;

    if (n == 1) return 0 < k - 1;
    else if (m == M) return 1 < k - 1;
    else return 2 < k - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << (solve() ? "yEs" : "nO") << '\n';
    }
}