#include <iostream>
#include <array>
#include <map>

void run(std::istream& in, std::ostream& out) {
  std::string path;
  in >> path;
  std::map<std::array<int, 2>, int> prev;
  const std::array<int, 2> dxy[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  prev[std::array<int, 2>{0, 0}] = 0;
  std::array<int, 2> pos = {0, 0};
  for (size_t i = 0; i < path.length(); i++) {
    switch (path[i]) {
      case 'L':
        pos[0]++;
        break;
      case 'R':
        pos[0]--;
        break;
      case 'U':
        pos[1]++;
        break;
      case 'D':
        pos[1]--;
        break;
    }
    if (prev.find(pos) != prev.end()) {
      out << "BUG" << std::endl;
      return;
    }
    prev[pos] = i + 1;
    for (int j = 0; j < 4; j++) {
      std::array<int, 2> neib = {pos[0] + dxy[j][0], pos[1] + dxy[j][1]};
      auto it = prev.find(neib);
      if (it != prev.end() && it->second < i) {
        out << "BUG" << std::endl;
        return;
      }
    }
  }
  out << "OK" << std::endl;
}

int main() {
  run(std::cin, std::cout);
  return 0;
}