#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    std::string p, h;
    std::cin >> p >> h;
    std::sort(p.begin(), p.end());
    bool found = false;
    for (int i = 0; i + p.size() <= h.size() && !found; ++ i) {
        auto s = h.substr(i, p.size());
        std::sort(s.begin(), s.end());
        found |= s == p;
    }
    puts(found ? "YES" : "NO");
  }
}