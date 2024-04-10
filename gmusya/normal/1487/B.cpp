#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
      cout << (k % n ? k % n : n) << '\n';
    } else {
      int m = n / 2;
      k--;
      k += (k / m) * (m + 1) - (k / m) * m;
      cout << k % n + 1 << '\n';
    }
  }
  return 0;
}