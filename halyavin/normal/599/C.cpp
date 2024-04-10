#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; i++) {
    in >> v[i];
  }
  std::vector<int> sortedV = v;
  std::sort(sortedV.begin(), sortedV.end());
  const int levels = 20;
  std::vector<int> tree[levels];
  for (int i = 0; i < levels; i++) {
    tree[i].resize((n + (1 << i) - 1) >> i);
  }
  int ans = 0;
  std::vector<int> next(n);
  std::iota(next.begin(), next.end(), 0);
  for (int i = 0; i < n; i++) {
    int idx = std::distance(sortedV.begin(), std::lower_bound(sortedV.begin(), sortedV.end(), v[i]));
    int idx2 = next[idx];
    next[idx]++;
    for (int i = 0; i < levels; i++) {
      tree[i][idx2]++;
      idx2 >>= 1;
    }
    int sum = 0;
    int icopy = i + 1;
    for (int j = 0; j < levels && icopy > 0; j++) {
      if (icopy & 1) {
        icopy--;
        sum += tree[j][icopy];
      }
      icopy >>= 1;
    }
    if (sum == i + 1) {
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