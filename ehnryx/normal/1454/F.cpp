#include <bits/stdc++.h>
using namespace std;

// START #include "../range_minimum_query.h"

// START #include "../utility/utility.h"

#include <algorithm>

namespace utility {

  // functional form of std::min

  template <typename T = void, class Compare = std::less<>>
  struct min {
    T operator () (const T& a, const T& b) const {
      return std::min<T>(a, b, Compare());
    }
  };
  template <>
  struct min<void, std::less<>> {
    template <typename input_t>
    input_t operator () (const input_t& a, const input_t& b) const {
      return std::min(a, b, std::less<>());
    }
  };

  // functional form of std::max

  template <typename T = void, class Compare = std::less<>>
  struct max {
    T operator () (const T& a, const T& b) const {
      return std::max<T>(a, b, Compare());
    }
  };
  template <>
  struct max<void, std::less<>> {
    template <typename input_t>
    input_t operator () (const input_t& a, const input_t& b) const {
      return std::max(a, b, std::less<>());
    }
  };

}

// END #include "../utility/utility.h"
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, class Func>
struct rmq_functional {
  std::vector<std::vector<T>> rmq;
  rmq_functional() = default;
  rmq_functional(const std::vector<T>& arr) {
    int n = (int)arr.size();
    int L = 32 - __builtin_clz(n);
    rmq.resize(L);
    rmq.front() = arr;
    build(n, L);
  }
  rmq_functional(std::vector<T>&& arr) {
    int n = (int)arr.size();
    int L = 32 - __builtin_clz(n);
    rmq.resize(L);
    rmq.front() = move(arr);
    build(n, L);
  }
  T query(int l, int r) const {
    if (l > r) throw std::invalid_argument("The range is empty, ie. l > r");
    int j = 31 - __builtin_clz(r + 1 - l);
    return Func()(rmq[j][l], rmq[j][r + 1 - (1<<j)]);
  }

private:
  void build(int n, int L) {
    for (int j = 1; j < L; j++) {
      rmq[j].resize(n - (1 << j) + 1);
      for (int i = 0; i + (1 << j) <= n; i++) {
        rmq[j][i] = Func()(rmq[j-1][i], rmq[j-1][i + (1<<(j-1))]);
      }
    }
  }
};

template <typename T, class Compare = std::less<>>
using range_minimum_query = rmq_functional<T, utility::min<T, Compare>>;

// END #include "../range_minimum_query.h"

constexpr char nl = '\n';

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    range_minimum_query rmq_min(a);
    range_minimum_query<int, greater<>> rmq_max(a);

    bool ok = false;
    for (int i = 1; !ok && i <= n - 2; i++) {
      int val = rmq_max.query(0, i - 1);
      int l = i + 1;
      int r = n - 1;
      while(l + 1 < r) {
        int m = (l + r) / 2;
        if (rmq_min.query(i, m - 1) > val) {
          l = m + 1;
        } else if (rmq_min.query(i, m - 1) < val) {
          r = m - 1;
        } else if (rmq_max.query(m, n - 1) < val) {
          r = m - 1;
        } else if (rmq_max.query(m, n - 1) > val) {
          l = m + 1;
        } else {
          r = m;
        }
      }
      for (int j = l; j <= r; j++) {
        if (val == rmq_min.query(i, j - 1) && val == rmq_max.query(j, n - 1)) {
          ok = true;
          cout << "YES" << nl;
          cout << i << " " << j - i << " " << n - j << nl;
          break;
        }
      }
    }
    if(!ok) {
      cout << "NO" << nl;
    }
  }

  return 0;
}