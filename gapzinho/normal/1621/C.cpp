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

int qry(int i) {
  int x;
  cout << "? " << i << endl;
  cin >> x;
  return x;
}

void solve() {
  int n;
  cin  >> n;
  for(int i = 1; i <= n; i++) {
    arr[i] = 0;
  }
  for(int i = 1; i <= n; i++) {
    if(!arr[i]) {
      int x = 0;
      while(x != i) {
        x = qry(i);
      }
      while(!arr[x]) {
        arr[x] = qry(i);
        x = arr[x];
      }
    }
  }
  cout << "!";
  for(int i = 1; i <= n; i++) {
    cout << " " << arr[i];
  }
  cout << endl;
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