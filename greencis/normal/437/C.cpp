#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, c[1005], u[1005];
vector<int> g[1005], order;

void dfs(int v) {
    if (u[v]) return;
    u[v] = 1;
    for (int to : g[v])
        dfs(to);
    order.push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (c[x] > c[y] || (c[x] == c[y] && x > y))
            g[x].push_back(y);
        else
            g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        dfs(i);
    int ans = 0;
    reverse(order.begin(), order.end());
    for (int v : order)
        for (int to : g[v])
            ans += c[to];
    cout << ans;

    return 0;
}