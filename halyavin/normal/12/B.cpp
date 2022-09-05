#include <iostream>
#include <array>

void run(std::istream &in, std::ostream &out) {
  std::string input;
  std::string answer;
  in >> input >> answer;
  if (input == "0") {
    if (answer=="0") {
      out << "OK" << std::endl;
    } else {
      out << "WRONG_ANSWER" << std::endl;
    }
    return;
  }
  size_t zeros = 0;
  while (answer.length() > zeros + 1 && answer[zeros + 1] == '0') {
    zeros++;
  }
  std::array<int, 10> stat = {};
  for (size_t i = 0; i < input.length(); i++) {
    stat[input[i] - '0']++;
  }
  if (zeros != stat[0]) {
    out << "WRONG_ANSWER" << std::endl;
    return;
  }
  stat[0] = 0;
  if (zeros != 0) answer.erase(1, zeros);
  for (size_t i = 0; i < answer.length(); i++) {
    int digit = answer[i] - '0';
    if (stat[digit] == 0) {
      out << "WRONG_ANSWER" << std::endl;
      return;
    }
    stat[digit]--;
    if (i > 0 && answer[i] < answer[i - 1]) {
      out << "WRONG_ANSWER" << std::endl;
      return;
    }
  }
  out << "OK" << std::endl;
}

int main() {
  run(std::cin, std::cout);
  return 0;
}