#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> mp(n + 1);
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            mp[a] += 1;
        }
        auto it = ranges::max_element(mp);
        cout << (*it >= 3 ? it - mp.begin() : -1) << "\n";
    }
}