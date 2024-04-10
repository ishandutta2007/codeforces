#include <bits/stdc++.h>
using namespace std;
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
        int i = ranges::max_element(b) - b.begin();
        if (b[i] == 0) cout << "YES\n";
        else {
            int d = a[i] - b[i];
            if (d < 0) cout << "NO\n";
            else {
                int ok = 1;
                for (int j = 0; j < n; j += 1)
                    if (max(a[j] - d, 0) != b[j])
                        ok = 0;
                cout << (ok ? "YES\n" : "NO\n");
            }
        }
    }
    return 0;   
}