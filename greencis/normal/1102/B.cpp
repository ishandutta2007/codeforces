#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int n, k, a[5005], b[5005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    map<int, vector<int>> mp;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(i);
        mx = max(mx, (int)mp[a[i]].size());
    }

    int idx = 0;
    for (auto& p : mp)
        for (int x : p.second)
            b[x] = idx++ % k + 1;
    if (mx > k) cout << "NO";
    else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << b[i] << " ";
    }
}