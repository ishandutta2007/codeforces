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
const ll inf = 1e9;
const ll INF = 1e18;

int n;
int u[200010];
int v[200010];
vector<pii> g[200010];
vector<int> G[200010];
vector<int> pop[200010];
vector<int> odd[200010], even[200010];
bool flag;
int in[200010];

void dfs(int x, int p = 0) {
    if(!flag) return;
    odd[x].clear();
    even[x].clear();
    pop[x].clear();

    for(int i=0; i<g[x].size(); i++) {
        if(i & 1) odd[x].eb(i);
        else even[x].eb(i);

        pop[x].eb(0);
    }

    for(auto i : g[x]) {
        if(i.fi == p) continue;

        dfs(i.fi, x);
        if(!flag) return;

        if(odd[i.fi].size()) {
            if(odd[x].empty()) {
                flag = false;
                return;
            }
            pop[x][odd[x].back()] = i.se;
            pop[i.fi][odd[i.fi].back()] = i.se;
            odd[x].pop_back();
            odd[i.fi].pop_back();
        }
        else if(even[i.fi].size()) {
            if(even[x].empty()) {
                flag = false;
                return;
            }
            pop[x][even[x].back()] = i.se;
            pop[i.fi][even[i.fi].back()] = i.se;
            even[x].pop_back();
            even[i.fi].pop_back();
        }
        else {
            flag = false;
            return;
        }

    }
}

void solve() {
    cin >> n;

    for(int i=1; i<=n; i++) g[i].clear();

    for(int i=1; i<n; i++) {
        in[i] = 0;
        G[i].clear();

        cin >> u[i] >> v[i];
        g[u[i]].eb(v[i], i);
        g[v[i]].eb(u[i], i);
    }

    flag = true;
    dfs(1);

    if(!flag) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    for(int i=1; i<=n; i++) {
        for(int j=1; j<pop[i].size(); j++) {
            G[pop[i][j]].eb(pop[i][j-1]);
            in[pop[i][j-1]]++;
        }
    }

    queue<int> q;
    for(int i=1; i<n; i++) if(in[i] == 0) q.em(i);

    while(q.size()) {
        int x = q.front();
        q.pop();

        cout << u[x] << " " << v[x] << "\n";

        for(auto i : G[x]) {
            in[i]--;
            if(in[i] == 0) q.em(i);
        }
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