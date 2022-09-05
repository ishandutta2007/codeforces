#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <sstream>
#include <queue>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::string> answer;
  std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
  for (int i = 0; i < n; i++) {
    std::string s;
    in >> s;
    if (s == "removeMin") {
      if (queue.empty()) {
        answer.push_back("insert 0");
      } else {
        queue.pop();
      }
      answer.push_back("removeMin");
      continue;
    }
    if (s == "insert") {
      int x;
      in >> x;
      queue.push(x);
      std::stringstream str;
      str << "insert " << x;
      answer.push_back(str.str());
      continue;
    }
    // s == "getMin"
    int y;
    in >> y;
    while (!queue.empty() && y > queue.top()) {
      queue.pop();
      answer.push_back("removeMin");
    }
    if (y < queue.top() || queue.empty()) {
      std::stringstream str;
      str << "insert " << y;
      answer.push_back(str.str());
      queue.push(y);
    }
    {
      std::stringstream str;
      str << "getMin " << y;
      answer.push_back(str.str());
    }
  }
  out << answer.size() << std::endl;
  for (const std::string& s : answer) {
    out << s << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}