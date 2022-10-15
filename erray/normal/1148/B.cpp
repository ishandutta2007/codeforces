// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  int ans = -1;
  if (min(n, m) <= k) {
    cout << -1 << '\n';
    return 0;
  } 
  
  for (int i = 0; i < k + 1; ++i) {
    int left = k - i;
    int next = lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
    next += left;
    if (next >= m) {
      cout << -1 << '\n';
      return 0;
    } else {
      ans = max(ans, b[next]);
    }
  }

  cout << 0LL + ans + tb << '\n';
}