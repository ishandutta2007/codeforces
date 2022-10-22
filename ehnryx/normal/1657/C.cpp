#include <bits/stdc++.h>
using namespace std;

//%:include "utility/fast_input.h"
//%:include "utility/output.h"

// START %:include "string/suffix_array_lcp.h"

// START #include "suffix_array.h"

#include <numeric>
#include <string>
#include <vector>

template <typename T>
struct suffix_array {
  std::vector<int> sa, rank, height;
  int operator [] (int i) const { return sa[i]; }

  suffix_array(const std::basic_string<T>& s) {
    int n = (int)size(s) + 1;
    std::vector<int> t(n);
    copy(begin(s), end(s), begin(t));
    sa = build(t, *max_element(begin(t), end(t)) + 1);
    // generate rank of suffix in sorted order
    rank.resize(n);
    for (int i = 0; i < n; i++) {
      rank[sa[i]] = i;
    }
    // generate heights of the lcp histogram
    height.resize(n);
    for (int i = 0, h = 0; i < n; i++) {
      if (rank[i] == 0) continue;
      int j = sa[rank[i] - 1];
      while (i + h < n && j + h < n && t[i + h] == t[j + h]) {
        h++;
      }
      height[rank[i]] = h;
      if (h > 0) {
        h--;
      }
    }
  }

  std::vector<int> build(const std::vector<int>& s, int A) {
    int n = (int)size(s);
    // get type and lms indices
    std::vector<bool> ltype(n);
    std::vector<int> lms;
    for (int i = n - 2; i >= 0; i--) {
      ltype[i] = (s[i] > s[i + 1] || (s[i] == s[i + 1] && ltype[i + 1]));
      if (ltype[i] && !ltype[i + 1]) {
        lms.push_back(i + 1);
      }
    }
    reverse(begin(lms), end(lms));
    // induced_sort
    std::vector<int> suf = induced_sort(s, ltype, lms, A);
    // get lms order
    std::vector<int> lms_order(size(lms));
    for (int i = 0, j = 0; i < n; i++) {
      if (suf[i] > 0 && ltype[suf[i] - 1] && !ltype[suf[i]]) {
        lms_order[j++] = suf[i];
      }
    }
    // name lms substrings
    int name = 0;
    suf[n - 1] = 0;
    for (int i = 1; i < (int)size(lms); i++) {
      bool diff = false;
      for (int j = 0; ; j++) {
        if (s[lms_order[i] + j] != s[lms_order[i - 1] + j]
            || ltype[lms_order[i] + j] != ltype[lms_order[i - 1] + j]) {
          diff = true;
          break;
        } else if (j > 0 && ((ltype[lms_order[i] + j - 1] && !ltype[lms_order[i] + j])
              || (ltype[lms_order[i - 1] + j - 1] && !ltype[lms_order[i - 1] + j]))) {
          break;
        }
      }
      name += diff;
      suf[lms_order[i]] = name;
    }
    // recurse if not unique
    if (name + 1 < (int)size(lms)) {
      std::vector<int> s_lms(size(lms));
      for (int i = 0; i < (int)size(lms); i++) {
        s_lms[i] = suf[lms[i]];
      }
      std::vector<int> suf_lms = build(s_lms, name + 1);
      for (int i = 0; i < (int)size(lms); i++) {
        lms_order[i] = lms[suf_lms[i]];
      }
    }
    // induced_sort
    return induced_sort(s, ltype, lms_order, A);
  }

  std::vector<int> induced_sort(
      const std::vector<int>& s, const std::vector<bool>& ltype,
      const std::vector<int>& idx, int A) {
    std::vector<int> suf(size(s), -1);
    std::vector<int> left(A), right(A), r2(A);
    for (int c : s) {
      right[c] += 1;
    }
    std::partial_sum(begin(right), end(right), begin(right));
    std::copy(begin(right), end(right) - 1, begin(left) + 1);
    std::copy(begin(right), end(right), begin(r2));
    for (int i = (int)size(idx) - 1; i >= 0; i--) {
      suf[--right[s[idx[i]]]] = idx[i];
    }
    for (int i = 0; i < (int)size(s); i++) {
      if (suf[i] > 0 && ltype[suf[i] - 1]) {
        suf[left[s[suf[i] - 1]]++] = suf[i] - 1;
      }
    }
    for (int i = (int)size(s) - 1; i >= 0; i--) {
      if (suf[i] > 0 && !ltype[suf[i] - 1]) {
        suf[--r2[s[suf[i] - 1]]] = suf[i] - 1;
      }
    }
    return suf;
  }
};

// END #include "suffix_array.h"
// START #include "../data_structure/range_minimum_query.h"

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
  template <class Compare>
  struct min<void, Compare> {
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
  template <class Compare>
  struct max<void, Compare> {
    template <typename input_t>
    input_t operator () (const input_t& a, const input_t& b) const {
      return std::max(a, b, std::less<>());
    }
  };

  // keep
  template <typename T = void>
  struct keep {
    T operator () (const T& old_v, const T&) const {
      return old_v;
    }
  };
  template <>
  struct keep<void> {
    template <typename input_t>
    input_t operator () (const input_t& old_v, const input_t&) const {
      return old_v;
    }
  };

  // replace
  template <typename T = void>
  struct replace {
    T operator () (const T&, const T& new_v) const {
      return new_v;
    }
  };
  template <>
  struct replace<void> {
    template <typename input_t>
    input_t operator () (const input_t&, const input_t& new_v) const {
      return new_v;
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

// END #include "../data_structure/range_minimum_query.h"

template <typename T>
struct suffix_array_lcp : suffix_array<T>, range_minimum_query<int> {
  suffix_array_lcp(const std::basic_string<T>& s):
    suffix_array<T>(s), range_minimum_query<int>(suffix_array<T>::height) {}
  int lcp(int i, int j) const {
    if(i == j) return (int)this->sa.size() - 1 - i;
    int l = min(this->rank[i], this->rank[j]);
    int r = max(this->rank[i], this->rank[j]);
    return range_minimum_query<int>::query(l + 1, r);
  }
  int operator [] (int i) { return suffix_array<T>::operator [] (i); }
};

// END %:include "string/suffix_array_lcp.h"
// START %:include "ds/segment_tree.h"

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
// START %:include "ds/segment_tree_nodes_min.h"

#include <functional>

namespace segment_node {

  template <typename T, typename Compare = std::less<>>
  struct custom_update_range_min {
    using out_t = T;
    T min;
    custom_update_range_min() = default;
    custom_update_range_min(T v): min(v) {}
    out_t get() const { return min; }
    void pull(const custom_update_range_min& left, const custom_update_range_min& right) {
      min = std::min(left.min, right.min, Compare());
    }
    static out_t merge(out_t left, out_t right) { return std::min(left, right, Compare()); }
  };

}

// END %:include "ds/segment_tree_nodes_min.h"

using ll = long long;
using ld = long double;

constexpr char nl = '\n';
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());


using segtree = segment_tree<segment_node::custom_update_range_min<int>>;

#define MULTI_TEST
void solve_main([[maybe_unused]] int testnum, [[maybe_unused]] auto& cin) {
  int n;
  cin >> n;
  string s;
  cin >> s;

  // for correct brackets
  vector<int> heights(n + 1);
  for(int i=0; i<n; i++) {
    heights[i+1] = heights[i] + (s[i] == '(' ? 1 : -1);
  }
  segtree st(heights);

  auto correct = [&](int i, int len) -> bool {
    return heights[i] == heights[i+len] && st.query(i, i+len) == heights[i];
  };

  // for palindromes
  string rev_s(rbegin(s), rend(s));
  suffix_array_lcp sa(s + rev_s);

  auto palindrome = [&](int i, int len) -> bool {
    int lmid = i + len / 2 - 1;
    int rmid = i + (len+1) / 2;
    return sa.lcp(rmid, 2*n - 1 - lmid) >= len/2;
  };


  int cnt = 0;
  int at = 0;
  while(true) {
    bool found = false;
    for(int len=2; len<=n-at; len++) {
      if(palindrome(at, len) || correct(at, len)) {
        at += len;
        found = true;
        break;
      }
    }
    if(!found) {
      break;
    }
    cnt++;
  }

  cout << cnt << " " << n - at << nl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#ifdef USING_FAST_INPUT
  fast_input cin;
#endif

  int T = 1;
#ifdef MULTI_TEST
  cin >> T;
#endif
  for(int testnum=1; testnum<=T; testnum++) {
    solve_main(testnum, cin);
  }

  return 0;
}