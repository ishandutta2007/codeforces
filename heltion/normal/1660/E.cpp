#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, c = 0;
        cin >> n;
        vector<int> vc(n);
        for (int i = 0; i < n; i += 1) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j += 1) {
                vc[(i + n - j) % n] += s[j] - '0';
                c += s[j] - '0';
            }
        }
        cout << n + c - 2 * ranges::max(vc) << "\n";
    }
    return 0;
}