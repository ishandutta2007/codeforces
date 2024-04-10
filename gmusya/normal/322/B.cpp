#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

int main() {
  uint r, g, b;
  cin >> r >> g >> b;
  uint ans = 0;
  for (int c = 0; c <= min({r, g, b, (uint) 2}); c++)
    ans = max(ans, (r - c) / 3 + (g - c) / 3 + (b - c) / 3 + c);
  cout << ans;
  return 0;
}