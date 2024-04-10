#include <bits/stdc++.h>

using namespace std;

using ui64 = uint64_t;

ui64 read() {
  string s;
  cin >> s;
  ui64 ans = 0;
  for (char ch : s) {
    ans *= 2;
    ans += ch - '0';
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ui64> rem(n);
  generate(rem.begin(), rem.end(), read);
  sort(rem.begin(), rem.end());
  ui64 U = (ui64) 1 << m;
  ui64 k = U - n;
  ui64 need = (k - 1) / 2;
  ui64 l = 0;
  ui64 r = U;
  while (l + 1 != r) {
    auto mid = (l + r) / 2;
    if (mid - (lower_bound(rem.begin(), rem.end(), mid) - rem.begin()) <= need) {
      l = mid;
    } else {
      r = mid;
    }
  }
  string ans;
  while (m--) {
    ans += to_string(l & 1);
    l >>= 1;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}