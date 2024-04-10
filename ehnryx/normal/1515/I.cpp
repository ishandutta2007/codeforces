#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

// START %:include "data_structure/segment_tree.h"

// START #include "../utility/member_function_checker.h"

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
        //&& !apply(&Node_t::contains, std::tuple_cat(std::tuple(data[i]), args))) return lim;
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
    return __search_right(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int search_right_mutable(int l, int r, Args&... args) {
    if (r < l) return lim;
    if (l < 0 || lim <= r) throw std::invalid_argument("search_right range out of bounds");
    return __search_right(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int __search_right(int l, int r, int i, int first, int last, std::tuple<Args&...> args) {
    if (l <= first && last <= r
        && !apply(&Node_t::contains, std::tuple_cat(std::tuple(data[i]), args))) return lim;
    if (first == last) return first;
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    int res = (mid < r ? __search_right(l, r, 2*i + 1, mid + 1, last, args) : lim);
    if (res == lim && l <= mid) res = __search_right(l, r, 2*i, first, mid, args);
    return res;
  }
};

// END %:include "data_structure/segment_tree.h"
// START %:include "data_structure/fenwick_tree.h"

#include <vector>
#include <stdexcept>

template <typename T>
struct fenwick_tree {
  int n, logn;
  std::vector<T> data;
  T& operator [] (int i) { return data[i]; }
  fenwick_tree(int _n): n(_n), logn(31 - __builtin_clz(n)), data(n + 1) {}
  fenwick_tree(const std::vector<T>& arr):
    n((int)arr.size()), logn(31 - __builtin_clz(n)), data(n + 1) {
    for (int i = 0; i < n; i++) {
      update(i, arr[i]);
    }
  }
  T query_point(int r) const { return query(r, r); }
  T query_range(int l, int r) const { return query(l, r); }
  T query(int l, int r) const { return query(r) - query(l - 1); }
  T query(int r) const {
    if (r <= -1) return 0;
    if (r >= n) throw std::invalid_argument("query index out of bounds");
    T res(0);
    for (r += 1; r > 0; r -= r & -r) {
      res += data[r];
    }
    return res;
  }
  void update_point(int i, const T& v) { update(i, v); }
  void insert(int i, const T& v = T(1)) { update(i, v); }
  void update(int i, const T& v) {
    if (i < 0 || n <= i) throw std::invalid_argument("update index out of bounds");
    for (i += 1; i <= n; i += i & -i) {
      data[i] += v;
    }
  }
  int lower_bound(T v) const {
    int res = 0;
    T prefix(0);
    for (int i = logn; i >= 0; i--) {
      if (res + (1 << i) <= n && prefix + data[res + (1 << i)] < v) {
        res += 1 << i;
        prefix += data[res];
      }
    }
    return res;
  }
};

// END %:include "data_structure/fenwick_tree.h"

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

const int L = 18;
const int N = 1 << 18;

struct Sum {
  ll value;
  Sum() = default;
  ll get() const { return value; }
  void put(ll v) { value += v; }
  void pull(const Sum& a, const Sum& b) { value = a.value + b.value; }
  bool contains(ll& cap) {
    if(value <= cap) {
      cap -= value;
      return false;
    } else {
      return true;
    }
  }
  static ll default_value() { return 0; }
  static ll merge(ll a, ll b) { return a + b; }
};

struct Node {
  ll value, lazy;
  Node() = default;
  ll get() const { return value; }
  void put(ll v) {
    value += v;
    lazy += v;
  }
  void pull(const Node& a, const Node& b) {
    value = min(a.value, b.value);
  }
  void push(Node& a, Node& b) {
    if(lazy) {
      a.put(lazy);
      b.put(lazy);
      lazy = 0;
    }
  }
  bool contains(ll cap) {
    return value <= cap;
  }
};

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;

  vector<ll> a(n);
  vector<int> w(n), v(n);
  vector<tuple<int,int,int>> order;
  for(int i=0; i<n; i++) {
    cin >> a[i] >> w[i] >> v[i];
    order.emplace_back(-v[i], w[i], i);
  }
  sort(begin(order), end(order));
  vector<int> remap(n);
  for(int i=0; i<n; i++) {
    remap[get<2>(order[i])] = i;
  }

  // build trees
  vector values(L, segment_tree<Sum, ll>(n));
  vector weights(L, segment_tree<Sum, ll>(n));
  //vector values(L, fenwick_tree<ll>(n));
  //vector weights(L, fenwick_tree<ll>(n));
  vector equal(L, segment_tree<Node, ll>(n));
  for(int i=0; i<n; i++) {
    // (v[i], w[i]) at remap[i]
    int id = remap[i];
    ll weight = a[i] * w[i];
    ll value = a[i] * v[i];
    for(int j=0; j<L; j++) {
      if(w[i] < 1 << j) {
        values[j].update_point(id, value);
        weights[j].update_point(id, weight);
        //values[j].update(id, value);
        //weights[j].update(id, weight);
        equal[j].update(id, n-1, weight);
      }
      if(1 << j <= w[i] && w[i] < 1 << (j+1)) {
        equal[j].update(id, id, w[i] + (a[i] == 0 ? INFLL : 0));
      } else {
        equal[j].update(id, id, INFLL);
      }
    }
  }

  function<void(int,int)> update = [&](int i, ll cnt) {
    int id = remap[i];
    ll weight = cnt * w[i];
    ll value = cnt * v[i];
    for(int j=0; j<L; j++) {
      if(w[i] < 1 << j) {
        values[j].update_point(id, value);
        weights[j].update_point(id, weight);
        //values[j].update(id, value);
        //weights[j].update(id, weight);
        equal[j].update(id, n-1, weight);
      }
      if(1 << j <= w[i] && w[i] < 1 << (j+1)) {
        if(a[i] + cnt == 0) {
          equal[j].update(id, id, INFLL);
        } else if(a[i] == 0) {
          equal[j].update(id, id, -INFLL);
        }
      }
    }
    a[i] += cnt;
  };

  // solver
  function<ll(int,ll,int)> solve = [&](int lvl, ll cap, int s) -> ll {
    if(lvl < 0 || s >= n) return 0;
    if(cap < 1 << lvl) return solve(lvl - 1, cap, s);
    ll prefix = weights[lvl].query(0, s - 1);
    int small = weights[lvl].search_left(s, n - 1, cap);
    //int small = weights[lvl].lower_bound(cap + prefix + 1);
    int big = equal[lvl].search_left(s, n - 1, cap + prefix);
    if(small == n && big == n) { // take everything
      return values[lvl].query(s, n - 1);
    } else if(big < small) { // take the big one
      int j = get<2>(order[big]);
      cap -= weights[lvl].query(s, big) + w[j];
      return values[lvl].query(s, big) + v[j] + solve(lvl - 1, cap, big + 1);
    } else { // take the small ones
      int j = get<2>(order[small]);
      cap -= weights[lvl].query(s, small - 1);
      ll take = cap / w[j];
      return values[lvl].query(s, small - 1) + take * v[j]
        + solve(lvl - 1, cap - take * w[j], small + 1);
    }
  };

  for(int i=0; i<m; i++) {
    int t;
    cin >> t; if(t == 1) {
      int k, d;
      cin >> k >> d;
      update(d - 1, k);
    } else if(t == 2) {
      int k, d;
      cin >> k >> d;
      update(d - 1, -k);
    } else {
      ll cap;
      cin >> cap;
      cout << solve(L - 1, cap, 0) << nl;
    }
  }

  return 0;
}