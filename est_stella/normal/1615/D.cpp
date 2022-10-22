#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define pre(x) cout<<fixed; cout.precision(x);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int n, m;
vector<pii> g[200010];
int u[200010];
int v[200010];
int w[200010];
int vis[200010];
bool flag;

void dfs(int x) {
    for(auto i : g[x]) {
        if(vis[i.fi] >= 0) {
            if(vis[i.fi] != (vis[x] ^ i.se)) flag = true;
            continue;
        }
        else {
            vis[i.fi] = vis[x] ^ i.se;
            dfs(i.fi);
        }
    }
}

void solve() {
    flag = false;
    cin >> n >> m;

    for(int i=1; i<=n; i++) g[i].clear();

    for(int i=1; i<n; i++) {
        cin >> u[i] >> v[i] >> w[i];
        if(w[i] >= 0) {
            int cnt = 0;
            for(int j=0; j<30; j++) cnt ^= (w[i] >> j);
            g[u[i]].eb(v[i], cnt&1);
            g[v[i]].eb(u[i], cnt&1);
        }
    }

    for(int i=0; i<m; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].eb(V, W);
        g[V].eb(U, W);
    }

    for(int i=1; i<=n; i++) vis[i] = -1;
    for(int i=1; i<=n; i++) {
        if(vis[i] >= 0) continue;
        vis[i] = 0;
        dfs(i);
    }

    if(flag) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(int i=1; i<n; i++) {
        cout << u[i] << " " << v[i] << " " << (w[i] >= 0 ? w[i] : (vis[u[i]] ^ vis[v[i]])) << "\n"; 
    }
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}