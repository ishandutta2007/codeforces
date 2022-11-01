#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> par(n);
        for (int i = 0; i < n; ++i) {
            cin >> par[i];
            --par[i];
        }
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            --p[i];
        }
        vector<bool> used(n);
        int mx = -1;
        bool can = true;
        vector<int> ans(n);
        vector<int> d(n);
        for (int x : p) {
            used[x] = true;
            if (!used[par[x]]) {
                can = false;
                break;
            }
            d[x] = ++mx;
            ans[x] = d[x] - d[par[x]];

        }
        if (!can) {
            cout << -1 << '\n';
        } else {
            for (int x : ans) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}