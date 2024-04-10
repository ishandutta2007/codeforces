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
    std::sort(as.begin(), as.end());
    if (as[n - 1] >= as[n -2] + as[n - 3]) {
        out << "NO\n";
        return;
    }
    out << "YES\n";
    std::swap(as[n -1], as[n-2]);
    for (int i = 0; i < n; i++) {
        out << as[i] << " ";
    }
    out << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}