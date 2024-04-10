#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        LL sum = 0, ok = 1;
        for (int i = 0; i < n; i += 1) {
            sum += a[i];
            if (sum < 0) ok = 0;
            else if (sum == 0) {
                for (int j = i + 1; j < n; j += 1)
                    if (a[j]) ok = 0;
                break;
            }
        }
        if (sum) ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
    }
}