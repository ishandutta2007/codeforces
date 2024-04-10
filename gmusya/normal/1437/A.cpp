#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (2 * l  > r)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}