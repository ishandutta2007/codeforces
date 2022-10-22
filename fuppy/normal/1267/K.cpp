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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  usize n;
  std::cin >> n;

  const auto f =
      [](std::priority_queue<u64, std::vector<u64>, std::greater<u64>> que) {
        u64 ans = 1;
        u64 div = 1;
        u64 cnt = que.size() + 2;
        u64 rem = 0;
        u64 dc = 1;
        while (!que.empty() && que.top() < 1) {
          rem += 1;
          que.pop();
          div *= dc;
          dc += 1;
        }
        for (u64 c = 2; c != cnt; c += 1) {
          dc = 1;
          while (!que.empty() && que.top() < c) {
            que.pop();
            rem += 1;
            div *= dc;
            dc += 1;
          }
          ans *= rem;
          rem -= 1;
        }
        return ans / div;
      };

  const auto solve = [&](u64 k) -> u64 {
    std::priority_queue<u64, std::vector<u64>, std::greater<u64>> que;
    u64 cnt = 2;
    while (k != 0) {
      que.push(k % cnt);
      k /= cnt;
      cnt += 1;
    }
    u64 ans = f(que);
    if (que.top() == 0) {
      que.pop();
      ans -= f(que);
    }
    return ans;
  };
  for (usize loop = 0; loop != n; loop += 1) {
    u64 k;
    std::cin >> k;
    std::cout << solve(k) - 1 << '\n';
  }
  return 0;
}