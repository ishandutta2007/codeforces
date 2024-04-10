#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct state {
    ll sum1, sum2;
    int cnt1, cnt2;
};

inline state operator+(const state& a, const state& b) {
    return {a.sum1 + b.sum1, a.sum2 + b.sum2, a.cnt1 + b.cnt1, a.cnt2 + b.cnt2};
}

inline state operator-(const state& a, const state& b) {
    return {a.sum1 - b.sum1, a.sum2 - b.sum2, a.cnt1 - b.cnt1, a.cnt2 - b.cnt2};
}

inline state next(const state& a) {
    return {a.sum2 + a.cnt2, a.sum1, a.cnt2, a.cnt1};
}

int n;
vector<int> g[200105];
ll ans = 0;
state dp[200105];

state dfs_dp(int v, int p = -1) {
    state cur = { 0, 0, 0, 1 };
    for (int to : g[v]) {
        if (to == p) continue;
        state nxt = next(dfs_dp(to, v));
        cur = cur + nxt;
    }
    return dp[v] = cur;
}

void dfs(int v, state st, int p = -1) { // st is 'nexted' already
    state total = st + dp[v];
    ans += total.sum1 + total.sum2;
    for (int to : g[v]) {
        if (to == p) continue;
        state go = total;
        go = go - next(dp[to]);
        go = next(go);
        dfs(to, go, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs_dp(1);
    dfs(1, {0, 0, 0, 0});

    cout << ans / 2 << endl;
}