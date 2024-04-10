#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n;
vector<int> g[100010];
int d[100010];

void dfs(int x, int p = 0) {
    for(auto i : g[x]) {
        if(i == p) continue;

        d[i] = -d[x];
        dfs(i, x);
    }
}

void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) g[i].clear();
    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    d[1] = 1;
    dfs(1);

    for(int i=1; i<=n; i++) cout << ((int) g[i].size() * d[i]) << " ";
    cout << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}