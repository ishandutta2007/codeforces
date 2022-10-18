#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n, m, a[100105], b[100105], u[100105], dp[100105];
vector<int> g[100105];

void dfs(int v) {
    if (!u[v]) {
        u[v] = 1;
        int ans = 0;
        for (int i = 0; i < g[v].size(); ++i) {
            dfs(g[v][i]);
            ans = max(ans, dp[g[v][i]]);
        }
        dp[v] = ans + 1;
    }
}

bool check(int R) {
    for (int i = 0; i < 100105; ++i)
        g[i].clear(), u[i] = dp[i] = 0;
    for (int i = 0; i < R; ++i)
        g[a[i]].push_back(b[i]);
    for (int i = 0; i < n; ++i)
        dfs(i + 1);

    for (int i = 1; i <= n; ++i)
        if (dp[i] == n)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> a[i] >> b[i];

    int L = 1, R = m;
    while (L < R) {
        int mid = (L + R) / 2;
        if (check(mid)) R = mid;
        else L = mid + 1;
    }
    if (check(L)) cout << L;
    else cout << "-1";

    return 0;
}