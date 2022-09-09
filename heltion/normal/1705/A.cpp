#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, x;
        cin >> n >> x;
        vector<int> a(2 * n);
        for (int& ai: a) cin >> ai;
        ranges::sort(a);
        int ok = 1;
        for (int i = 0; i < n; i += 1)
            if (a[i + n] < a[i] + x)
                ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
    }
}