#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int x, y;
        cin >> x >> y;
        if (y % x) cout << "0 0\n";
        else cout << "1 " << y / x << "\n";
    }
}