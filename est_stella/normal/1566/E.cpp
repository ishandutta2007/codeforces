#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define em emplace
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair

typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const ll INF = 1e18;
const int inf = 1e9;

int n;
int ans;
vector<int> g[200010];

int dfs(int x, int p=0) {
    int cnt = 0;
    for(auto i : g[x]) {
        if(i == p) continue;

        cnt += dfs(i, x);
    }

    if(!cnt && x != 1) return 1;
    
    ans += max(cnt - 1, 0);
    
    return 0;
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

    ans = 1;
    dfs(1);

    cout << ans << "\n";
}

int main() {
    fast;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}