#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        vector<tuple<int, int, int>> vt;
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> vp(n + 1);
        for (int i = 1, b; i <= n; i += 1) {
            //b <= i / a < b + 1
            //i / (b + 1) < a <= i / b
            cin >> b;
            vp[i / (b + 1) + 1].emplace_back(b ? i / b : n, i);
        }
        set<pair<int, int>> sp;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i += 1) {
            for (auto p : vp[i]) sp.insert(p);
            p[sp.begin()->second] = i;
            sp.erase(sp.begin());
        }
        for (int i = 1; i <= n; i += 1)
            cout << p[i] << " ";
        cout << "\n";
    }
}