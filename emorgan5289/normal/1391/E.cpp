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
vector<int> adj[N], r[N], s, p;
int v[N], h[N], f, n, m, k;

void dfs(int i) {
    v[i] = 1;
    if (!f) s.pb(i);
    if (s.size() == k) f = 1;
    r[h[i]].pb(i);
    for (auto& j : adj[i])
        if (!v[j]) {
            h[j] = h[i]+1;
            dfs(j);
        }
    if (!f) s.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        k = n/2 + (n&1);
        for (int i = 0; i < n; i++)
            adj[i].clear(), r[i].clear();
        s.clear(), p.clear();
        fill(v, v+n, 0);
        while (m--) {
            int x, y; cin >> x >> y; x--, y--;
            adj[x].pb(y), adj[y].pb(x);
        }
        h[0] = f = 0;
        dfs(0);
        if (f) {
            cout << "PATH\n" << k << "\n";
            for (auto& x : s)
                cout << x+1 << " ";
            cout << "\n";
        } else {
            k = k/2 + (k&1);
            cout << "PAIRING\n" << k << "\n";
            for (int i = 0; i < n; i++) {
                debug(r[i]);
                for (int j = 0; j+1 < r[i].size(); j += 2) {
                    if (k == 0) break;
                    k--;
                    cout << r[i][j]+1 << " " << r[i][j+1]+1 << "\n";
                }
            }
        }
    }
}