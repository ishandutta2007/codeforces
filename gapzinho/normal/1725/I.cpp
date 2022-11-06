#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  long double;
const int inf = 0x3f3f3f3f3f3f3f3f;
 
const int ms = 1e5+5;
const int mod = 998244353;

int ds[ms];
int sz[ms];

int root(int i) {
  if(ds[i] != i) ds[i] = root(ds[i]);
  return ds[i];
}

int ans = 1;
int cnt = 1;

void join(int i, int j) {
  i = root(i); j = root(j);
  if(sz[i] < sz[j]) {
    swap(i, j);
  }
  ds[j] = i;
  ans = ans * sz[i] % mod * sz[i] % mod * sz[j] % mod * sz[j] % mod * cnt % mod;
  cnt += 2;
  sz[i] += sz[j];
}

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    ds[i] = i;
    sz[i] = 1;
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    join(u, v);
  }
  cout << ans << '\n';
}
 
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}