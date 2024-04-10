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
ll n, r, h[N], ans = 0;
vector<int> adj[N];

ll dfs(int i, int p) {
    vector<ll> x;
    for (int j : adj[i])
        if (j != p)
            x.pb(dfs(j, i));
    sort(all(x), greater<>());
    if (i == r) {
        if (x.size() == 1)
            ans += 2*h[i]-x[0];
        else
            ans += 2*h[i]-x[0]-x[1];
        return h[i];
    } else {
        ll y = x.size() == 0 ? 0 : x[0];
        if (h[i] > y) {
            ans += h[i]-y;
            y = h[i];
        }
        return y;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    r = max_element(h, h+n)-h;
    dfs(r, r);
    cout << ans << "\n";
}