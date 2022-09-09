#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n, 2e9), v(k), t(k);
        for (int& x : v) cin >> x;
        for (int& x : t) cin >> x;
        for (int i = 0; i < k; i += 1) a[v[i] - 1] = t[i];
        for (int i = 1; i < n; i += 1) a[i] = min(a[i - 1] + 1, a[i]);
        for (int i = n - 2; i >= 0; i -= 1) a[i] = min(a[i + 1] + 1, a[i]);
        for (int x : a) cout << x << " ";
        cout << "\n";
    }
    return 0;
}