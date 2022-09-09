#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int c[5][5] = {}, s[5] = {};
        int n;
        cin >> n;
        for (int i = 0; i < n; i += 1) {
            vector<int> v(5);
            for (int& x : v) cin >> x;
            for (int j = 0; j < 5; j += 1) {
                s[j] += v[j];
                for (int k = j + 1; k < 5; k += 1) {
                    c[j][k] += v[j] * v[k];
                }
            }
        }
        int ok = 0;
        for (int i = 0; i < 5; i += 1)
            for (int j = i + 1; j < 5; j += 1)
                if (s[i] + s[j] - c[i][j] >= n and s[i] >= n / 2 and s[j] >= n / 2)
                    ok = 1;
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}