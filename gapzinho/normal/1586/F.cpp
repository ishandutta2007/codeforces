
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 1005;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int v[ms][ms];

int solve(int i, int j, int k, int c) {
  if(i == j) return 0;
  int sz = j-i+1;
  int qnt = (sz+k-1)/k;
  int ans = 1;
  // cout << i << " " << j << " " << qnt << endl;
  for(int p = 0; i+p*qnt <= j; p++) {
    for(int x = i+p*qnt; x <= min(j, i+(p+1)*qnt-1); x++) {
      for(int y = i+(p+1)*qnt; y <= j; y++) {
        v[x][y] = c;
      }
    }
    ans = max(ans, solve(p*qnt+i, min(j, i+(p+1)*qnt-1), k, c+1)+1);
  }
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  cout << solve(0, n-1, k, 1) << endl;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      cout << v[i][j] << ' ';
    }
    // cout << endl;
  }
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // t = inf;
  // cin >> t;
  // cout << fixed << setprecision(9);
  while (t--) {
      solve();
  }
  return 0;
}