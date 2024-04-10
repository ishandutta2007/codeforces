#include <bits/stdc++.h>
using namespace std;

// START %:include "utility/fast_input.h"

// START #include "member_function_checker.h"

#define MEMBER_FUNCTION_CHECKER(FUNCTION) \
  template <typename __class_t, typename... __args_t> \
  struct _has_##FUNCTION { \
    template <typename __class> \
    static constexpr auto check(__class*) -> \
      typename std::is_void<std::void_t< \
        decltype(std::declval<__class&>().FUNCTION(std::declval<__args_t>()...))>>::type; \
    template <typename __dummy> \
    static constexpr auto check(...) -> std::false_type; \
    using type = decltype(check<__class_t>(0)); \
    static constexpr bool value = type::value; \
  }

// END #include "member_function_checker.h"

#include <complex>
#include <string>
#include <tuple>
#include <vector>

#define USING_FAST_INPUT

template <size_t buf_size = 10000>
struct fast_input {
  char buf[buf_size], *S, *T, c = 0;
  int positive;
  FILE* ifptr;
  fast_input(FILE* _in = stdin): S(buf), T(buf), ifptr(_in) {}

  explicit operator bool() const { return c != EOF; }

  inline char getc(void) {
    if (c == EOF) return EOF;
    if (S == T) {
      T = (S = buf) + fread(buf, 1, buf_size, ifptr);
      if (S == T) return c = EOF;
    }
    return *S++;
  }

  inline void get(char& x) {
    while (isspace(x = getc()) && x != EOF);
  }

  inline void get(std::string& x) {
    x.clear();
    while (isspace(c = getc()) && c != EOF);
    for (; !isspace(c) && c != EOF; c = getc()) {
      x.push_back(c);
    }
  }

  inline void get(decltype(std::ignore)) {
    while (isspace(c = getc()) && c != EOF);
    for (; !isspace(c) && c != EOF; c = getc());
  }

  template <typename var_t, std::enable_if_t<std::is_integral_v<var_t>, bool> = true>
  inline void get(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc()) && c != EOF) {
      positive = (c ^ '-');
    }
    for (; isdigit(c) && c != EOF; c = getc()) {
      x = x * 10 + c - '0';
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename var_t, std::enable_if_t<std::is_floating_point_v<var_t>, bool> = true>
  inline void get(var_t& x) {
    x = 0;
    positive = 1;
    while (!isdigit(c = getc()) && c != '.' && c != EOF) {
      positive = (c ^ '-');
    }
    if (c != '.') {
      for (; isdigit(c) && c != EOF; c = getc()) {
        x = x * 10 + c - '0';
      }
    }
    if (c == '.') {
      static var_t div;
      div = 1;
      while (isdigit(c = getc()) && c != EOF) {
        x = x * 10 + c - '0';
        div *= 10;
      }
      x /= div;
    }
    if (!positive) {
      x = -x;
    }
  }

  template <typename T>
  inline void get(std::complex<T>& x) {
    x.real(getv<T>());
    x.imag(getv<T>());
  }

  template <typename T, typename U>
  inline void get(std::pair<T, U>& x) {
    *this >> x.first >> x.second;
  }

  template <size_t index = 0, typename... T>
  inline void get(std::tuple<T...>& x) {
    if constexpr (index < sizeof...(T)) {
      *this >> (std::get<index>(x));
      get<index + 1>(x);
    }
  }

  MEMBER_FUNCTION_CHECKER(get);

  template <typename T>
  inline fast_input& operator >> (T& x) {
    if constexpr (_has_get<fast_input, T&>::value) {
      get(x);
    } else {
      x.fast_read(*this);
    }
    return *this;
  }

  std::string getline() {
    std::string out;
    while ((c = getc()) != '\n' && c != EOF) {
      out.push_back(c);
    }
    return out;
  }

  std::vector<std::string> readlines(int n) {
    std::vector<std::string> out;
    out.reserve(n);
    for (int i = 0; i < n; i++) {
      out.push_back(getline());
    }
    return out;
  }

  template <typename T>
  T getv() {
    T x;
    *this >> x;
    return x;
  }

  template <typename T, int pad_n = 0>
  std::vector<T> read(int n) {
    return readinit<T, pad_n>(n, T());
  }

  template <typename T, int pad_n = 0, int pad_m = 0>
  std::vector<std::vector<T>> read(int n, int m) {
    return readinit<T, pad_n, pad_m>(n, m, T());
  }

  template <typename T, int pad_n = 0, int pad_m = 0, int pad_h = 0>
  std::vector<std::vector<std::vector<T>>> read(int n, int m, int h) {
    return readinit<T, pad_n, pad_m, pad_h>(n, m, h, T());
  }

  template <typename T, int pad_n = 0>
  std::vector<T> readinit(int n, T init) {
    std::vector<T> out(n + 2 * pad_n, init);
    for (int i = 0; i < n; i++) {
      *this >> out[pad_n + i];
    }
    return out;
  }

  template <typename T, int pad_n = 0, int pad_m = 0>
  std::vector<std::vector<T>> readinit(int n, int m, T init) {
    std::vector out(n + 2 * pad_n, std::vector<T>(m + 2 * pad_m, init));
    for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        *this >> out[pad_n + i][pad_m + j];
      }
    }
    return out;
  }

  template <typename T, int pad_n = 0, int pad_m = 0, int pad_h = 0>
  std::vector<std::vector<std::vector<T>>> readinit(int n, int m, int h, T init) {
    std::vector out(n + 2 * pad_n, std::vector(m + 2 * pad_m,
          std::vector<T>(h + 2 * pad_h, init)));
    for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        for (int k = 0; k < h; k++) {
          *this >> out[pad_n + i][pad_m + j][pad_h + k];
        }
      }
    }
    return out;
  }
};

// END %:include "utility/fast_input.h"
//%:include "utility/output.h"

// START %:include "ds/segment_tree.h"

// START #include "../utility/member_function_checker.h"
// already included
// END #include "../utility/member_function_checker.h"
// START #include "../utility/member_variable_checker.h"

#define MEMBER_VARIABLE_CHECKER(VARIABLE) \
  template <typename __class_t> \
  struct _has_##VARIABLE { \
    template <typename __class> \
    static constexpr auto check(__class*) -> \
      typename std::is_void<std::void_t< \
        decltype(std::declval<__class&>().VARIABLE)>>::type; \
    template <typename __dummy> \
    static constexpr auto check(...) -> std::false_type; \
    using type = decltype(check<__class_t>(0)); \
    static constexpr bool value = type::value; \
  }

// END #include "../utility/member_variable_checker.h"
// START #include "../utility/member_type_getter.h"

#define MEMBER_TYPE_GETTER(TYPE) \
  template <typename __class_t, typename __default_t, typename = void> \
  struct _get_type_##TYPE { \
    using type = __default_t; \
  }; \
  template <typename __class_t, typename __default_t> \
  struct _get_type_##TYPE<__class_t, __default_t, std::void_t<typename __class_t::TYPE>> { \
    using type = typename __class_t::TYPE; \
  }

// END #include "../utility/member_type_getter.h"

#include <cassert>
#include <stdexcept>
#include <tuple>
#include <vector>


template <class Node_t, typename __Query_t = void>
struct segment_tree {
  MEMBER_TYPE_GETTER(out_t);
  using Query_t = typename _get_type_out_t<Node_t, __Query_t>::type;
  static_assert(std::is_same_v<Query_t, __Query_t> || std::is_void_v<__Query_t>);

  MEMBER_VARIABLE_CHECKER(length);
  MEMBER_FUNCTION_CHECKER(push);
  MEMBER_FUNCTION_CHECKER(pull);
  MEMBER_FUNCTION_CHECKER(merge);
  MEMBER_FUNCTION_CHECKER(default_value);
  MEMBER_FUNCTION_CHECKER(break_condition); // TODO
  MEMBER_FUNCTION_CHECKER(put_condition); // TODO
  static constexpr bool has_push = _has_push<Node_t, Node_t&, Node_t&>::value;
  static constexpr bool has_pull = _has_pull<Node_t, Node_t, Node_t>::value;
  static constexpr bool has_merge = _has_merge<Node_t, Query_t, Query_t>::value;
  static constexpr bool has_default_value = _has_default_value<Node_t>::value;
  static constexpr bool has_length = _has_length<Node_t>::value;
  // TODO fix this
  static constexpr bool has_break_condition = _has_break_condition<Node_t>::value;
  static_assert(!_has_put_condition<Node_t>::value || has_break_condition);
  // end TODO

  int lim, length;
  std::vector<Node_t> data;
  Node_t& operator [] (int i) { return data[i]; }

  segment_tree(int n): lim(n),
    length(1 << (lim == 1 ? 0 : 32 - __builtin_clz(lim - 1))), data(2 * length) {
    if constexpr (has_length) assign_lengths();
  }
  template <class Input_t>
  segment_tree(const std::vector<Input_t>& a, int offset = 0): lim((int)size(a)),
    length(1 << (lim == 1 ? 0 : 32 - __builtin_clz(lim - 1))), data(2*length) {
    for (int i = offset; i < lim; i++) {
      data[length + i] = Node_t(a[i]);
    }
    build();
    if constexpr (has_length) assign_lengths();
  }
  void build() {
    for (int i = length - 1; i > 0; i--) {
      if constexpr (has_pull) data[i].pull(data[2*i], data[2*i + 1]);
    }
  }
  void assign_lengths() {
    for (int i = 0; i < length; i++) {
      data[i + length].length = 1;
    }
    for (int i = length - 1; i > 0; i--) {
      data[i].length = data[2 * i].length + data[2 * i + 1].length;
    }
  }

  template <class... Args>
  void update(int l, int r, const Args&... args) {
    update_range_mutable(l, r, args...);
  }
  template <class... Args>
  void update_range(int l, int r, const Args&... args) {
    update_range_mutable(l, r, args...);
  }
  template <class... Args>
  void update_range_mutable(int l, int r, Args&... args) {
    if (r < l) return;
    if (l < 0 || lim <= r) throw std::invalid_argument("update range out of bounds");
    __update(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  void __update(int l, int r, int i, int first, int last, Args&... args) {
    if constexpr (has_break_condition) {
      if (data[i].break_condition(args...)) return;
      if (l <= first && last <= r && data[i].put_condition(args...)) {
        return data[i].put(args...);
      }
      if (i >= length) {
        throw std::invalid_argument("put_condition/break_condition is incorrect, "
                               "trying to descend past a leaf");
      }
    } else {
      if (l <= first && last <= r) {
        return data[i].put(args...);
      }
    }
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if(l <= mid) __update(l, r, 2*i, first, mid, args...);
    if(mid < r) __update(l, r, 2*i + 1, mid + 1, last, args...);
    if constexpr (has_pull) data[i].pull(data[2*i], data[2*i + 1]);
  }

  template <class... Args>
  Query_t query(int l, int r, const Args&... args) {
    return query_range_mutable(l, r, args...);
  }
  template <class... Args>
  Query_t query_range(int l, int r, const Args&... args) {
    return query_range_mutable(l, r, args...);
  }
  template <class... Args>
  Query_t query_range_mutable(int l, int r, Args&... args) {
    if (r < l) {
      if constexpr (has_default_value) return Node_t::default_value();
      else assert(false);
    }
    if (l < 0 || lim <= r) throw std::invalid_argument("query range out of bounds");
    return __query(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query(int l, int r, int i, int first, int last, Args&... args) {
    if (l <= first && last <= r) return data[i].get(args...);
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if(r <= mid) return __query(l, r, 2*i, first, mid, args...);
    if(mid < l) return __query(l, r, 2*i + 1, mid + 1, last, args...);
    Query_t left = __query(l, r, 2*i, first, mid, args...);
    Query_t right = __query(l, r, 2*i + 1, mid + 1, last, args...);
    if constexpr (!has_merge && std::is_same_v<Node_t, Query_t>) {
      return Node_t().pull(left, right);
    } else {
      return Node_t::merge(left, right);
    }
  }

  template <class... Args>
  void update_point(int x, const Args&... args) {
    update_point_mutable(x, args...);
  }
  template <class... Args>
  void update_point_mutable(int x, Args&... args) {
    if (x < 0 || lim <= x) throw std::invalid_argument("update_point index out of bounds");
    __update_point(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  void __update_point(int x, int i, int first, int last, Args&... args) {
    if (first == last) return data[i].put(args...);
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) __update_point(x, 2*i, first, mid, args...);
    else __update_point(x, 2*i + 1, mid + 1, last, args...);
    if constexpr (has_pull) data[i].pull(data[2*i], data[2*i + 1]);
  }

  template <class... Args>
  Query_t query_point(int x, const Args&... args) {
    return query_point(x, args...);
  }
  template <class... Args>
  Query_t query_point_mutable(int x, Args&... args) {
    if (x < 0 || lim <= x) throw std::invalid_argument("query_point index out of bounds");
    return __query_point(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query_point(int x, int i, int first, int last, Args&... args) {
    if (first == last) return data[i].get(args...);
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) return __query_point(x, 2*i, first, mid, args...);
    else return __query_point(x, 2*i + 1, mid + 1, last, args...);
  }

  template <class... Args>
  void update_up(int x, const Args&... args) {
    update_up(x, args...);
  }
  template <class... Args>
  void update_up_mutable(int x, Args&... args) {
    static_assert(!has_push);
    if (x < 0 || lim <= x) throw std::invalid_argument("update_up index out of bounds");
    for (int i = x + length; i > 0; i /= 2) {
      data[i].put(args...);
    }
  }

  template <class... Args>
  Query_t query_up(int x, const Args&... args) {
    return query_up_mutable(x, args...);
  }
  template <class... Args>
  Query_t query_up_mutable(int x, Args&... args) {
    if (x < 0 || lim <= x) throw std::invalid_argument("query_up index out of bounds");
    return __query_up(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query_up(int x, int i, int first, int last, Args&... args) {
    if (first == last) return data[i].get(args...);
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) {
      return Node_t::merge(data[i].get(args...), __query_up(x, 2*i, first, mid, args...));
    } else {
      return Node_t::merge(data[i].get(args...), __query_up(x, 2*i + 1, mid + 1, last, args...));
    }
  }

  template <class... Args>
  int search_left(int l, int r, Args... args) {
    if (r < l) return lim;
    if (l < 0 || lim <= r) throw std::invalid_argument("search_left range out of bounds");
    return __search_left(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  int search_left_mutable(int l, int r, Args&... args) {
    if (r < l) return lim;
    if (l < 0 || lim <= r) throw std::invalid_argument("search_left range out of bounds");
    return __search_left(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  int __search_left(int l, int r, int i, int first, int last, Args&... args) {
    if (l <= first && last <= r && !data[i].contains(args...)) return lim;
    if (first == last) return first;
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    int res = (l <= mid ? __search_left(l, r, 2*i, first, mid, args...) : lim);
    if (res == lim && mid < r) res = __search_left(l, r, 2*i + 1, mid + 1, last, args...);
    return res;
  }

  template <class... Args>
  int search_right(int l, int r, Args... args) {
    if (r < l) return lim;
    if (l < 0 || lim <= r) throw std::invalid_argument("search_right range out of bounds");
    return __search_right(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  int search_right_mutable(int l, int r, Args&... args) {
    if (r < l) return lim;
    if (l < 0 || lim <= r) throw std::invalid_argument("search_right range out of bounds");
    return __search_right(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  int __search_right(int l, int r, int i, int first, int last, Args&... args) {
    if (l <= first && last <= r && !data[i].contains(args...)) return lim;
    if (first == last) return first;
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    int res = (mid < r ? __search_right(l, r, 2*i + 1, mid + 1, last, args...) : lim);
    if (res == lim && l <= mid) res = __search_right(l, r, 2*i, first, mid, args...);
    return res;
  }
};

// END %:include "ds/segment_tree.h"
// START %:include "ds/segment_tree_nodes_sum.h"

namespace segment_node {

  template <typename T>
  struct custom_update_range_sum {
    using out_t = T;
    T sum;
    custom_update_range_sum() = default;
    custom_update_range_sum(T v): sum(v) {}
    out_t get() const { return sum; }
    void pull(const custom_update_range_sum& left, const custom_update_range_sum& right) {
      sum = left.sum + right.sum;
    }
    static out_t merge(out_t left, out_t right) { return left + right; }
  };

  template <typename T>
  struct range_assign_range_sum final : custom_update_range_sum<T> {
    using Base = custom_update_range_sum<T>;
    using Base::sum;
    int length;
    bool lazy;
    range_assign_range_sum() = default;
    range_assign_range_sum(T v): Base(v), lazy(false) {}
    void put(T v) {
      sum = v * length;
      lazy = true;
    }
    void push(range_assign_range_sum& left, range_assign_range_sum& right) {
      if (lazy) {
        left.sum = right.sum = sum / 2;
        left.lazy = right.lazy = true;
        lazy = false;
      }
    }
  };

  template <typename T>
  struct range_add_range_sum final : custom_update_range_sum<T> {
    using Base = custom_update_range_sum<T>;
    using Base::sum;
    T lazy;
    int length;
    range_add_range_sum() = default;
    range_add_range_sum(T v): Base(v), lazy(v) {}
    void put(T v) {
      T add = v * length;
      lazy += add;
      sum += add;
    }
    void push(range_add_range_sum& left, range_add_range_sum& right) {
      if (lazy != T(0)) {
        T add = lazy / 2;
        left.lazy += add;
        right.lazy += add;
        left.sum += add;
        right.sum += add;
        lazy = T(0);
      }
    }
  };

}

// END %:include "ds/segment_tree_nodes_sum.h"

using ll = long long;
using ld = long double;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

using node = segment_node::range_add_range_sum<ll>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int n, m;
  cin >> n >> m;
  vector<int> a(n+1);
  for(int i=1; i<=n; i++) {
    cin >> a[i];
  }

  segment_tree<node> st(n+1);
  ll val = 0;
  for(int i=n; i>0; i--) {
    st.update_point(i, val + (n-i+1));
    if(a[i] != a[i-1]) {
      val += n-i+1;
    }
  }

  for(int i=0; i<m; i++) {
    int x, v;
    cin >> x >> v;
    // a[x] <- v
    if(1 < x) {
      int before = (a[x] != a[x-1]);
      int after = (v != a[x-1]);
      if(before != after) {
        st.update(1, x-1, (ll)(after - before) * (n-x+1));
      }
    }
    if(x < n) {
      int before = (a[x] != a[x+1]);
      int after = (v != a[x+1]);
      if(before != after) {
        st.update(1, x, (ll)(after - before) * (n-x));
      }
    }
    a[x] = v;
    //assert(st.query(1, n) == st[1].sum);
    //cout << st.query(1, n) << nl;
    cout << st[1].sum << nl;
  }

  return 0;
}