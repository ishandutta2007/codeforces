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

const int N = 2e5+5;
vector<int> adj[N];
multiset<array<int, 2>, greater<>> w[N];
int ans = 0, a, b, c;

array<int, 2> inc(array<int, 2> x) {
    return {x[0]+1, x[1]};
}

void dfs1(int i, int k) {
    w[i].insert({0, i});
    for (int j : adj[i])
        if (j != k) {
            dfs1(j, i);
            w[i].insert(inc(*w[j].begin()));
        }
}

void shift(int i, int j) {
    w[i].erase(w[i].find(inc(*w[j].begin())));
    w[j].insert(inc(*w[i].begin()));
}

void dfs2(int i, int k) {
    for (int j : adj[i])
        if (j != k) {
            shift(i, j);
            dfs2(j, i);
            shift(j, i);
        }
    if (w[i].size() < 3) return;
    auto it = w[i].begin();
    auto x = *(it++);
    auto y = *(it++);
    auto z = *(it++);
    if (x[0]+y[0]+z[0] > ans) {
        ans = x[0]+y[0]+z[0];
        a = x[1], b = y[1], c = z[1];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs1(0, 0);
    dfs2(0, 0);
    cout << ans << "\n";
    cout << a+1 << " " << b+1 << " " << c+1 << "\n";
}