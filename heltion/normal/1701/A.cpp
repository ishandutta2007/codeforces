#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int s = 0;
        for (int i = 0, a; i < 4; i += 1) {
            cin >> a;
            s += a;
        }
        if (not s) cout << "0\n";
        else if (s < 4) cout << "1\n";
        else cout << "2\n";
    }
}