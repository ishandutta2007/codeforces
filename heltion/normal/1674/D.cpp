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
        for (int i = n - 2; i >= 0; i -= 2)
            if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
        cout << (ranges::is_sorted(a) ? "YES\n" : "NO\n");
    }
}