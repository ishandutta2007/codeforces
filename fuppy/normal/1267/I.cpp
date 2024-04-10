#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

using usize = std::size_t;
using u64 = std::uint_fast64_t;
using u32 = std::uint_fast32_t;
using i32 = std::int_fast32_t;

void solve(const usize n) {
  std::vector<std::vector<int>> memo(n * 2, std::vector<int>(n * 2, 0));
  for (usize i = 0; i < 2 * n; i += 1) {
    memo[i][i] = 2;
  }
  const auto ge = [&](const usize a, const usize b) {
    if (memo[a][b] != 0) {
      return memo[a][b] == 1;
    }
    std::cout << "? " << a + 1 << ' ' << b + 1 << std::endl;
    char c;
    std::cin >> c;
    if (c == '>') {
      memo[a][b] = 1;
      memo[b][a] = 2;
    } else {
      memo[a][b] = 2;
      memo[b][a] = 1;
    }
    return c == '>';
  };

  std::vector<usize> idx(n * 2);
  std::iota(idx.begin(), idx.end(), 0);
  for (usize i = 0; i < n; i += 1) {
    if (!ge(idx[i], idx[n + i])) {
      std::swap(idx[i], idx[n + i]);
    }
  }
  {
    std::vector<std::pair<usize, usize>> temp(n);
    for (usize i = 0; i < n; i += 1) {
      temp[i] = {idx[i], idx[n + i]};
    }
    std::sort(temp.begin(), temp.end(),
              [&](auto l, auto r) { return ge(l.second, r.second); });
    for (usize i = 0; i < n; i += 1) {
      idx[i] = temp[i].first;
      idx[n + i] = temp[i].second;
    }
  }
  std::vector<bool> checked(n * 2, false);
  std::queue<usize> que;
  for (usize i = 1; i < n; i += 1) {
    que.push(idx[n + i]);
  }
  while (!que.empty()) {
    const usize v = que.front();
    que.pop();
    usize cnt = 0;
    for (usize i = 0; i < n * 2; i += 1) {
      if (i == v) {
        continue;
      }
      if (ge(i, v)) {
        cnt += 1;
      } else if (!checked[i]) {
        checked[i] = true;
        que.push(i);
      }
    }
    if (cnt == n) {
      std::cout << '!' << std::endl;
      return;
    }
  }
  std::sort(idx.begin() + 1, idx.begin() + n, ge);
  ge(idx[n - 1], idx[n]);
  std::cout << '!' << std::endl;
  return;
}

int main() {
  usize t;
  std::cin >> t;
  while (t--) {
    usize n;
    std::cin >> n;
    solve(n);
  }
  return 0;
}