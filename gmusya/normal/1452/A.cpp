#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x > y)
      swap(x, y);
    int ans = 2 * x;
    y -= x;
    ans += max(2 * y - 1, 0);
    cout << ans << '\n';
  }
  return 0;
}