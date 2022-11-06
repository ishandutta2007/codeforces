#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
const int ms = 205; // N-i+qntB[i];
const int mod = 1e9+7;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int qnt[ms];


void solve() {
  int n;
  cin >> n;
  int ans = 0;
  memset(qnt, 0, sizeof qnt);
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x = abs(x);
    qnt[x]++;
    if(qnt[x] == 1 || (qnt[x] == 2 && x != 0)) ans++;
  }
  cout << ans << '\n';
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // #ifdef ONLINE_JUDGE
  //   freopen("grid.in", "r", stdin);
  //   freopen("grid.out", "w", stdout);
  // #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}