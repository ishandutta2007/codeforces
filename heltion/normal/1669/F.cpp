#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, ans = 0;
        cin >> n;
        vector<int> w(n);
        for (int& wi : w) cin >> wi;
        for (int i = 0, j = n - 1, L = 0, R = 0; i <= j;) {
            L += w[i ++];
            while (R < L and j >= i)
                R += w[j --];
            if (L == R) ans = max(ans, i + n - j - 1);
        }
        cout << ans << "\n";
    }
}