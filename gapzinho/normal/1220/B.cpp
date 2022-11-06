#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int ms = 1005;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[ms][ms];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  int x = round(sqrt(arr[0][1] * arr[0][2] / arr[1][2]));
  // a[0] * a[1]
  // a[0] * a[2]
  // a[1] * a[2]
  cout << x;
  for(int i = 1; i < n; i++) {
    cout << " " << arr[0][i]/x;
  }
  cout << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
      solve();
  }
  return 0;
}