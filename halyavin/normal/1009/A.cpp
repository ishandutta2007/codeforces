#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n, m;
    in >> n >> m;
    std::vector<int> cs(n);
    for (int i = 0; i < n; i++) {
        in >> cs[i];
    }
    std::vector<int> as(m);
    for (int i = 0; i < m; i++) {
        in >> as[i];
    }
    int i = 0;
    int j = 0;
    int ans = 0;
    while (i < n && j < m) {
        if (cs[i] <= as[j]) {
            ans++;
            i++;
            j++;
            continue;
        }
        i++;
    }
    out << ans << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}