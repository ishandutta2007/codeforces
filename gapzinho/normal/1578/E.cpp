
#include <bit>
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 1e6+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[ms];
int composite[ms];

void solve() {
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  // cout << sum << " - " << composite[sum] << endl;
  if(composite[sum]) {
    cout << n << '\n';
    for(int i = 1; i <= n; i++) cout << i << ' ';
    cout << endl;
  } else {
    cout << n-1 << '\n';
    for(int i = 1; i <= n; i++) {
      if(composite[sum-arr[i]]) {
        for(int j = 1; j <= n; j++) {
          if(j != i) cout << j << ' ';
        }
        cout << '\n';
        return;
      }
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // t = inf;
  for(int i = 2; i <= 20000; i++) {
    for(int j = i+i; j <= 20000; j+=i) composite[j] = 1;
  }
  cin >> t;
  // cout << fixed << setprecision(9);
  while (t--) {
      solve();
  }
  return 0;
}