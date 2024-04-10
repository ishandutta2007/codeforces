#include <bits/stdc++.h>

const int N = 1'000'000;

int n, a[N], min_div[N + 1];
char s[N + 1];
std::vector<std::pair<int, int>> events[N];

struct Window {
  void prepend(int i, int e) {
    sum += e;
    list.emplace_back(i, sum);
  }

  void work() {
    // std::cerr << list << std::endl;
    std::vector<std::pair<int, int>> stack{{0, -1}};
    for (int i = 0; i < static_cast<int>(list.size()); ++i) {
      auto [idx, sum] = list[i];
      while (!stack.empty() && stack.back().first <= sum) {
        stack.pop_back();
      }
      int r = stack.empty() ? n : list[stack.back().second + 1].first;
      stack.emplace_back(sum, i);
      if (r < n) {
        int nxt_idx =
            i + 1 < static_cast<int>(list.size()) ? list[i + 1].first : -1;
        // std::cerr << "(" << nxt_idx << ", " << idx << "]"
        //           << " " << KV(r) << std::endl;
        events[r].push_back({nxt_idx, idx});
      }
    }
  }

  int sum = 0;
  std::vector<std::pair<int, int>> list;
};

int prev[N], right[N];

int find(int u) {
  if (u == -1) {
    return -1;
  }
  if (prev[u] != u) {
    prev[u] = find(prev[u]);
  }
  return prev[u];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  scanf("%s", s);
  int m = *std::max_element(a, a + n);
  memset(min_div, -1, sizeof(int) * (m + 1));
  std::vector<int> primes;
  for (int d = 2; d <= m; ++d) {
    if (min_div[d] == -1) {
      min_div[d] = primes.size();
      primes.push_back(d);
    }
    for (int i = 0; i < static_cast<int>(primes.size()); ++i) {
      int p = primes[i];
      if (d * p > m) {
        break;
      }
      min_div[p * d] = i;
      if (d % p == 0) {
        break;
      }
    }
  }
  //   std::cerr << std::vector<int>(min_div, min_div + (m + 1)) << std::endl;
  std::vector<Window> windows(primes.size());
  for (int l = n; l--;) {
    int v = a[l];
    while (v > 1) {
      int pid = min_div[v];
      int p = primes[pid];
      int e = 0;
      while (v % p == 0) {
        v /= p;
        e++;
      }
      windows[pid].prepend(l, s[l] == '*' ? e : -e);
    }
  }
  // int i = 0;
  for (auto &window : windows) {
    // std::cerr << KV(primes[i++]) << std::endl;
    window.work();
  }
  std::iota(prev, prev + n, 0);
  for (int m = 0; m < n; ++m) {
    for (auto [l, r] : events[m]) {
      int i = find(r);
      while (i > l) {
        right[i] = m;
        prev[i] = i - 1;
        i = find(i);
      }
    }
  }
  int i = find(n - 1);
  while (i >= 0) {
    right[i] = n;
    prev[i] = i - 1;
    i = find(i);
  }
  // std::cerr << std::vector<int>(right, right + n) << std::endl;
  long long result = 0;
  for (int l = 0; l < n; ++l) {
    result += right[l] - l;
  }
  printf("%lld\n", result);
}