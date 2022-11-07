
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
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) arr[i] = 0;
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[b] = 1;
  }
  for(int i = 1; i <= n; i++) {
    if(!arr[i]) {
      for(int j = 1; j <= n; j++) {
        if(i != j) {
          cout << i << ' ' << j << '\n';
        }
      }
      return;
    }
  }
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