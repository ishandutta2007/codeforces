#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      cout << abs(y1 - y2) << '\n';
      continue;
    }
    if (y1 == y2) {
      cout << abs(x1 - x2) << '\n';
      continue;
    }
    cout << abs(x1 - x2) + abs(y1 - y2) + 2 << '\n';
  }
  return 0;
}