#include <iostream>
#include <vector>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x == y && y == z) {
      cout << "YES\n";
      cout << x << ' ' << y << ' ' << z << '\n';
      continue;
    }
    if (x == y && z < x) {
      cout << "YES\n";
      cout << x << ' ' << z << ' ' << z << '\n';
      continue;
    }
    if (x == z && y < x) {
      cout << "YES\n";
      cout << y << ' ' << x << ' ' << y << '\n';
      continue;
    }
    if (y == z && x < y) {
      cout << "YES\n";
      cout << x << ' ' << x << ' ' << y << '\n';
      continue;
    }
    cout << "NO\n";
  }
  return 0;
}