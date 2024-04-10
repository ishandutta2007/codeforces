#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    int n, m, q;
    in >> n >>m >> q;
    std::string s, t;
    in >> s >> t;
    if (t.length() > s.length()) {
        for (int i = 0; i < q; i++) {
            out << "0\n";
        }
        return;
    }
    std::vector<int> match(s.length() - t.length() + 1);
    for (size_t i = 0; i < match.size(); i++) {
        if (s.compare(i, t.length(), t) == 0) {
            match[i] = 1;
        }
    }
    std::vector<int> sum(match.size() + 1);
    sum[0] = 0;
    for (size_t i = 1; i < sum.size(); i++) {
        sum[i] = sum[i - 1] + match[i - 1];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        in >> l >> r;
        l--;r--;
        if (r - l + 1 < t.length()) {
            out << 0 << "\n";
        } else {
            out << (sum[r - t.length() + 2] - sum[l]) << "\n";
        }
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}