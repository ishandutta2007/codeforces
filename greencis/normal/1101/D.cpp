#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k;
vector<int> ver[200105], g[200105], vis;
int d[200105], u[200105];

void dfs(int v, bool second = false) {
    if (!second) {
        vis.push_back(v);
        u[v] = 2 * k + 1;
    }
    for (int to : g[v]) {
        if (u[to] / 2 == k && d[to] > d[v]) {
            d[to] = d[v] + 1;
            dfs(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for (int j = 2; j * j <= x; ++j) {
            int cnt = 0;
            while (x % j == 0) {
                x /= j;
                ++cnt;
            }
            if (cnt > 0)
                ver[j].push_back(i);
        }
        if (x > 1)
            ver[x].push_back(i);
    }

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;
    for (k = 2; k <= 200000; ++k) {
        if (ver[k].empty()) continue;
        for (int x : ver[k]) {
            u[x] = k * 2;
            d[x] = 1e9;
        }
        for (int x : ver[k]) {
            if (u[x] & 1)
                continue;
            vis.clear();
            d[x] = 0;
            dfs(x);
            int mx = -1, mxi = -1;
            for (int y : vis) {
                if (d[y] > mx) {
                    mx = d[y];
                    mxi = y;
                }
                d[y] = 1e9;
            }
            d[mxi] = 0;
            dfs(mxi, true);
            for (int y : vis)
                ans = max(ans, d[y] + 1);
        }
    }
    cout << ans;
}