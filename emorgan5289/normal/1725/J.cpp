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

const int N = 1e5+5;

struct my_hash {
    size_t operator()(array<int, 2> x) const {
        return size_t(x[0]) * N + x[1];
    }
};

int n;
vector<int> adj[N];
multiset<ll> dp[N], c[N];
unordered_map<array<int, 2>, ll, my_hash> m, w;
ll ans = 0;

void erase_one(auto& x, auto y) {
    x.erase(x.find(y));
}

ll get_best(int j) {
    if (dp[j].size() > 1)
        return max(*--c[j].end(), *--dp[j].end() + *----dp[j].end());
    return max(*--c[j].end(), *--dp[j].end());
}

void build(int i, int k) {
    for (int j : adj[i]) {
        if (j == k) continue;
        build(j, i);
        dp[i].insert(w[{i, j}]+*--dp[j].end());
        c[i].insert(get_best(j));
    }
}

void reroot(int i, int j) {
    erase_one(dp[i], w[{i, j}]+*--dp[j].end());
    erase_one(c[i], get_best(j));
    dp[j].insert(w[{i, j}]+*--dp[i].end());
    c[j].insert(get_best(i));
}

void dfs(int i, int k) {
    if (dp[i].size() > 3)
        ans = max(ans, *--dp[i].end() + *----dp[i].end() + *------dp[i].end() + *--------dp[i].end()); // lol
    for (int j : adj[i]) {
        m[{i, j}] = get_best(j);
        if (j == k) continue;
        reroot(i, j);
        dfs(j, i);
        reroot(j, i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        ll z; cin >> z;
        adj[x].pb(y), adj[y].pb(x);
        w[{x, y}] = w[{y, x}] = z;
        sum += 2*z;
    }
    for (int i = 0; i < n; i++) {
        dp[i].insert(0);
        c[i].insert(0);
    }
    build(0, 0);
    dfs(0, 0);
    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            if (i < j)
                ans = max(ans, 2*w[{i, j}] + m[{i, j}] + m[{j, i}]);
    cout << sum-ans << "\n";
}