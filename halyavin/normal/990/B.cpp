#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n, K;
    in >> n >> K;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    std::sort(as.begin(), as.end(), std::greater<>());
    int ans = 1;
    int prev = as[0];
    for (int i = 1; i < n; i++) {
        if (as[i] == prev) {
            ans++;
            continue;
        }
        if (as[i] >= as[i - 1] - K) {
            continue;
        }
        prev = as[i];
        ans++;
    }
    out << ans << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}