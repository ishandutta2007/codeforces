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

const int N = 1e6+5, Q = 10;
vector<int> adj[N];
int n, q, l[N], x[Q];

void bfs() {
    queue<int> v;
    fill(l, l+n, inf);
    for (int i = 0; i < n; i++)
        if (adj[i].size() == 1)
            l[i] = 0, v.push(i);
    while (!v.empty()) {
        int i = v.front(); v.pop();
        for (int j : adj[i])
            if (l[j] == inf)
                l[j] = l[i]+1, v.push(j);
    }
}

vector<int> d[N];
int ans[Q];

void dfs(int i, int k) {
    int b = -1;
    for (int j : adj[i]) {
        if (j == k) continue;
        dfs(j, i);
        if (b == -1 || d[j].size() > d[b].size())
            b = j;
    }

    if (b == -1) {
        d[i].push_back(l[i]);
        return;
    }

    d[i] = move(d[b]);

    for (int j : adj[i]) {
        if (j == k || j == b) continue;

        // LCA at i, one path at j, other path at child < j
        for (int u = 0; u < d[j].size(); u++) {
            for (int z = 0; z < q; z++) {
                int v = d[i].size();
                for (int dv = 2*bit_floor(d[i].size()); dv > 0; dv /= 2)
                    if (v-dv >= 0 && int(d[j].size()-1-u)+(d[i].size()-1-(v-dv))+2 < d[j][u]+d[i][v-dv]+x[z])
                        v -= dv;
                if (v != d[i].size())
                    cmax(ans[z], int(d[j].size()-1-u)+int(d[i].size()-1-v)+2);
                if (v != 0)
                    cmax(ans[z], d[j][u]+d[i][v-1]+x[z]);
            }
        }

        // merge
        for (int u = 0; u < d[j].size(); u++)
            cmax(d[i][u+d[i].size()-d[j].size()], d[j][u]);
        d[j].clear();
    }

    d[i].push_back(max(l[i], d[i].back()));

    // debug(i, d[i]);

    // endpoint at i, other endpoint in subtree of i
    for (int z = 0; z < q; z++) {
        int v = d[i].size();
        for (int dv = 2*bit_floor(d[i].size()); dv > 0; dv /= 2)
            if (v-dv >= 0 && (d[i].size()-1-(v-dv)) < l[i]+d[i][v-dv]+x[z])
                v -= dv;
        if (v != d[i].size())
            cmax(ans[z], int(d[i].size()-1-(v)));
        if (v != 0)
            cmax(ans[z], l[i]+d[i][v-1]+x[z]);
    }

    adj[i].clear();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int j; cin >> j; j--;
        // debug(i, j);
        adj[j].pb(i), adj[i].pb(j);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
        cin >> x[i];
    bfs();
    fill(ans, ans+q, -inf);
    dfs(0, 0);

    for (int i = 0; i < q; i++)
        cout << ans[i] << " \n"[i == q-1];
}