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
        ll n, m; cin >> n >> m;
        vector<array<ll, 3>> e(m);
        vector<vector<ll>> se(n, vector<ll>(n));
        for (int i = 0; i < m; i++) {
            ll x, y, w; cin >> x >> y >> w;
            e[i] = {x-1, y-1, w-1};
            se[x-1][y-1] = se[y-1][x-1] = i+1;
        }
        vector<array<ll, 3>> tri;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                for (int k = j+1; k < n; k++)
                    if (se[i][j] && se[i][k] && se[j][k])
                        tri.pb({se[i][j]-1, se[i][k]-1, se[j][k]-1});
 
        debug(tri);
 
        vector<vector<int>> M;
        vector<int> x;
 
        for (auto& [i, j, k] : tri) {
            M.emplace_back(m);
            M.back()[i] = M.back()[j] = M.back()[k] = 1;
            x.pb(0);
        }
        for (int i = 0; i < m; i++)
            if (e[i][2] != -2) {
                M.emplace_back(m);
                M.back()[i] = 1;
                x.pb(e[i][2]);
            }
 
        debug(M);
        debug(x);
 
        for (int i = 0; i < m; i++) {
            // find something with nonzero in slot i
            for (int j = i+1; j < M.size(); j++)
                if (M[j][i]) {
                    swap(M[i], M[j]);
                    swap(x[i], x[j]);
                    break;
                }
            // if no constraint, add a fake one
            if (i >= M.size() || M[i][i] == 0) {
                M.insert(M.begin()+i, vector<int>(m));
                M[i][i] = 1;
                x.insert(x.begin()+i, 0);
            }
            // ensure M[i][i] == 1
            if (M[i][i] == 2) {
                x[i] = (2*x[i])%3;
                for (int j = 0; j < m; j++)
                    M[i][j] = (2*M[i][j])%3;
            }
            // make all other vectors have 0 at index i
            for (int j = 0; j < M.size(); j++) {
                if (j == i || M[j][i] == 0) continue;
                int c = M[j][i];
                x[j] = (x[j]-c*x[i]+9)%3;
                for (int k = 0; k < m; k++)
                    M[j][k] = (M[j][k]-c*M[i][k]+9)%3;
            }
 
            debug(i);
            debug(M);
            debug(x);
        }
 
        debug(M);
        debug(x);
 
        bool ok = 1;
        for (auto& [i, j, k] : tri)
            if ((x[i]+x[j]+x[k])%3 != 0)
                ok = 0;
        if (ok) {
            for (int i = 0; i < m; i++)
                cout << x[i]+1 << " \n"[i == m-1];
        } else
            cout << "-1\n";
    }
}