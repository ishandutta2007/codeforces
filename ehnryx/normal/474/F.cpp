#include <bits/stdc++.h>
using namespace std;

// START #include "../segment_tree.h"

// START #include "../misc/member_function_checker.h"

#define MEMBER_FUNCTION_CHECKER(function) \
  template <typename T> \
  struct _has_##function { \
    using other = struct { char x[2]; }; \
    template <typename C> static char test(decltype(&C::function)); \
    template <typename C> static other test(...); \
    enum { value = sizeof(test<T>(0)) == sizeof(char) }; \
  }

// END #include "../misc/member_function_checker.h"

template <class Node_t, typename Query_t, bool break_cond = false>
struct segment_tree {
  MEMBER_FUNCTION_CHECKER(push);
  MEMBER_FUNCTION_CHECKER(pull);
  MEMBER_FUNCTION_CHECKER(default_value);
  static constexpr bool has_push = _has_push<Node_t>::value;
  static constexpr bool has_pull = _has_pull<Node_t>::value;
  static constexpr bool has_default_value = _has_default_value<Node_t>::value;

  int lim, length;
  vector<Node_t> data;
  Node_t& operator [] (int i) { return data[i]; }

  segment_tree(int n): lim(n),
    length(1 << (lim == 1 ? 0 : 32 - __builtin_clz(lim - 1))), data(2 * length) {}
  template <class Input_t>
  segment_tree(const vector<Input_t>& a, int offset = 0): lim((int)size(a)),
    length(1 << (lim == 1 ? 0 : 32 - __builtin_clz(lim - 1))), data(2*length) {
    for (int i = offset; i < lim; i++) {
      data[length + i] = Node_t(a[i]);
    }
    build();
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
  void update_range(int l, int r, const Args&... args) {
    update(l, r, args...);
  }
  template <class... Args>
  void update(int l, int r, const Args&... args) {
    if (r < l) return;
    if (l < 0 || lim <= r) throw invalid_argument("update range out of bounds");
    __update(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  void __update(int l, int r, int i, int first, int last, const Args&... args) {
    if constexpr (break_cond) {
      if (data[i].break_condition(args...)) return;
      if (l <= first && last <= r && data[i].put_condition(args...)) {
        return data[i].put(args...);
      }
      if (i >= length) {
        throw invalid_argument("put_condition/break_condition is incorrect, "
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
  Query_t query_range(int l, int r, const Args&... args) {
    return query(l, r, args...);
  }
  template <class... Args>
  Query_t query(int l, int r, const Args&... args) {
    if (r < l) {
      if constexpr (has_default_value) return Node_t::default_value();
      assert(false);
    }
    if (l < 0 || lim <= r) throw invalid_argument("query range out of bounds");
    return __query(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query(int l, int r, int i, int first, int last, const Args&... args) {
    if (l <= first && last <= r) return data[i].get(args...);
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if(r <= mid) return __query(l, r, 2*i, first, mid, args...);
    if(mid < l) return __query(l, r, 2*i + 1, mid + 1, last, args...);
    return Node_t::merge(
        __query(l, r, 2*i, first, mid, args...),
        __query(l, r, 2*i + 1, mid + 1, last, args...));
  }

  template <class... Args>
  void update_point(int x, const Args&... args) {
    if (x < 0 || lim <= x) throw invalid_argument("update_point index out of bounds");
    __update_point(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  void __update_point(int x, int i, int first, int last, const Args&... args) {
    if (first == last) return data[i].put(args...);
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) __update_point(x, 2*i, first, mid, args...);
    else __update_point(x, 2*i + 1, mid + 1, last, args...);
    if constexpr (has_pull) data[i].pull(data[2*i], data[2*i + 1]);
  }

  template <class... Args>
  Query_t query_point(int x, const Args&... args) {
    if (x < 0 || lim <= x) throw invalid_argument("query_point index out of bounds");
    return __query_point(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query_point(int x, int i, int first, int last, const Args&... args) {
    if (first == last) return data[i].get(args...);
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) return __query_point(x, 2*i, first, mid, args...);
    else return __query_point(x, 2*i + 1, mid + 1, last, args...);
  }

  template <class... Args>
  void update_up(int x, const Args&... args) {
    static_assert(!has_push);
    if (x < 0 || lim <= x) throw invalid_argument("update_up index out of bounds");
    for (int i = x + length; i > 0; i /= 2) {
      data[i].put(args...);
    }
  }

  template <class... Args>
  Query_t query_up(int x, const Args&... args) {
    if (x < 0 || lim <= x) throw invalid_argument("query_up index out of bounds");
    return __query_up(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query_up(int x, int i, int first, int last, const Args&... args) {
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
    if (l < 0 || lim <= r) throw invalid_argument("search_left range out of bounds");
    return __search_left(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int search_left_mutable(int l, int r, Args&... args) {
    if (r < l) return lim;
    if (l < 0 || lim <= r) throw invalid_argument("search_left range out of bounds");
    return __search_left(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int __search_left(int l, int r, int i, int first, int last, tuple<Args&...> args) {
    if (l <= first && last <= r
        && !apply(&Node_t::contains, tuple_cat(tuple(data[i]), args))) return lim;
    if (first == last) return first;
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    int res = (l <= mid ? __search_left(l, r, 2*i, first, mid, args) : lim);
    if (res == lim && mid < r) res = __search_left(l, r, 2*i + 1, mid + 1, last, args);
    return res;
  }

  template <class... Args>
  int search_right(int l, int r, Args... args) {
    if (r < l) return lim;
    if (l < 0 || lim <= r) throw invalid_argument("search_right range out of bounds");
    return __search_right(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int search_right_mutable(int l, int r, Args&... args) {
    if (r < l) return lim;
    if (l < 0 || lim <= r) throw invalid_argument("search_right range out of bounds");
    return __search_right(l, r, 1, 0, length - 1, forward_as_tuple(args...));
  }
  template <class... Args>
  int __search_right(int l, int r, int i, int first, int last, tuple<Args&...> args) {
    if (l <= first && last <= r
        && !apply(&Node_t::contains, tuple_cat(tuple(data[i]), args))) return lim;
    if (first == last) return first;
    if constexpr (has_push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    int res = (mid < r ? __search_right(l, r, 2*i + 1, mid + 1, last, args) : lim);
    if (res == lim && l <= mid) res = __search_right(l, r, 2*i, first, mid, args);
    return res;
  }
};

// END #include "../segment_tree.h"

struct Node {
  int value, cnt;
  Node() = default;
  //static Node default_value() { return Node(); }
  static Node merge(const Node& a, const Node& b) { return Node().pull(a, b); }
  Node get() const { return *this; }
  void put(int v) { value = v; cnt = 1; }
  Node& pull(const Node& a, const Node& b) {
    value = gcd(a.value, b.value);
    cnt = (a.value == value) * a.cnt + (b.value == value) * b.cnt;
    return *this;
  }
};

constexpr char nl = '\n';

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  segment_tree<Node, Node> st(n + 1);
  for(int i=1; i<=n; i++) {
    int a;
    cin >> a;
    st.update(i, i, a);
  }

  int m;
  cin >> m;
  for(int i=0; i<m; i++) {
    int l, r;
    cin >> l >> r;
    cout << (r-l+1) - st.query(l, r).cnt << nl;
  }

  return 0;
}