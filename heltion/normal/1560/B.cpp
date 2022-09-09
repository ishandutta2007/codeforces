#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        int n = (b - a) * 2;
        if (b > n or c > n) cout << "-1\n";
        else cout << (c > n / 2 ? c - n / 2 : c + n / 2) << "\n";
    }
    return 0;
}