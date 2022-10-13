#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 5e5+5;
int r[N], c[N], v[N];
map<int, int> adj[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int x, y, t; cin >> x >> y >> t; x--, y--;
        adj[y][x] |= t+1;
    }
    queue<int> q({n-1});
    fill(c, c+n, inf);
    c[n-1] = 0;
    while (q.size()) {
        int i = q.front(); q.pop();
        for (auto& [j, t] : adj[i]) {
            if (v[j]) continue;
            if (t == 3 || r[j] == t)
                v[j] = 1, c[j] = c[i]+1, q.push(j);
            else r[j] = 3^t;
        }
    }
    for (int i = 0; i < n; i++)
        debug(i, c[i], adj[i]);
    cout << (c[0] == inf ? -1 : c[0]) << "\n";
    for (int i = 0; i < n; i++)
        cout << (r[i] > 1 ? 1 : 0);
    cout << "\n";
}