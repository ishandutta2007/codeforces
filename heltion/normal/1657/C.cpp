#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        int x = 0, y = 0;
        while (y < n) {
            if (y + 1 == n) break;
            if (s[y] == '(') {
                x += 1;
                y += 2;
                continue;
            }
            int z = y + 1;
            while (z < n and s[z] != ')') z += 1;
            if (z == n) break;
            x += 1;
            y = z + 1;
        }
        cout << x << " " << n - y << "\n";
    }
    return 0;
}