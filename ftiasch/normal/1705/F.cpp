#line 1 "/tmp/tmp-9007097FSDktOygB3b.cpp"
#include <bits/stdc++.h>

template <int N> struct Strategy {
  static int diff(int p, int c) {
    return __builtin_popcount(p & c) - __builtin_popcount(p & ~c);
  }

  std::pair<int, int> solve(const std::vector<int> &candidates) {
    if (candidates.size() <= 1) {
      return {0, 0};
    }
    auto iterator = cache.find(candidates);
    if (iterator != cache.end()) {
      return iterator->second;
    }
    std::pair<int, int> best{INT_MAX, 0};
    for (int p = 0; p < 1 << N; ++p) {
      std::vector<std::vector<int>> groups((N << 1) + 1);
      for (int c : candidates) {
        groups[N + diff(p, c)].push_back(c);
      }
      bool effective = true;
      for (auto &&g : groups) {
        effective &= g.size() < candidates.size();
      }
      if (effective) {
        int cost = 0;
        for (auto &&g : groups) {
          cost = std::max(cost, solve(g).first);
        }
        best = std::min(best, {cost + 1, p});
      }
    }
    return cache[candidates] = best;
  }

  std::map<std::vector<int>, std::pair<int, int>> cache;
};

template <int STEP, typename IO> void solve(IO &&io) {
  int n = io.n();
  std::string q(n, 'F'), result(n, 'F');
  int base = io.ask(q);
  if (base == n) {
    return;
  }
  Strategy<STEP> strategy;
  for (int offset = 0; offset < n; offset += STEP) {
    std::vector<int> candidates;
    int step = std::min(n - offset, STEP);
    for (int mask = 0; mask < 1 << step; ++mask) {
      candidates.push_back(mask);
    }
    while (candidates.size() > 1) {
      int best = strategy.solve(candidates).second;
      for (int i = 0; i < step; ++i) {
        q[offset + i] = "FT"[best >> i & 1];
      }
      int diffs = io.ask(q) - base;
      if (diffs + base == n) {
        return;
      }
      std::vector<int> new_candidates;
      for (int c : candidates) {
        if (strategy.diff(best, c) == diffs) {
          new_candidates.push_back(c);
        }
      }
      candidates.swap(new_candidates);
    }
    int c = candidates[0];
    for (int i = 0; i < step; ++i) {
      result[offset + i] = "FT"[c >> i & 1];
      q[offset + i] = 'F';
    }
  }
  io.ask(result);
}

struct Mock {
  int n() const { return n_; }

  int ask(const std::string &q) {
    std::cerr << "ask " << q << std::endl;
    int result = 0;
    for (int i = 0; i < n_; ++i) {
      result += q[i] == answer[i];
    }
    return result;
  }

  void report(const std::string &q) {
    std::cerr << "report " << q << std::endl;
    assert(q == answer);
  }

  int n_;
  std::string answer;
};

struct IO {
  int n() {
    int n;
    std::cin >> n;
    return n;
  }

  int ask(const std::string &q) {
    std::cout << q << std::endl;
    int result;
    std::cin >> result;
    return result;
  }

  std::string answer;
};

int main() { solve<6>(IO{}); }