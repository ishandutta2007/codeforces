#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ll l, r;
  cin >> l >> r;
  for (int p = 61; p >= 0; p--) {
    if (((1ll << p) & l) != ((1ll << p) & r)) {
      cout << (1ll << (p + 1)) - 1;
      return 0;
    }
    if ((r - l + 1) >= (1ll << (p + 1))) {
      cout << (1ll << (p + 1)) - 1;
      return 0;
    }
  }
  cout << 0;
  return 0;
}