// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    
    array<vector<int>, 2> c;
    for (int i = 0; i < n; ++i) {
      c[i % 2].push_back(a[i]);
    }
    sort(c[0].rbegin(), c[0].rend());
    sort(c[1].rbegin(), c[1].rend());
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      res[i] = c[i % 2].back();
      c[i % 2].pop_back();
    }
    cout << (is_sorted(res.begin(), res.end()) ? "YES" : "NO") << '\n';
  }
}