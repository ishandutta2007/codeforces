
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

void solve() {
  int n;
  cin >> n;
  for(int i = n; i > 1; i--) {
    cout << "?";
    for(int j = 1; j < n; j++) cout << " " << 1;
    cout << " " << i << endl;
    int k;
    cin >> k;
    if(k != 0) {
      if(arr[n] == 0) {
        arr[n] = n+1-i;                                        
      }
      arr[k] = arr[n] + i - 1;
    }
  }
  if(arr[n] == 0) arr[n] = n;
  for(int i = n-1; i >= 1; i--) {
    cout << "?";
    for(int j = 1; j < n; j++) cout << " " << n;
    cout << " " <<  i << endl;
    int k;
    cin >> k;
    if(k != 0) {
      arr[k] = arr[n] + i - n;
    }
  }
  cout << "!";
  for(int i = 1; i <= n; i++) cout << " " << arr[i];
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