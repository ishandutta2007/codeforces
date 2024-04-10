#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <map>

std::pair<int, int> simplify(const std::string& s) {
    int left = 0;
    int level = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            level++;
        } else {
            if (level == 0) {
                left++;
            } else {
                level--;
            }
        }
    }
    return {left, level};
}

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<std::pair<int, int>> ss;
    for (int i = 0; i < n; i++) {
        std::string s;
        in >> s;
        ss.push_back(simplify(s));
    }
    std::map<int, int> right;
    for (const auto& p : ss) {
        if (p.second == 0) {
            right[p.first]++;
        }
    }
    int64_t ans = 0;
    for (const auto& p : ss) {
        if (p.first == 0) {
            ans += right[p.second];
        }
    }
    out << ans << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}