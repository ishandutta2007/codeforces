// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    if (accumulate(a.begin(), a.end(), 0) == x) {
      cout << "NO\n";
      continue; 
    }
    cout << "YES\n";
    sort(a.begin(), a.end());
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      cur += a[i];
      if (cur == x) {
        swap(a.back(), a[i]);
        break; 
      }
    }
    for (auto e : a) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}