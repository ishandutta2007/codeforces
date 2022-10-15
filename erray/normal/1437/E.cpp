// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(k);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] -= i;
  }

  bool ok = true;
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
    --b[i];
    if (i > 0) {
      ok &= (a[b[i]] >= a[b[i - 1]]);   
    }
  }
  b.insert(b.begin(), -1);
  b.push_back(n);

  if (!ok) {
    return cout << -1, 0;
  }
  auto solve = [&](int l, int ri) {
    int low = (l == -1 ? (int) -1e9 : a[l]);
    int high = (ri == n ? (int) +2e9 : a[ri]);
    vector<int> r;
    for (int i = l + 1; i < ri; ++i) {
      if (a[i] > high || a[i] < low) {
        continue;
      }  
      auto it = lower_bound(r.begin(), r.end(), a[i] + 1);
      if (it == r.end()) {
        r.push_back(a[i]);
      } else {
        *it = a[i];
      }
    }
    return (ri - l - 1) - (int) r.size();
  };

  int ans = 0;
  for (int i = 1; i < (int) b.size(); ++i) {
    ans += solve(b[i - 1], b[i]);
  }
  cout << ans << '\n';
}