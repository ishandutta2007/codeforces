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

int n, k;
vector<int> g[200010];
priority_queue<int> pq[200010];

void dfs(int x, int p = 0) {
    int cnt = 0;
    for(auto i : g[x]) {
        if(i == p) continue;

        cnt++;
        dfs(i, x);
        if(pq[x].size() < pq[i].size()) swap(pq[x], pq[i]);

        while(pq[i].size()) {
            pq[x].em(pq[i].top());
            pq[i].pop();
        }
    }

    if(cnt == 0) pq[x].em(0);
    
    int y = pq[x].top();
    pq[x].pop();
    pq[x].em(y+1);
}

int main() {
    fast;

    cin >> n >> k;

    for(int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    dfs(1);

    int sum = 0;
    ll ans = -INF;
    for(int i=1; i<=k; i++) {
        if(pq[1].size()) {
            sum += pq[1].top();
            pq[1].pop();
        }

        ll b = min(n-sum, n/2);
        ans = max(ans, (n - i - b) * (i-b));
    }
    cout << ans;
}