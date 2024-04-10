#include <bits/stdc++.h>

using Long = unsigned long long;

const int N = 1'000'000;
const int M = 60;

struct Seg {
  int l, r, sum;
};

bool operator<(const Seg &a, const Seg &b) { return a.r < b.r; }

struct Segs {
  Segs() : segs{Seg{-2, -2, 0}} {}

  // (l, r]
  void add(int l, int r) {
    int sum = segs.back().sum;
    segs.push_back(Seg{l, r, sum + (r - l)});
  }

  void pop() { segs.pop_back(); }

  int count(int r) const {
    auto iterator = std::lower_bound(segs.begin(), segs.end(), Seg{0, r, 0});
    if (iterator == segs.end() || r <= iterator->l) {
      return std::prev(iterator)->sum;
    }
    return iterator->sum - (iterator->r - r);
  }

  int count(int l, int r) const { return count(r) - count(l); }

  std::vector<Seg> segs;
};

int n;
Long a[N];
Segs min_segs[M], max_segs[M];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  Long result = 0;
  std::vector<int> min_stack{-1}, max_stack{-1};
  int run_sum = 0;
  for (int i = 0; i < n; ++i) {
    int r = min_stack.back();
    while (~r && a[r] >= a[i]) {
      min_stack.pop_back();
      int b = __builtin_popcountll(a[r]);
      int l = min_stack.back();
      min_segs[b].pop();
      run_sum -= max_segs[b].count(l, r);
      r = l;
    }
    {
      int b = __builtin_popcountll(a[i]);
      min_segs[b].add(r, i);
      run_sum += max_segs[b].count(r, i);
    }
    min_stack.push_back(i);
    r = max_stack.back();
    while (~r && a[r] <= a[i]) {
      max_stack.pop_back();
      int b = __builtin_popcountll(a[r]);
      int l = max_stack.back();
      max_segs[b].pop();
      run_sum -= min_segs[b].count(l, r);
      r = l;
    }
    {
      int b = __builtin_popcountll(a[i]);
      max_segs[b].add(r, i);
      run_sum += min_segs[b].count(r, i);
    }
    max_stack.push_back(i);
    result += run_sum;
  }
  std::cout << result << std::endl;
}