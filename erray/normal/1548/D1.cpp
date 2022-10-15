// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  array<int, 4> ct = {};
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    ct[(x / 2) % 2 * 2 + (y / 2) % 2]++;  
  }
  long long ans = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        int even = (i == j) + (j == k) + (i == k);
        if (even % 2 == 0) {
          continue;
        }
        array<int, 3> c = {ct[i], ct[j] - (i == j), ct[k] - (i == k) - (j == k)};
        ans += 1LL * c[0] * c[1] * c[2];
      }
    }
  }
  assert(ans % 6 == 0);
  ans /= 6;
  cout << ans << '\n';
}