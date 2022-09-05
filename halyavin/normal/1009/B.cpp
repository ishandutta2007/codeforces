#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    std::string s;
    in >> s;
    int bs = 0;
    std::string t;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            bs++;
        } else {
            t.push_back(s[i]);
        }
    }
    size_t i;
    for (i = 0; i < t.length(); i++) {
        if (t[i] == '2') {
            break;
        }
    }
    t.insert(i, bs, '1');
    out << t << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}