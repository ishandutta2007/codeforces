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
        vector<int> a(n), b(n);
        for (int& ai : a) cin >> ai;
        for (int& bi : b) cin >> bi;
        for (int i = 0, j = 0; i < n; i += 1) {
            while (b[j] < a[i]) j += 1;
            cout << b[j] - a[i] << " ";
        }
        cout << "\n";
        vector<int> c(n);
        for (int i = n - 1, j = n - 1; i >= 0; i -= 1) {
            c[i] = b[j] - a[i];
            if (i and a[i] > b[i - 1])
                j = i - 1;
        }
        for (int ci : c) cout << ci << " ";
        cout << "\n";
    }
}