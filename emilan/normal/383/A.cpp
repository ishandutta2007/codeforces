#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> pre_l(n + 1);
    for (int i = 0; i < n; i++) {
        pre_l[i + 1] = pre_l[i] + !a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) ans += pre_l[n] - pre_l[i + 1];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}