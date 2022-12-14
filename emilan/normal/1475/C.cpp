#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    vector<int> p_l(k);
    for (auto &x : p_l) cin >> x;
    vector<int> p_r(k);
    for (auto &x : p_r) cin >> x;

    ll ans = 0;
    map<int, int> freq_l;
    map<int, int> freq_r;
    map<pii, int> freq_lr;
    for (int i = 0; i < k; i++) {
        auto &lr = freq_lr[pair{p_l[i], p_r[i]}];
        ans += i - freq_l[p_l[i]] - freq_r[p_r[i]] + lr;
        freq_l[p_l[i]]++;
        freq_r[p_r[i]]++;
        lr++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}