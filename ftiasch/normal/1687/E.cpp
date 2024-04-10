#line 1 "sieve.h"
#include <vector>

struct PrimeGen : public std::vector<int> {
  PrimeGen(int m) : std::vector<int>(), min_div_(m, -1) {
    for (int d = 2; d < m; ++d) {
      if (min_div_[d] == -1) {
        min_div_[d] = d;
        push_back(d);
      }
      for (int p : *this) {
        if (d * p >= m) {
          break;
        }
        min_div_[p * d] = p;
        if (d % p == 0) {
          break;
        }
      }
    }
  }

  int min_div(int n) const { return min_div_[n]; }

  bool is_prime(int n) const { return min_div(n) == n; }

private:
  std::vector<int> min_div_;
};
#line 1 "util.h"
#include <iostream>
#include <queue>
#line 4 "util.h"

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

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
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 3 "/tmp/tmp-1163071jJaP8L22YL.cpp"

// #include "debug.h"

#include <bits/stdc++.h>

struct Reduction {
  Reduction(std::vector<std::pair<int, int>> &&candidates_)
      : n(candidates_.size()), candidates{std::move(candidates_)} {}

  std::vector<int> operator()() const {
    Long v = gcd((1 << n) - 1);
    std::pair<int, int> best(INT_MAX, 0);
    for (int mask = 0; mask < 1 << n; ++mask) {
      if (gcd(mask) == v) {
        best = std::min(best, {__builtin_popcount(mask), mask});
      }
    }
    std::vector<int> result;
    for (int i = 0; i < n; ++i) {
      if (best.second >> i & 1) {
        result.push_back(candidates[i].first);
      }
    }
    return result;
  }

  Long gcd(int mask) const {
    Long result = 0;
    for (int i = 0; i < n; ++i) {
      if (mask >> i & 1) {
        for (int j = i + 1; j < n; ++j) {
          if (mask >> j & 1) {
            result = std::__gcd(result, 1LL * candidates[i].second *
                                            candidates[j].second);
          }
        }
      }
    }
    return result;
  }

  int n;
  std::vector<std::pair<int, int>> candidates;
};

int main() {
  IO io;
  int n = io.read();
  auto a = io.read_vector(n);
  int m = *std::ranges::max_element(a);
  PrimeGen primes(m + 1);
  std::map<int, std::vector<std::pair<int, int>>> exponents;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    while (x > 1) {
      int p = primes.min_div(x);
      int e = 0;
      while (x % p == 0) {
        x /= p;
        e++;
      }
      exponents[p].emplace_back(e, i);
    }
  }
  // std::cerr << KV(exponents) << std::endl;
  std::vector<std::pair<int, int>> candidates;
  candidates.emplace_back(0, a[0]);
  candidates.emplace_back(1, a[1]);
  for (auto &[p, indices] : exponents) {
    int needs = (a[0] % p == 0) + (a[1] % p == 0);
    if (needs > 0) {
      std::vector<std::pair<int, int>> best;
      auto iterator = indices.begin();
      while (iterator != indices.end() && iterator->second < 2) {
        iterator++;
      }
      for (int i = 2; i < n; ++i) {
        std::pair<int, int> p;
        if (iterator != indices.end() && iterator->second == i) {
          p = *iterator;
          iterator++;
        } else {
          p = {0, i};
        }
        best.push_back(p);
        std::ranges::sort(best);
        if (best.size() > needs) {
          best.pop_back();
        }
      }
      for (auto [_, i] : best) {
        candidates.emplace_back(i, a[i]);
      }
    }
  }
  std::ranges::sort(candidates);
  candidates.erase(std::unique(ALL(candidates)), candidates.end());
  // std::cerr << KV(candidates) << std::endl;
  auto reduced = Reduction(std::move(candidates))();
  int length = 0;
  for (int mask = 1; mask < 1 << reduced.size(); ++mask) {
    std::vector<int> indices;
    for (int i = 0; i < reduced.size(); ++i) {
      if (mask >> i & 1) {
        indices.push_back(reduced[i]);
      }
    }
    int ones = __builtin_popcount(mask);
    int count = (ones & 1 ? -1 : 1) * (ones - 2);
    length += std::abs(count);
  }
  std::cout << length << "\n";
  for (int mask = 1; mask < 1 << reduced.size(); ++mask) {
    std::vector<int> indices;
    for (int i = 0; i < reduced.size(); ++i) {
      if (mask >> i & 1) {
        indices.push_back(reduced[i]);
      }
    }
    int ones = indices.size();
    int count = (ones & 1 ? -1 : 1) * (ones - 2);
    while (count != 0) {
      std::cout << "01"[count < 0] << " " << indices.size();
      if (count < 0) {
        count++;
      } else {
        count--;
      }
      for (int i : indices) {
        std::cout << " " << i + 1;
      }
      std::cout << "\n";
    }
  }
}