#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 2e5+5;
vector<int> adj[N];
bool c[N];

void dfs(int i, int p) {
    c[i] = !c[p];
    for (auto& j : adj[i])
        if (j != p)
            dfs(j, i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(0, 0);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (c[i]) a++;
        else b++;
    }
    cout << min(a, b)-1 << "\n";
}