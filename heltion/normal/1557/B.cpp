#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        set<int> s;
        for (int & x : v) {
            cin >> x;
            s.insert(x);
        }
        for (int i = 0; i + 1 < n; i += 1)
            k -= s.upper_bound(v[i]) == s.end() or *s.upper_bound(v[i]) != v[i + 1];
        cout << (k <= 0 ? "No" : "Yes") << "\n";
    }
    return 0;
}