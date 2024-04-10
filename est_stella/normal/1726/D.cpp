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
const ll Mod = 1e9+7;

int n, m;
int u[200010];
int v[200010];
vector<pii> g[200010];
int ans[200010];
bool chk[200010];
int cnt[200010];
pii p[200010];
int d[200010];

void dfs(int x) {
    chk[x] = true;
    for(auto i : g[x]) {
        if(chk[i.fi]) continue;
        ans[i.se] = 0;
        p[i.fi] = mp(x, i.se);
        d[i.fi] = d[x] + 1;
        dfs(i.fi);
    }
}

void solve() {
    cin >> n >> m;

    for(int i=1; i<=n; i++) g[i].clear(), chk[i] = false, cnt[i] = d[i] = 0;

    for(int i=1; i<=m; i++) {
        cin >> u[i] >> v[i];
        if(u[i]> v[i]) swap(u[i], v[i]);
        g[v[i]].eb(u[i], i);
        g[u[i]].eb(v[i], i);
        ans[i] = 1;
    }

    dfs(1);

    vector<int> e;
    for(int i=1; i<=m; i++) {
        if(ans[i]) {
            e.eb(u[i]);
            e.eb(v[i]);
        }
    }

    sort(all(e), [](int i, int j) {
        return d[i] < d[j];
    });
    
    if(e.size() == 6 && e[0] == e[1] && e[2] == e[3] && e[4] == e[5]) {
        int i;
        for(i = e[4]; p[i].fi != e[2]; i = p[i].fi);

        for(int j=1, flag = 1; j<=m; j++) {
            if(ans[j]) {
                if(flag && (u[j] == p[i].fi || v[j] == p[i].fi)) {
                    flag = 0;
                }
                else ans[j] = 0;
            }
        }

        ans[p[i].se] = 1;
        ans[p[p[i].fi].se] = 1;
    }

    for(int i=1; i<=m; i++) cout << ans[i];
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