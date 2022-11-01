#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    int ans = 0;
    {
      int k = min(z1, y2);
      ans += 2 * k;
      z1 -= k;
      y2 -= k;
    }
    {
      int k = min(z2, x1);
      z2 -= k;
      x1 -= k;
    }
    {
      int k = min(z1, z2);
      z1 -= k;
      z2 -= k;
    }
    {
      int k = min(z2, y1);
      ans -= 2 * k;
    }
    cout << ans << '\n';
  }
  return 0;
}