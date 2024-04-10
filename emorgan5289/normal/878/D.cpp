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

const int N = 1<<12;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> a(k, vector<int>(n));
    vector<vector<int>> v(n);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            v[j].pb(a[i][j]);
        }
    vector<vector<int>> m(n, vector<int>(k));
    vector<bitset<N>> p(k+q);
    for (int i = 0; i < n; i++) {
        iota(all(m[i]), 0);
        sort(all(m[i]), [&](int x, int y){
            return v[i][x] < v[i][y];
        });
    }
    for (int i = 0; i < k; i++)
        for (int j = 0; j < 1<<k; j++)
            p[i][j] = j&(1<<i);
    int i = k;
    while (q--) {
        int t, x, y; cin >> t >> x >> y; x--, y--;
        if (t == 1)
            p[i++] = p[x]&p[y];
        if (t == 2)
            p[i++] = p[x]|p[y];
        if (t == 3) {
            int mask = 0;
            for (int j : m[y]) {
                mask |= 1<<j;
                if (p[x][mask]) {
                    cout << v[y][j] << "\n";
                    break;
                }
            }
        }
    }
}