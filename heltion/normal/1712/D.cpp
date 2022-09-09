#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        vector<pair<int, int>> vp;
        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            vp.emplace_back(a[i], i);
        }
        ranges::sort(vp);
        int inf = 1E9;
        for (int i = 0; i + 1 < k; i += 1)
            a[vp[i].second] = inf;
        int mn = min_element(a.begin() + 1, a.end()) - a.begin();
        int mx = max_element(a.begin() + 1, a.end()) - a.begin();
        int ans = min(a[mx], a[mn] * 2);
        a[mn] = inf;
        mn = min_element(a.begin() + 1, a.end()) - a.begin();
        int pans = 0;
        for (int i = 1; i < n; i += 1)
            pans = max(pans, min(a[i], a[i + 1]));
        pans = min(a[mn] * 2, pans);
        cout << max(ans, pans) << "\n";
    }
}