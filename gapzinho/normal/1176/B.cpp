
#include <bit>
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int inf = 1e9;
const int ms = 1e6+5;
const int mod = 1e9+7;
using ii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  int n;
  cin >> n;
  int cnt[3] = {0, 0, 0};
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x%3]++;
  }
  int x = min(cnt[2], cnt[1]);
  cnt[1] -= x;
  cnt[2] -= x;
  cnt[0] += x;
  while(cnt[1] >= 3) {
    cnt[1] -= 3;
    cnt[0]++;
  }
  while(cnt[2] >= 3) {
    cnt[2] -= 3;
    cnt[0]++;
  }
  cout << cnt[0] << endl;
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