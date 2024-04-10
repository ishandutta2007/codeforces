#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            mp[x].push_back(i);
        }
        int ans = -1;
        for (const auto& [_, v] : mp) {
            for (int i = 0; i + 1 < (int)v.size(); ++i) {
                int diff = v[i + 1] - v[i];
                ans = max(ans, n - diff);
            }
        }
        cout << ans << '\n';
    }
}