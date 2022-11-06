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

int p[ms];
int l[ms], r[ms];
vector<int> g[ms];
int ans = 0;

int dfs(int u) {
  int hlp = 0;
  for(int v : g[u]) {
    hlp += dfs(v);
  }
  if(hlp < l[u]) {
    ans++;
    return r[u];
  } else {
    return min(hlp, r[u]);
  }
}

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    g[i].clear();
  }
  for(int i = 2; i <= n; i++) {
    cin >> p[i];
    g[p[i]].emplace_back(i);
  }
  for(int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  ans = 0;
  dfs(1);
  cout << ans << '\n';
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
  cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}