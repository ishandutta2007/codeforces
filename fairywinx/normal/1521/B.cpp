#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <array>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int c = min_element(all(a)) - a.begin();
    int z = 1e9 + 7;
    vector<array<int, 4>> ans;
    if (c != 0) {
        ans.push_back({1, c + 1, a[c], a[c]});
    }
    for (int i = 1; i < n; i += 2) {
        ans.push_back({1, i + 1, a[c], z});
    }
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << ' ' << i[3] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    // cout << 1 << '\n';
}