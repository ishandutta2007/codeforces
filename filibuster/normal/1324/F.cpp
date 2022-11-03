#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int N = 2e5 + 13;

vector<int> g[N];
int dp[N], dp1[N], a[N];

void dfs(int v, int p) {
    dp[v] = a[v];
//    cout << v << endl;
    for(auto u : g[v])
        if(u != p) {
            dfs(u, v);
            if(dp[u] > 0)
                dp[v] += dp[u];
        }
}

void dfs2(int v, int p) {
    int s = dp[v] + dp1[v];//cout << v << endl;
    for(auto u : g[v])
        if(u != p) {
            if(dp[u] > 0)s -= dp[u];

            if(s > 0)
                dp1[u]= s;
            dfs2(u, v);

            if(dp[u] > 0)s += dp[u];
        }
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = (a[i] == 1 ? 1 : -1);
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v>> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, 0);
    dfs2(0, 0);
//    for(int i = 0; i < n; i++)
//        cout << dp[i] << ' ' << dp1[i] << endl;

    for(int i = 0; i < n; i++)
        cout << dp[i] + dp1[i] << ' ';
}