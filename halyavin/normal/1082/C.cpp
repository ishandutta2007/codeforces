#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
struct Solution {
    int n, m;
    std::vector<std::vector<int>> rate;
    std::vector<int> subj;
    std::vector<int> subj2;
    std::vector<int> sums;
    int ans;
    void run(std::istream& in, std::ostream& out) {
      in >> n >> m;
      rate.assign(m, std::vector<int>());
      for (int i = 0; i < n; i++) {
        int s, r;
        in >> s >> r;
        s--;
        rate[s].push_back(r);
      }
      for (int i = 0; i < m; i++) {
        std::sort(rate[i].begin(), rate[i].end(), std::greater<int>());
      }
      subj.resize(m);
      std::iota(subj.begin(), subj.end(), 0);
      sums.assign(m, 0);
      ans = 0;
      int cur = 0;
      for (int i = 0; i < n; i++) {
        subj2.clear();
        for (int s : subj) {
          if (rate[s].size() <= i) {
            cur -= sums[s];
            continue;
          }
          sums[s] += rate[s][i];
          cur += rate[s][i];
          if (sums[s] < 0) {
            cur -= sums[s];
            continue;
          }
          subj2.push_back(s);
        }
        ans = std::max(ans, cur);
        std::swap(subj, subj2);
      }
      out << ans << "\n";
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}