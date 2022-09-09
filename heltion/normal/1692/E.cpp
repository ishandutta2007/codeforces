#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        if (reduce(a.begin(), a.end(), 0) < s) {
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        for (int i = 0, j = 0, sum = 0; i < n; i += 1) {
            while (j < n and sum + a[j] <= s) {
                sum += a[j];
                j += 1;
            }
            ans = max(ans, j - i);
            sum -= a[i];
        }
        cout << n - ans << "\n";
    }
}