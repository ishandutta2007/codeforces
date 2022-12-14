#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

bool f(int x) {
    int s = llround(sqrtl(x));
    return s * s == x;
}

void solve() {
    int n;
    cin >> n;

    if ((n % 2 == 0 && f(n / 2)) || (n % 4 == 0 && f(n / 4))) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}