#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector <int> v(k);
    for (int i = 0; i < k; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < k; ++i) {
        if (!i) {
            ans = max(ans, v[i]);
        }
        if (i == k - 1) {
            ans = max(ans, n - v[i] + 1);
        }
        else {
            int dist = v[i + 1] - v[i] - 1;
            ans = max(ans, (dist + 1) / 2 + 1);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}