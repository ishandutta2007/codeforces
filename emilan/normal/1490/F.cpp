#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    map<int, int> mf;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mf[x]++;
    }
    vt<int> f;
    for (auto &p : mf) f.push_back(p.se);
    sort(all(f));
    int m = sz(f);

    int p = 0, ans = n;
    for (int i = 1; i <= n; i++) {
        for (; p < m && f[p] < i; p++);
        ans = min(n - (m - p) * i, ans);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}