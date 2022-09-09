#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m = 0;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) {
            cin >> ai;
            if (ai < 0) {
                m += 1;
                ai = -ai;
            }
        }
        for (int i = 0; i < m; i += 1) a[i] = -a[i];
        cout << (ranges::is_sorted(a) ? "YES\n" : "NO\n");
    }
}