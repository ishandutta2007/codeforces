#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, n, m; cin >> k >> n >> m;
    vector<ll> a(k), a_tmp(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a_tmp[i] = a[i];
    }
    vector<array<ll, 3>> b(n);
    vector<array<ll, 2>> upd(k);
    vector<vector<array<ll, 2>>> pre_add(k);
    vector<pair<ld, int>> mul;
    vector<vector<pair<ld, int>>> add(k);
    for (int i = 0; i < n; i++) {
        cin >> b[i][0] >> b[i][1] >> b[i][2]; b[i][1]--;
        if (b[i][0] == 1) {
            array<ll, 2> tmp = {b[i][2], i};
            cmax(upd[b[i][1]], tmp);
        }
        if (b[i][0] == 2)
            pre_add[b[i][1]].pb({b[i][2], i});
        if (b[i][0] == 3)
            mul.pb({b[i][2], i});
    }
    for (int i = 0; i < k; i++) {
        if (upd[i][0] > 0) {
            pre_add[i].pb({upd[i][0]-a[i], upd[i][1]});
        }
        sort(all(pre_add[i]), greater<>());
        for (auto& [x, j] : pre_add[i]) {
            mul.pb({1+ld(x)/a_tmp[i], j});
            a_tmp[i] += x;
        }
    }
    sort(all(mul), greater<>());
    debug(mul);
    while (mul.size() > m) mul.pop_back();
    debug(mul);
    vector<int> ans;
    for (auto& [x, i] : mul)
        if (x > 1) ans.pb(i);
    sort(all(ans), [&](int i, int j){
        return b[i][0] < b[j][0];
    });
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i+1 << " ";
    cout << "\n";
}