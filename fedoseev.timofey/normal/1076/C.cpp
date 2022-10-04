#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int d;
    cin >> d;
    if (d == 0) {
        cout << "Y 0 0\n";
        return;
    }
    int b = -d;
    int c = d;
    if (b * b - 4 * c < 0) {
        cout << "N\n";
        return;
    }
    ld x1 = (-b + sqrt(b * b - 4 * c)) / 2;
    ld x2 = d / x1;
    cout << "Y " << x1 << ' ' << x2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}