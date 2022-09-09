#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        vector<set<int>> vs(2);
        int n;
        cin >> n;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            vs[i & 1].insert(a & 1);
        }
        if (vs[0].size() <= 1 and vs[1].size() <= 1)
            cout << "YES\n";
        else cout << "NO\n";
    }
}