#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
        if (as[i] > as[i - 1] && as[i] > as[i + 1]) {
            ans++;
        } else if (as[i] < as[i - 1] && as[i] < as[i + 1]) {
            ans++;
        }
    }
    out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}