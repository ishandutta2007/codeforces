#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int x, y;
        cin >> x >> y;
        if (x == 0 and y == 0)
            cout << "0\n";
        else {
            int ok = 0, s = x * x + y * y;
            for (int i = 0; i * i <= s; i += 1)
                if (i * i == s) ok = 1;
            cout << 2 - ok << "\n";
        }
    }
    return 0;
}