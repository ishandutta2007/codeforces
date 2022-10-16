#include <bits/stdc++.h>

int main() {
  unsigned n;
  std::cin >> n;
  unsigned const ROOMS = 10;
  std::vector<bool> hotel(ROOMS);
  char ch{};
  while (n--) {
    std::cin >> ch;
    if (ch == 'L') {
      auto it = std::find(hotel.begin(), hotel.end(), false);
      *it = true;
    } else if (ch == 'R') {
      auto it = std::find(hotel.rbegin(), hotel.rend(), false);
      *it = true;
    } else {
      hotel[ch - '0'] = false;
    }
  }
  for (auto b : hotel) {
    std::cout << b;
  }
  std::cout << '\n';
  return 0;
}