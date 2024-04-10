#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll mod = 1000000007;
int n, x, u[200105];
int cycle, sz;
vector<int> g[200105];
ll ans = 1;
ll deg2[200105];

void dfs(int v, int timer, int p = -1) {
    if (u[v]) {
        if (!cycle)
            cycle = timer - u[v];
        return;
    }
    u[v] = timer;
    ++sz;
    int wasp = 0;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            if (!wasp) { wasp = 1; continue; }
        }
        dfs(to, timer + 1, v);
    }
}

int main()
{
    deg2[0] = 1;
    for (int i = 1; i < 200105; ++i)
        deg2[i] = (deg2[i - 1] * 2) % mod;

    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        if (!u[i]) {
            cycle = 0;
            sz = 0;
            dfs(i, 1);
            if (cycle)
                (ans *= deg2[cycle] - 2 + mod) %= mod;
            (ans *= deg2[sz - cycle]) %= mod;
        }
    }

    cout << ans << endl;

    return 0;
}