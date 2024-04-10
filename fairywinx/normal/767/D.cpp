#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

bool check(vector<int> a, int k) {
    // sort(all(a));
    for (int i = 0; i < (int) a.size(); i += k) {
        if (a[i] < i / k)
            return false;
    }
    return true;
}

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    auto sort_b = b;
    sort(rall(sort_b));
    if (!check(a, k)) {
        cout << -1 << '\n';
        return 0;
    }
    int left = 0, right = m + 1;
    while (left + 1 != right) {
        int mid = (left + right) / 2;
        vector<int> tmp;
        for (int i = 0; i < mid; ++i)
            tmp.push_back(sort_b[i]);
        reverse(all(tmp));
        vector<int> z(tmp.size() + n);
        merge(all(tmp), all(a), z.begin());
        if (check(z, k)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    if (left == 0) {
        cout << 0 << '\n';
        return 0;
    }
    sort(all(a));
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        if (b[i] > sort_b[left - 1]) {
            ans.push_back(i + 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (b[i] == sort_b[left - 1] && ans.size() < left) {
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}