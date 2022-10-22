#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(int n) {
    int d = 2;
    while (d * d <= n) {
        if (n % d == 0) return 0;
        ++d;
    }
    return 1;
}

void solve() {
    int a, b;
    cin >> a >> b;

    if (b + 1 != a) {
        cout << "NO\n";
        return;
    }   

    int n = a * 2 - 1;
    if (check(n)) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) solve();

    return 0;
}