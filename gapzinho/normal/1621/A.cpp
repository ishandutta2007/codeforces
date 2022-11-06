#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 2e5+5; // N-i+qntB[i];
const int mod = 1e9+7;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[ms];

void solve() {
  int n, k;
  cin >> n >> k;
  if (k*2-1 > n) {
    cout << -1 << '\n';
    return;
  }
  for(int i = 0; i < n; i++) {
      arr[i] = 0;
  }
  for(int i = 0; i < k; i++) {
    arr[i*2] = 1;
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i != j || !arr[i]) {
        cout << '.';
      } else {
        cout << 'R';
      }
    }
    cout << '\n';
  }
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