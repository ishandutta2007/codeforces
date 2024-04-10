#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

double get_time() {
    return 1.0 * clock() / CLOCKS_PER_SEC;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    array<vector<vector<int>>, 2> arr;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    arr[0].resize(k + 1);
    arr[0][0] = {0};
    for (int i = 0; i < n; ++i) {
        if (get_time() > 1.9) {
            cout << k + 1 << '\n';
            for (int j = 0; j <= k; ++j)
                cout << j << ' ';
            cout << '\n';
            return 0;
        }
        int z = i & 1;
        arr[z ^ 1].clear();
        arr[z ^ 1].resize(k + 1);
        for (int j = 0; j <= k; ++j) {
            sort(all(arr[z][j]));
            arr[z][j].resize(unique(all(arr[z][j])) - arr[z][j].begin());
        }

        for (int j = 0; j <= k; ++j) {
            for (auto p : arr[z][j]) {
                arr[z ^ 1][j].push_back(p);
                if (j + a[i] <= k) {
                    arr[z ^ 1][j + a[i]].push_back(p + a[i]);
                    arr[z ^ 1][j + a[i]].push_back(p);
                }
            }
        }
    }
    vector<int> tmp;
    for (int i : arr[n & 1][k])
        tmp.push_back(i);
    sort(all(tmp));
    tmp.resize(unique(all(tmp)) - tmp.begin());
    cout << tmp.size() << '\n';
    for (auto i : tmp)
        cout << i << ' ';
    cout << '\n';
}