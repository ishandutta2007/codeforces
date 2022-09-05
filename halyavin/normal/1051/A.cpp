#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

int getMask(const std::string& s) {
    int res = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res |= 1;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            res |= 2;
        } else {
            res |= 4;
        }
    }
    return res;
}

void run(std::istream &in, std::ostream &out) {
    int t;
    in >> t;
    const char add[3] = {'0', 'a', 'A'};
    for (int test = 0; test < t; test++) {
        std::string s;
        in >> s;
        if (getMask(s) == 7) {
            out << s << "\n";
            continue;
        }
        bool good = false;
        for (int l = 1; l <= 2 && !good; l++) {
            for (size_t i = 0; i + l <= s.length(); i++) {
                int mask = getMask(s.substr(0, i)) | getMask(s.substr(i + l));
                int rest = 7 - mask;
                if (__builtin_popcount(rest) <= l) {
                    size_t j = i;
                    for (int k = 0; k < 3; k++) {
                        if ((rest & (1 << k)) != 0) {
                            s[j] = add[k];
                            j++;
                        }
                    }
                    out << s << "\n";
                    good = true;
                    break;
                }
            }
        }
        if (!good) {
            for (int i = 0; i < 3; i++) {
                s[i] = add[i];
            }
            out << s << "\n";
        }
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}