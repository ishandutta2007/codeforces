#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int mod = 1e9+7;

int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}



const int ms = 2e5+3;

vector<int> g[ms];
int cst[ms];
int ans[ms];

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if(u == n) continue;
    g[v].emplace_back(u);
    cst[u]++;
  }
  memset(ans, 0x3f, sizeof ans);
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  ans[n] = 0;
  pq.emplace(0, n);
  while(!pq.empty()) {
    auto [resp, u] = pq.top();
    pq.pop();
    if(resp != ans[u]) continue;
    for(int v : g[u]) {
      cst[v]--;
      int dt = resp + cst[v] + 1;
      if(dt < ans[v]) {
        ans[v] = dt;
        pq.emplace(dt, v);
      }
    }
  }
  cout << ans[1] << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(12);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}