#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto &[b, t] : a) cin >> t >> b;
    sort(a.rbegin(), a.rend());

    priority_queue<int> pq;
    ll len = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        auto [b, t] = a[i];

        len += t;
        pq.push(-t);
        if (i >= k) {
            len += pq.top();
            pq.pop();
        }
        ans = max(len * b, ans);
    }

    cout << ans;
}