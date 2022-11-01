#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if ((y - x) % (a + b))
      cout << -1 << '\n';
    else
      cout << (y - x) / (a + b) << '\n';
  }
  return 0;
}