#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  bool good = true;
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    if (x <= 5 || n - x + 1 <= 5 || y <= 5 || m - y + 1 <= 5) {
      good = false;
    }
  }
  if (!good) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}