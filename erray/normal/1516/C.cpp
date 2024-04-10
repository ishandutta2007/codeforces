// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  const int N = 100 * 2000 + 1;
  bitset<N> can;
  can[0] = true;
  for (auto e : a) {
    can = (can << e) | (can >> e);
  }

  if (can[0]) {
    int mn = INT_MAX;
    int ind = -1;
    for (int i = 0; i < n; ++i) {
      int me = __builtin_ctz(a[i]);
      if (me < mn) {
        mn = me;
        ind = i;
      }
    }
    cout << 1 << '\n' << ind + 1 << '\n';
  } else {
    cout << 0 << '\n';
  }                                                                                    
}