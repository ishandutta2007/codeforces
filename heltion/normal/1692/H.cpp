#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        map<int, vector<int>> mp;
        for (int i = 1, a; i <= n; i += 1) {
            cin >> a;
            mp[a].push_back(i);
        }
        int a = -1, l = -1, r = -1, ans = -1;
        for (auto [x, v] : mp) {
            int mn = 0, sum = 0, mnl = v[0];
            for (int i = 0; i < v.size(); i += 1) {
                if (i) {
                    sum -= v[i] - v[i - 1] - 1;
                    if (sum < mn) {
                        mn = sum;
                        mnl = v[i];
                    }
                }
                sum += 1;
                if (sum - mn > ans) {
                    ans = sum - mn;
                    a = x;
                    l = mnl;
                    r = v[i];
                }
            }
        }
        cout << a << " " << l << " " << r << "\n";
    }
}