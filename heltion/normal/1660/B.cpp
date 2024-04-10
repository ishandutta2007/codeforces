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
        ranges::sort(a);
        if (n == 1) cout << (a[0] == 1 ? "YES\n" : "NO\n");
        else cout << (a[n - 1] - a[n - 2] <= 1 ? "YES\n" : "NO\n");
    }
    return 0;
}