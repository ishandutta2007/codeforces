#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 2000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

pair<int, int> d[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define inrange(i, j) (i >= 0 && j >= 0 && i < n && j < m)

const int maxn = 1005;
bool v[maxn][maxn];
ll a[maxn][maxn], p[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m, t; cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            a[i][j] = c == '1' ? 1 : 0;
            p[i][j] = inf_ll;
        }
    queue<pair<int, int>> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            bool w = 0;
            for (auto& [dx, dy] : d)
                w |= inrange(i+dx, j+dy) && a[i+dx][j+dy] == a[i][j];
            if (w) {
                p[i][j] = 0;
                v[i][j] = 1;
                s.emplace(i, j);
            }
        }
    while (!s.empty()) {
        int x, y; tie(x, y) = s.front(); s.pop();
        for (auto& [dx, dy] : d)
            if (inrange(x+dx, y+dy) && !v[x+dx][y+dy]) {
                p[x+dx][y+dy] = p[x][y]+1;
                v[x+dx][y+dy] = 1;
                s.emplace(x+dx, y+dy);
            }
    }
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         debug(i, j, a[i][j], p[i][j]);
    while (t--) {
        ll i, j, k; cin >> i >> j >> k;
        i--, j--;
        if (k <= p[i][j])
            cout << a[i][j] << "\n";
        else
            cout << ((k%2)+p[i][j]+a[i][j])%2 << "\n";
    }
}