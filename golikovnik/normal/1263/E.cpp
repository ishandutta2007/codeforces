//  Copyright 2019 Nikita Golikov
 
#include <bits/stdc++.h>
 
#define BITSET_ITER(i, bt) for (auto i = bt._Find_first(); i != bt.size();\
i = bt._Find_next(i))
 
using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::queue;
using std::deque;
using std::stack;
using std::string;
using std::map;
using std::set;
using std::pair;
using std::tuple;
using std::unique_ptr;
using std::shared_ptr;
using std::unordered_map;
using std::unordered_set;
using std::multiset;
using std::sort;
using std::reverse;
using std::function;
using std::make_pair;
using std::make_tuple;
using i32 = std::int32_t;
using ui32 = std::uint32_t;
using i64 = std::int64_t;
using ui64 = std::uint64_t;
 
#ifdef GOLIKOV
std::mt19937 rng(566);
#else
std::mt19937 rng(static_cast<unsigned>(std::chrono::high_resolution_clock::now()
.time_since_epoch().count()));
#endif
 
template <typename T>
T rnd(T l, T r) {
  if constexpr (std::is_integral_v<T>) {
    return std::uniform_int_distribution<T>(l, r)(rng);
  } else {
    return std::uniform_real_distribution<T>(l, r)(rng);
  }
}
 
template <typename T>
auto make_vector() {
  return T();
}
 
template <typename T, typename... Args>
auto make_vector(size_t n, Args... args) {
  return vector(n, make_vector<T>(args...));
}
 
template <typename... Args>
void read(Args& ... args) {
  (cin >> ... >> args);
}
 
constexpr bool golikov() {
#ifdef GOLIKOV
  return true;
#else
  return false;
#endif
}
 
template <bool flush = false>
void print() {
  if constexpr (golikov() || flush) {
    cout << std::endl;
  } else {
    cout << '\n';
  }
}
 
template <bool flush = false, typename T, typename... Args>
void print(T const& x, Args const& ... args) {
  cout << x;
  if constexpr (sizeof...(args)) {
    cout << ' ';
  }
  print<flush>(args...);
}
 
int main() {
  if constexpr (golikov()) {
    std::freopen("in", "rt", stdin);
  }
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int n;
  cin >> n;
  int pw = 1;
  while (pw < n) {
    pw *= 2;
  }
 
  struct node {
    int bal{};
    int min_bal{};
    int max_bal{};
  };
  vector<node> tree(2 * pw);
  auto join = [](node const& a, node const& b) {
    auto min = std::min(a.min_bal, a.bal + b.min_bal);
    auto max = std::max(a.max_bal, a.bal + b.max_bal);
    return node{a.bal + b.bal, min, max};
  };
  auto update = [&](int pos, char ch) {
    int new_bal = ch == '(' ? 1 : ch == ')' ? -1 : 0;
    node to_set{new_bal, std::min(0, new_bal), std::max(0, new_bal)};
    for (tree[pos += pw] = to_set; pos /= 2; ) {
      tree[pos] = join(tree[2 * pos], tree[2 * pos + 1]);
    }
  };
  int pos = 0;
  for (int qi = 0; qi < n; ++qi) {
    char ch;
    cin >> ch;
    if (ch == 'L') {
      if (pos) {
        pos--;   
      }
    } else if (ch == 'R') {
      pos++;
    } else {
      update(pos, ch);
    }
    auto& nd = tree[1];
    cout << (nd.min_bal < 0 || nd.bal ? -1 : nd.max_bal) << ' ';
  }
  print();
  return 0;
}