#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> idx(n + 1);
    for (int i = 0; i < n; i++) idx[a[i]].push_back(i);

    ll ans = 0;
    ll comp_sum = 0;
    vector<int> d(n);
    for (int x = 1; x <= n; x++) {
        for (int i : idx[x]) {
            comp_sum += x - d[i];
            if (i > 0) d[i - 1] += x;
            if (i < n - 1) d[i + 1] += x;
        }
        ans += comp_sum;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}