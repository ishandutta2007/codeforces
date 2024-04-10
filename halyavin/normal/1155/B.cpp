#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::string s;
    in >> s;
    int k = (n - 11 + 1) / 2;
    int l = (n - 11) - k;
    int pos = 0;
    for (;pos < s.length() && l >= 0; pos++) {
        if (s[pos] == '8') {
            l--;
        }
    }
    if (pos >= s.length() - 9) {
        out << "NO\n";
        return;
    } else {
        out << "YES\n";
        return;
    }

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}