#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int a, b;
        cin >> a >> b;
        if (a) cout << a + 2 * b + 1 << "\n";
        else cout << "1\n";
    }
    return 0;
}