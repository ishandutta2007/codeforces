#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        cout << (a + b + c >= x + y and a + c >= x and b + c >= y ? "YES\n" : "NO\n");
    }
}