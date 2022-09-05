#include <iostream>
#include <array>

void run(std::istream& in, std::ostream& out) {
  std::array<std::string, 3> data;
  for (size_t i = 0; i < data.size(); i++) {
    in >> data[i];
  }
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      if (data[i][j] != data[2-i][2-j]) {
        out << "NO" << std::endl;
        return;
      }
    }
  }
  out << "YES" << std::endl;
}

int main() {
  run(std::cin, std::cout);
  return 0;
}