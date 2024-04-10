#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int a, b, c;
        cin >> a >> b >> c;
        int ok = 0;
        if ((2 * b - c) % a ==  0 and (2 * b - c) / a >= 1) ok = 1;
        if ((2 * b - a) % c ==  0 and (2 * b - a) / c >= 1) ok = 1;
        if ((a + c) % (2 * b) == 0) ok = 1;
        cout << (ok ? "YES\n" : "NO\n");
    }
}