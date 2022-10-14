#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

template <typename T = int> T read() {
  T v;
  std::cin >> v;
  return v;
}

template <typename T = int> std::vector<T> read_vector(size_t n) {
  std::vector<T> v(n);
  for (size_t i = 0; i < n; ++i) {
    v[i] = read<T>();
  }
  return v;
}

#define ALL(v) (v).begin(), (v).end()

template <typename T> using Vector2D = std::vector<std::vector<T>>;

template <typename T = int> Vector2D<T> vector_2d(int n, int m) {
  return Vector2D<T>(n, std::vector<T>(m));
}

template <typename T = int> Vector2D<T> vector_2d(int n, int m, T d) {
  return Vector2D<T>(n, std::vector<T>(m, d));
}

using Long = long long;
using u64 = uint64_t;

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-696031Ev6b0A6pGXgM.cpp"

#line 4 "/tmp/tmp-696031Ev6b0A6pGXgM.cpp"

using Plan = std::vector<int>;

// Kudos to ksun48
struct Solver {
  Solver(const std::string &s_) : n(s_.length()), s(n) {
    for (int i = 0; i < n; ++i) {
      s[i] = s_[i] - '0';
    }
    ones = std::accumulate(ALL(s), 0);
  }

  Plan solve() const {
    if (!ones) {
      return {};
    }
    // sum >= ones
    int min_power_of_two = ones == 1 ? 1 : 1 << (32 - __builtin_clz(ones - 1));
    int target = min_power_of_two;
    while (true) {
      auto plan = search(target);
      if (!plan.empty()) {
        return plan;
      }
      target <<= 1;
    }
  }

  static int score(int s) { return s - __builtin_popcount(s); }

  Plan search(int target) const {
    int exceed = target - ones;
    Plan plan{0};
    for (int i = 0; i < n;) {
      if (s[i]) {
        int current = s[i];
        int j = i + 1;
        while (j < n && score(current << 1 | s[j]) <= exceed) {
          current = current << 1 | s[j++];
        }
        exceed -= score(current);
        plan.push_back(j);
        i = j;
      } else {
        // [i, i + 1)
        plan.push_back(i + 1);
        i++;
      }
    }
    return exceed ? Plan{} : plan;
  }

  int n, ones;
  std::vector<int> s;
};

bool check(const std::string &s, const Plan &plan) {
  if (plan.back() != s.size()) {
    return false;
  }
  int sum = 0;
  for (int i = 1; i < plan.size(); ++i) {
    int cur = 0;
    for (int j = plan[i - 1]; j < plan[i]; ++j) {
      cur = cur << 1 | (s[j] - '0');
    }
    sum += cur;
  }
  return (sum & (sum - 1)) == 0;
}

int main() {
  std::ios::sync_with_stdio(false);
  //   for (int n = 5; n <= 15; ++n) {
  //     for (int mask = 1; mask < 1 << n; ++mask) {
  //       std::vector<char> s(n + 1);
  //       for (int i = 0; i < n; ++i) {
  //         s[i] = '0' + (mask >> i & 1);
  //       }
  //       auto plan = Solver(s.data()).solve();
  //       assert(!plan.empty());
  //       int sum = 0;
  //       for (int i = 1; i < plan.size(); ++i) {
  //         int cur = 0;
  //         for (int j = plan[i - 1]; j < plan[i]; ++j) {
  //           cur = cur << 1 | (s[j] - '0');
  //         }
  //         sum += cur;
  //       }
  //       std::cerr << sum << "\n";
  //       assert((sum & (sum - 1)) == 0);
  //     }
  //   }
  int T = read();
  while (T--) {
    auto s = read<std::string>();
    auto plan = Solver{s}.solve();
    if (plan.empty()) {
      std::cout << "-1\n";
    } else {
      if (!check(s, plan)) {
        throw new std::runtime_error(s);
      }
      std::cout << plan.size() - 1 << "\n";
      for (int i = 1; i < plan.size(); ++i) {
        std::cout << plan[i - 1] + 1 << " " << plan[i] << "\n";
      }
    }
  }
}