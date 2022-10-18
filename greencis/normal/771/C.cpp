#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k, x, y;
ll ans = 0;
vector<int> g[201005];
vector<pll> dp[200105]; /// DISTS/CNT

inline vector<pll> add(vector<pll> a, vector<pll> b) {
    for (size_t i = 0; i < a.size(); ++i)
        a[i].first += b[i].first, a[i].second += b[i].second;
    return a;
}

inline vector<pll> sub(vector<pll> a, vector<pll> b) {
    for (size_t i = 0; i < a.size(); ++i)
        a[i].first -= b[i].first, a[i].second -= b[i].second;
    return a;
}

inline vector<pll> shift(vector<pll> a) {
    a.insert(a.begin(), a.back());
    a[0].first += a[0].second;
    a.pop_back();
    return a;
}

vector<pll> dfs_init(int v, int p) {
    vector<pll> cur(k);
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)
            continue;
        vector<pll> nxt = dfs_init(to, v);
        cur = add(cur, nxt);
    }
    cur = shift(cur);
    ++cur[0].first;
    ++cur[0].second;
    dp[v] = cur;
    return cur;
}

void dfs(int v, int p, vector<pll> up) {
    vector<pll> cur = up, nxt;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)
            continue;
        cur = add(cur, dp[to]);
    }
    for (int i = 0; i < k; ++i)
        ans += cur[i].first;

    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)
            continue;
        nxt = sub(cur, dp[to]);
        nxt = shift(nxt);
        ++nxt[0].first;
        ++nxt[0].second;
        dfs(to, v, nxt);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs_init(1, -1);
    vector<pll> emp(k);
    dfs(1, -1, emp);

    cout << ans / 2LL << endl;

    return 0;
}