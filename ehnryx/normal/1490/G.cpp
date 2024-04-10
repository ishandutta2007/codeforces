#include <bits/stdc++.h>
using namespace std;

constexpr char nl = '\n';

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;
  while(T--) {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i=0; i<n; i++) {
      cin >> a[i];
    }
    vector<long long> sum, pmax;
    partial_sum(begin(a), end(a), back_inserter(sum));
    partial_sum(begin(sum), end(sum), back_inserter(pmax),
        [](const auto& a, const auto& b) { return max(a, b); });

    for(int i=0; i<m; i++) {
      int x;
      cin >> x;
      long long ans = 0;
      if(x > pmax.back()) {
        if(sum.back() <= 0) {
          cout << -1 << " ";
          continue;
        }
        long long shift = x - pmax.back();
        long long revs = (shift + sum.back() - 1) / sum.back();
        ans += revs * n;
        x -= revs * sum.back();
      }
      if(x > 0) {
        ans += lower_bound(begin(pmax), end(pmax), x) - begin(pmax);
      }
      cout << ans << " ";
    }
    cout << nl;
  }

  return 0;
}