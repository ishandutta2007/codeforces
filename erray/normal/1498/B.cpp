// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    multiset<int> ms(a.begin(), a.end());
    int ans = 0;
    int from = 0;
    while (!ms.empty()) {
      auto can = ms.lower_bound(w - from + 1);
      if (can == ms.begin()) {
        ++ans;
        from = 0;
      } else {
        can = prev(can);
        from += *can;
        ms.erase(can);
      }
    }
    cout << ans + 1 << '\n';
  }
}