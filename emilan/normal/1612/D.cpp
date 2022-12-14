#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool solve() {
    ll a, b, x;
    cin >> a >> b >> x;

    if (a > b) swap(a, b);
    while (a != 0 && b >= x) {
        if (b % a == x % a) return true;
        swap(a, b %= a);
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
}