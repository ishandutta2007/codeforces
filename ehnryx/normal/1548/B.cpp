#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

// START #include "../../../lca/data_structure/segment_tree.h"

template <class Node_t, typename Query_t, bool push = true, bool break_cond = false>
struct segment_tree {
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
      data[i].pull(data[2*i], data[2*i + 1]);
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
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if(l <= mid) __update(l, r, 2*i, first, mid, args...);
    if(mid < r) __update(l, r, 2*i + 1, mid + 1, last, args...);
    data[i].pull(data[2*i], data[2*i + 1]);
  }

  template <class... Args>
  Query_t query_range(int l, int r, const Args&... args) {
    return query(l, r, args...);
  }
  template <class... Args>
  Query_t query(int l, int r, const Args&... args) {
    if (r < l) return Node_t::default_value();
    if (l < 0 || lim <= r) throw invalid_argument("query range out of bounds");
    return __query(l, r, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query(int l, int r, int i, int first, int last, const Args&... args) {
    if (l <= first && last <= r) return data[i].get(args...);
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
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
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) __update_point(x, 2*i, first, mid, args...);
    else __update_point(x, 2*i + 1, mid + 1, last, args...);
    data[i].pull(data[2*i], data[2*i + 1]);
  }

  template <class... Args>
  Query_t query_point(int x, const Args&... args) {
    if (x < 0 || lim <= x) throw invalid_argument("query_point index out of bounds");
    return __query_point(x, 1, 0, length - 1, args...);
  }
  template <class... Args>
  Query_t __query_point(int x, int i, int first, int last, const Args&... args) {
    if (first == last) return data[i].get(args...);
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    if (x <= mid) return __query_point(x, 2*i, first, mid, args...);
    else return __query_point(x, 2*i + 1, mid + 1, last, args...);
  }

  template <class... Args>
  void update_up(int x, const Args&... args) {
    static_assert(!push);
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
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
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
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
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
    if constexpr (push) data[i].push(data[2*i], data[2*i + 1]);
    int mid = (first + last) / 2;
    int res = (mid < r ? __search_right(l, r, 2*i + 1, mid + 1, last, args) : lim);
    if (res == lim && l <= mid) res = __search_right(l, r, 2*i, first, mid, args);
    return res;
  }
};

// END #include "../../../lca/data_structure/segment_tree.h"

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
using ordered_set = __gnu_pbds::tree<T,
      __gnu_pbds::null_type,
      less<T>,
      __gnu_pbds::rb_tree_tag,
      __gnu_pbds::tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
using pt = complex<ld>;

constexpr char nl = '\n';
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr int MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

struct node {
  ll v;
  node(ll _v = 1): v(abs(_v)) {}
  ll get() const { return v; }
  void pull(const node& a, const node& b) { v = gcd(a.v, b.v); }
  void push(node&, node&) const {}
  static ll merge(ll a, ll b) { return gcd(a, b); }
  static ll default_value() { return 0; }
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

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) {
      cin >> a[i];
    }

    vector<ll> diff;
    adjacent_difference(begin(a), end(a), back_inserter(diff));
    segment_tree<node, ll> st(diff);

    int ans = 1;
    for(int i=1, j=1; i<n; i++) {
      while(j <= i && st.query(j, i) == 1) {
        j++;
      }
      ans = max(ans, i-j + 2);
    }
    cout << ans << nl;
  }

  return 0;
}