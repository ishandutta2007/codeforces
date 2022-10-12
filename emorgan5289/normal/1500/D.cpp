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

using state = vector<array<int, 2>>; // {pos, val}

const int N = 1505, K = 10;
int n, q;
int a[N][N], f[N*N], ans[N], dp[N][N];
state tmp;
state up[N], sq[N][N];

// merge r into l
void apply(state& l, state r) {
    for (auto& [i, v] : r) i++;
    merge(all(l), all(r), back_inserter(tmp));
    l.clear();
    for (auto [i, v] : tmp)
        if (f[v]++ == 0 && l.size() <= q)
            l.pb({i, v});
    for (auto [i, v] : tmp) f[v]--;
    tmp.clear();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            sq[i][j].pb({1, a[i][j]});
        }
    state pl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            state le = {{1, a[i][j]}}, u = {{1, a[i][j]}};
            if (i > 0) {
                apply(u, up[j]);
                apply(sq[i][j], up[j]);
            }
            if (j > 0) {
                apply(le, pl);
                apply(sq[i][j], pl);
            }
            up[j] = u;
            pl = le;
            if (min(i, j) > 0) {
                apply(sq[i][j], sq[i-1][j-1]);
                sq[i-1][j-1].clear();
            }
            int k = min(i, j)+1;
            if (sq[i][j].size() == q+1)
                cmin(k, sq[i][j].back()[0]-1);
            ans[k]++;
        }
    }

    for (int i = n-1; i > 0; i--)
        ans[i] += ans[i+1];
    for (int i = 1; i <= n; i++)
        cout << ans[i] << "\n";
}