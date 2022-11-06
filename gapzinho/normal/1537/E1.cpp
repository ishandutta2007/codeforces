
#include <bit>
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e18;
const int ms = 2e6+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
ii a[ms];

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  string ans;
  for(int i = 0; i < k; i++) {
    ans.push_back(s[i%n]);
  }
  for(int i = 1; i < n; i++) {
    string tmp;
    for(int j = 0; j < k; j++) {
      tmp.push_back(s[j%i]);
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
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