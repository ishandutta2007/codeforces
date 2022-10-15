// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      int add = min(k, a[i]);
      a[i] -= add;
      k -= add;
      a.back() += add;
    }
    for (auto e : a) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}