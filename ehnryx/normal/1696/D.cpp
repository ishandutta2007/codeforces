#include <bits/stdc++.h>
using namespace std;

//%:include "utility/defines.h"
//%:include "utility/fast_input.h"
//%:include "utility/output.h"

// START %:include "ds/range_minimum_query.h"

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

// END %:include "ds/range_minimum_query.h"

using ll = long long;
using ld = long double;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    range_minimum_query<pair<int, int>> smin(a);
    range_minimum_query<pair<int, int>, greater<>> smax(a);
    int cnt = 0;
    for(int i=0; i!=n-1; ) {
      int l = i+1;
      int r = n-1;
      while(l < r) {
        int m = (l+r + 1) / 2;
        int bot = smin.query(i, m).first;
        int top = smax.query(i, m).first;
        if(top == a[i].first || bot == a[i].first) {
          l = m;
        } else {
          r = m-1;
        }
      }
      i = max(smax.query(i, r).second, smin.query(i, r).second);
      cnt++;
    }
    cout << cnt << nl;
  }

  return 0;
}