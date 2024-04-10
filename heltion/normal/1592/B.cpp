#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        vector<int> v;
        for (int i = 0; i < n; i += 1) if (i >= x or i + x < n) v.push_back(a[i]);
        sort(v.begin(), v.end());
        for (int i = 0, j = 0; i < n; i += 1) if (i >= x or i + x < n) a[i] = v[j ++];
        int ok = 1;
        for (int i = 1; i < n; i += 1) ok &= a[i] >= a[i - 1];
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}