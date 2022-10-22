#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int ans = a[n-1] - a[0];
  for (int i = 0; i < n; ++i) {
    ans = max(ans, a[i] - a[(i+1) % n]);
  }
  if (n > 1) {
    ans = max(ans, a[n-1] - *min_element(a.begin(), a.end()-1));
    ans = max(ans, *max_element(a.begin()+1, a.end()) - a[0]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}