#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    int res = 0;
    while (r - l) {
      res += r - l;
      r /= 10;
      l /= 10;
    }
    cout << res << '\n';
  }
  return 0;
}