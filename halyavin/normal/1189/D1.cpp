#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        in >> u >> v;
        u--;v--;
        deg[u]++;
        deg[v]++;
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] == 2) {
            out << "NO\n";
            return;
        }
    }
    out << "YES\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}