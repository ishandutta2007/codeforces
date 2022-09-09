#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        int ans = 0;
        for (int i = n - 2; i >= 0; i -= 1) {
            while (a[i] and a[i] >= a[i + 1]) {
                ans += 1;
                a[i] /= 2;
            }
            if (a[i] >= a[i + 1]) {
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }
}