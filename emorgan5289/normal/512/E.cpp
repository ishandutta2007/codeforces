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

const int N = 1005;
int adj[N][N], n;
vector<array<int, 4>> ans;

void flip(int a, int b, int c, int d) {
    ans.pb({a, b, c, d});
    adj[a][b] = adj[b][a] = 0;
    adj[c][d] = adj[d][c] = 1;
}

void solve(int l, int r) {
    if (r-l+2 <= 3) return;
    int m = (l+r)/2;
    vector<array<int, 2>> cross;
    for (int i = r; i > m; i--)
        for (int j = l; j < m; j++)
            if (adj[i][j]) cross.pb({i, j});
    for (int i = 0; i+1 < cross.size(); i++) {
        if (cross[i][0] == cross[i+1][0])
            flip(cross[i][0], cross[i][1], cross[i+1][1], 0);
        else
            flip(cross[i][0], cross[i][1], cross[i+1][0], 0);
    }
    if (!cross.empty())
        flip(cross.back()[0], cross.back()[1], 0, m);
    solve(l, m), solve(m, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<array<int, 2>> combined_ans;
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < n; i++)
            fill(adj[i], adj[i]+n, 0);
        ans.clear();
        for (int i = 0; i < n-3; i++) {
            int x, y; cin >> x >> y; x--, y--;
            adj[x][y] = adj[y][x] = 1;
        }
        solve(1, n-1);
        if (t) {
            reverse(all(ans));
            for (auto& [a, b, c, d] : ans)
                combined_ans.pb({c, d});
        } else {
            for (auto& [a, b, c, d] : ans)
                combined_ans.pb({a, b});
        }
    }
    cout << combined_ans.size() << "\n";
    for (auto& [a, b] : combined_ans)
        cout << a+1 << " " << b+1 << "\n";
}