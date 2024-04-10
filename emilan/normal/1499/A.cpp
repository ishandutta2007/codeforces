#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b, x, y;
        cin >> n >> a >> b >> x >> y;
        if (x <= (a + b) / 2 && y <= (n * 2 - a - b) / 2) cout << "yEs";
        else cout << "nO";
        cout << '\n';
    }
}