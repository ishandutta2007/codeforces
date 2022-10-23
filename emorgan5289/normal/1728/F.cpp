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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct splitmix64 {
    size_t operator()(long long x) const {
        static const size_t fixed = chrono::steady_clock::now().time_since_epoch().count();
        x += 0x9e3779b97f4a7c15 + fixed;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
};

gp_hash_table<int, int, splitmix64> b;
gp_hash_table<int, pair<ll, int>, splitmix64> dp;

pair<ll, int> dfs(int i) {
    dp[i] = {inf, inf};
    pair<ll, int> ans = {inf, inf};
    for (int j = i; 1; j += i) {
        if (b.find(j) != b.end()) {
            int k = b[j];
            if (k == i)
                continue;
            pair<ll, int> v;
            if (dp.find(k) == dp.end())
                v = dfs(k);
            else v = dp[k];
            v.second = j;
            cmin(ans, v);
        } else {
            cmin(ans, make_pair(ll(j), j));
            break;
        }
    }
    return dp[i] = ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a), greater<>());
    ll ans = 0;
    for (int x : a) {
        dp.clear();
        dfs(x);
        debug(x);
        debug(b);
        debug(dp);
        while (b.find(dp[x].second) != b.end())
            swap(x, b[dp[x].second]);
        b[dp[x].second] = x;
        ans += dp[x].second;
    }
    cout << ans << "\n";
}