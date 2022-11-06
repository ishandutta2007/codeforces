
#include <bit>
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int inf = 1e9;
const int ms = 1e6+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> curAns;

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  while(n % 6 == 0) {
    n /= 6;
    ans++;
  }
  while(n % 3 == 0) {
    n /= 3;
    ans += 2;
  }
  if(n == 1) {
    cout << ans << '\n';
  } else {
    cout << -1 << '\n';
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