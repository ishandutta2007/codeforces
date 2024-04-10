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

const int N = 2005;
char a[N][N];
int c[N][N];
vector<pair<int, int>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pair<int, int>> bfs;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    fill(&a[0][0], &a[0][0]+sizeof(a)/sizeof(char), '$');
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            bool v = 1;
            for (auto& [x, y] : d)
                v = v && a[i][j] == a[i+x][j+y];
            if (!v) c[i][j] = 1, bfs.push({i, j});
            else c[i][j] = inf;
        }
    while (!bfs.empty()) {
        auto [i, j] = bfs.front(); bfs.pop();
        for (auto& [x, y] : d)
            if (a[i+x][j+y] != '$' && c[i+x][j+y] == inf)
                c[i+x][j+y] = c[i][j]+1, bfs.push({i+x, j+y});
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans += c[i][j];
    cout << ans << "\n";
}