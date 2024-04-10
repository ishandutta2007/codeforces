#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);

  long long r; cin >> r;
  for (long long x = 1; x * x < r; ++x) {
    long long y = r - (x * x + x + 1);
    if (y > 0 && y % 2 * x == 0) {
      cout << x << ' ' << y / 2 * x << '\n';
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}