#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n), used(n);
        for (int& ai : a) {
            cin >> ai;
            while (ai > n) ai /= 2;
        }
        int ok = 1;
        for (int i = n; i >= 1; i -= 1) {
            int k = -1;
            for (int j = 0; j < n; j += 1) if (not used[j] and a[j] == i) {
                k = j;
            }
            if (k == -1) {
                ok = 0;
                break;
            }
            used[k] = 1;
            for (int& ai : a) if (ai >= i) ai /= 2;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}