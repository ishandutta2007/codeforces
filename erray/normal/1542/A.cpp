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
    n *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    array<int, 2> ct = {};
    for (auto e : a) {
      ++ct[e % 2];
    }
    cout << (ct[0] == n / 2 ? "Yes" : "No") << '\n';
  }
}