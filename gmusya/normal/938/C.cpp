#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    bool flag = false;
    int x;
    cin >> x;
    for (int n = 1; n == 1 || n * n - (n / 2) * (n / 2) <= x; n++) {
      int tmp = n * n - x;
      if (tmp <= 0) continue;
      int val = ceil(sqrt(tmp));
      int k = floor(n / val);
      if (k && n * n - (n / k) * (n / k) == x) {
        flag = true;
        cout << n << ' ' << k << '\n';
        break;
      }
    }
    if (!flag)
      cout << -1 << '\n';
  }
  return 0;
}