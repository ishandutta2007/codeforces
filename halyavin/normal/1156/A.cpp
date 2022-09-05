#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<int> figures(n);
    for (int i = 0; i < n; i++) {
        in >> figures[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int next = figures[i];
        int prev = figures[i - 1];
        if (prev == 1) {
            if (next == 2) {
                ans += 3;
                if (i >= 2 && figures[i - 2] == 3) {
                    ans--;
                }
            } else if (next == 3) {
                ans += 4;
            }
        } else if (prev == 2) {
            if (next == 1) {
                ans += 3;
            } else if (next == 3) {
                out << "Infinite\n";
                return;
            }
        } else if (prev == 3) {
            if (next == 1) {
                ans += 4;
            } else if (next == 2) {
                out << "Infinite\n";
                return;
            }
        }
    }
    out << "Finite\n";
    out << ans << "\n";

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}