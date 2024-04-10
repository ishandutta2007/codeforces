#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
map<ll, ll, greater<ll>> mp, ans;

int main() {
    scanf("%lld %lld", &n, &k);
    if (k == 1) puts("1"), exit(0);
    if (k == 2) printf("%lld\n", n), exit(0);
    k -= 2;
    auto solve = [&](ll n) {
        mp.clear(), ans.clear();
        if (n) mp[n] = 1;
        while (!mp.empty()) {
            auto p = *mp.begin(); mp.erase(mp.begin());
            ans[(p.first + 1) / 2] += p.second;
            ll r = p.first / 2, l = p.first - r - 1;
            if (l) mp[l] += p.second;
            if (r) mp[r] += p.second;
        }
    };
    ll l = 1, r = n, v;
    solve(n - 2);
    for (auto p : ans) {
        if (p.second >= k) { v = p.first; break; }
        k -= p.second;
    }
    while (1) {
        ll mid = (l + r) >> 1;
        if ((r - l) >> 1 == v && !--k) { printf("%lld\n", mid); break; }
        solve(mid - l - 1);
        if (ans[v] >= k) r = mid;
        else l = mid, k -= ans[v];
    }
    return 0;
}