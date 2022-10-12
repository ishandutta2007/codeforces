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

const int N = 1005, M = 5005;
vector<int> adj[N], radj[N];
array<int, 2> e[M];
int l[N], v[N], w[N], ans[M];

void inc(int i) {
    l[i]++;
    for (int j : radj[i])
        if (v[j] && w[j] && l[i] == l[j])
            inc(j);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--, y--;
        e[i] = {x, y};
        adj[x].pb(y);
        radj[y].pb(x);
    }
    v[0] = 1, w[n-1] = 1;
    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            v[j] |= v[i];
    for (int i = n-1; i >= 0; i--) {
        for (int j : adj[i]) {
            w[i] |= w[j];
            if (v[i] && v[j] && w[i] && w[j])
                cmax(l[i], l[j]+1);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            auto [x, y] = e[j];
            if (!w[x] || !w[y] || !v[x] || !v[y])
                continue;
            if (l[y] < l[x]-2) {
                if (i == n)
                    cout << "No\n", exit(0);
                inc(y);
            }
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < m; i++) {
        auto [x, y] = e[i];
        cout << max(1, min(2, l[x]-l[y])) << "\n";
    }
}