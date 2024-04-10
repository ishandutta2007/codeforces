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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj(1<<n);
        for (int i = 0; i < n<<(n-1); i++) {
            int x, y; cin >> x >> y;
            adj[x].pb(y), adj[y].pb(x);
        }
        vector<int> v(1<<n, -1), p(1<<n, -1);
        vector<int> deg(1<<n, 0);
        queue<int> q;
        v[0] = 0;
        p[0] = 0;
        deg[0] = 2;
        for (int i = 0; i < n; i++) {
            v[adj[0][i]] = 1<<i;
            p[1<<i] = adj[0][i];
            deg[adj[0][i]] = 2;
            for (int j : adj[adj[0][i]])
                if (++deg[j] == 2) q.push(j);
        }
        while (!q.empty()) {
            int i = q.front(); q.pop();
            vector<int> x;
            for (int j : adj[i]) {
                if (v[j] != -1) x.pb(j);
                if (++deg[j] == 2) q.push(j);
            }
            int k = v[x[0]]^v[x[1]];
            int k1 = (k-1)&k;
            if (p[v[x[0]]^k1] == -1)
                v[i] = v[x[0]]^k1;
            else
                v[i] = v[x[1]]^k1;
            p[v[i]] = i;
        }
        for (int i = 0; i < 1<<n; i++)
            cout << p[i] << " \n"[i == (1<<n)-1];
        if (__builtin_popcount(n) != 1) {
            cout << "-1\n"; continue;
        }
        vector<int> c(1<<n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 1<<n; j++)
                if (j&(1<<i))
                    c[j] ^= i;
        for (int i = 0; i < 1<<n; i++)
            cout << c[v[i]] << " \n"[i == (1<<n)-1];
    }
}