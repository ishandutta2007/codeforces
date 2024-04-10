#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int ms = 1e6+5;

int n;
int lim;
map<int, int> vis;
int get(int k) {
  if(vis.count(k)) return vis[k];
  int &ans = vis[k];
  ans = 100;
  if(k >= lim) return ans = 0;
  vector<bool> digs(10);
  int p = k;
  while(p > 0) {
    digs[p % 10] = 1;
    p /= 10;
  }
  for(int i = 9; i > 1; i--) {
    if(digs[i]) ans = min(ans, 1 + get(k*i));
  }
  return ans;
}

void solve() {
  int x;
  cin >> n >> x;
  lim = 1;
  while(n > 1) {
    n--;
    lim *= 10;
  }
  int bst = get(x);
  if(bst == 100) cout << -1 << '\n';
  else cout << bst << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
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