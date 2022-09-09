#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string x, y;
        cin >> n >> x >> y;
        if (x[0] != y[0]) cout << "-1\n";
        else {
            vector<int> xw, yw;
            for (int i = 1; i < n; i += 1) {
                if (x[i] != x[i - 1]) xw.push_back(i);
                if (y[i] != y[i - 1]) yw.push_back(i);
            }
            if (xw.size() != yw.size())
                cout << "-1\n";
            else {
                LL ans = 0;
                for (int i = 0; i < xw.size(); i += 1)
                    ans += abs(xw[i] - yw[i]);
                cout << ans << "\n";
            }
        }
    }
}