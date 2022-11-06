
#include <bit>
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int inf = 1e9;
const int ms = 3000+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[ms];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr+n);
  reverse(arr, arr+n);
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // t = inf;
  cin >> t;
  // cout << fixed << setprecision(9);
  while (t--) {
      solve();
  }
  return 0;
}