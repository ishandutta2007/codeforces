#include <bits/stdc++.h>

int solve() {
  int n;
  scanf("%d", &n);
  std::vector<int> f(n), color(n);
  for (int i = 0, a, b; i < n; ++i) {
    scanf("%d%d", &a, &b);
    a--;
    b--;
    if ((a < n) ^ (b < n)) {
      if (a < n) {
        f[a] = b;
        color[a] = 0;
      } else {
        f[b] = a;
        color[b] = 1;
      }
    } else {
      return -1;
    }
  }
  std::vector<int> sufmax(n + 1);
  sufmax[n] = -1;
  for (int i = n; i--;) {
    sufmax[i] = std::max(f[i], sufmax[i + 1]);
  }
  int premin = n << 1;
  //   std::cerr << f << std::endl;
  int result = 0;
  for (int cut = 0, last_cut = -1; cut <= n; ++cut) {
    if (premin > sufmax[cut]) {
      if (last_cut >= 0) {
        std::vector<int> s0;
        for (int i = last_cut; i < cut; ++i) {
          while (!s0.empty() && f[s0.back()] < f[i]) {
            s0.pop_back();
          }
          s0.push_back(i);
        }
        std::vector<int> s1;
        {
          auto iterator = s0.begin();
          for (int i = last_cut; i < cut; ++i) {
            if (iterator != s0.end() && i == *iterator) {
              iterator++;
            } else {
              s1.push_back(i);
            }
          }
        }
        for (int i = 1; i < static_cast<int>(s1.size()); ++i) {
          if (f[s1[i - 1]] < f[s1[i]]) {
            return -1;
          }
        }
        int c[2][2];
        memset(c, 0, sizeof(c));
        for (int i : s0) {
          c[0][color[i]]++;
        }
        for (int i : s1) {
          c[1][color[i]]++;
        }
        result += std::min(c[0][0] + c[1][1], c[0][1] + c[1][0]);
      }
      last_cut = cut;
    }
    if (cut < n) {
      premin = std::min(premin, f[cut]);
    }
  }
  return result;
}

int main() { printf("%d\n", solve()); }