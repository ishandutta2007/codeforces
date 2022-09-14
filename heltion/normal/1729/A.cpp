#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = a - 1, y = abs(b - c) + abs(c - 1);
        if (x < y) cout << "1\n";
        else if (x > y) cout << "2\n";
        else cout << "3\n";
    }
}