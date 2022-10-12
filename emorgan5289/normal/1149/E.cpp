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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 2e5+5;
int h[N], f[N], l[N], v[N];
vector<int> adj[N];

void dfs(int i) {
    v[i] = 1;
    vector<int> d;
    for (auto& j : adj[i]){
        if (!v[j]) dfs(j);
        d.pb(l[j]);
    }
    sort(all(d));
    for (auto& x : d)
        if (l[i] == x) l[i]++;
    f[l[i]] ^= h[i];
}

void dfs2(int i) {
    debug(i, h[i], f[l[i]]);
    for (auto& j : adj[i])
        if (l[j] == l[i]-1) {
            dfs2(j); break;
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    while (m--) {
        int x, y; cin >> x >> y;
        adj[x-1].pb(y-1);
    }
    for (int i = 0; i < n; i++)
        if (!v[i]) dfs(i);
    if (*max_element(f, f+n) == 0)
        cout << "LOSE\n";
    else {
        cout << "WIN\n";
        int k = 0;
        for (int i = 0; i < n; i++)
            if (f[i] != 0) k = i;
        int r = 1<<(31-__builtin_clz(f[k]));
        debug(r);
        for (int i = 0; i < n; i++)
            if (l[i] == k && (r&h[i])) {
                h[i] ^= f[l[i]];
                for (auto& j : adj[i])
                    h[j] ^= f[l[j]], f[l[j]] = 0;
                break;
            }
        for (int i = 0; i < n; i++)
            cout << h[i] << " \n"[i == n-1];
    }
}