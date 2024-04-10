//  Copyright 2019 Nikita Golikov

#include <iostream>

int main() {
  int x;
  std::cin >> x;
  auto s = "DACB";
  auto r = x % 4;
  if (r != 2) {
    std::cout << (5 - r) % 4 << " A\n";
    return 0;
  }
  std::cout << 1 << " B\n";
  return 0;
}