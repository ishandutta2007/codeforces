#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::string s;
    in >> s;
    int x = 0;
    int y = 0;
    for (char c : s) {
        switch (c) {
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
        }
    }
    out << n - std::abs(x) - std::abs(y) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}