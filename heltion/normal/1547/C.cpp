#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int k, n, m;
        cin >> k >> n >> m;
        vector<int> a(n), b(m), ans;
        for (int& x : a) cin >> x;
        for (int& x : b) cin >> x;
        for (int i = 0, j = 0; i < n or j < m;) {
            if (i < n and a[i] <= k) {
                k += a[i] == 0;
                ans.push_back(a[i ++]);
            }
            else if (j < m and b[j] <= k) {
                k += b[j] == 0;
                ans.push_back(b[j ++]);
            }
            else break;
        }
        if (ans.size() != m + n) cout << "-1\n";
        else {
            for (int x : ans) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}