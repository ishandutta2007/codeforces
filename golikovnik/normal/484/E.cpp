//  Copyright 2019 Nikita Golikov

#include <bits/stdc++.h>

#include <utility>

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
using i32 = std::int32_t;
using ui32 = std::uint32_t;
using i64 = std::int64_t;
using ui64 = std::uint64_t;

#ifdef GOLIKOV
std::mt19937 rng(566);
#else
std::mt19937 rng(static_cast<unsigned>(std::chrono::high_resolution_clock::now()
        .time_since_epoch()
        .count()));
#endif

template <typename T>
T rnd(T l, T r) {
  if constexpr (std::is_integral_v < T >) {
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
  return vector(n, make_vector(args...));
}

template <typename... Args>
void read(Args& ... args) {
  (cin >> ... >> args);
}

void print() {
  cout << '\n';
}

template <typename T, typename... Args>
void print(T const& x, Args const& ... args) {
  cout << x;
  if constexpr (sizeof...(args)) {
    cout << ' ';
  }
  print(args...);
}

int main() {
#ifdef GOLIKOV
  std::freopen("in", "rt", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  read(n);
  vector<ui32> h(n);
  for (auto& x : h) {
    read(x);
  }
  auto h_sorted = h;
  std::sort(h_sorted.begin(), h_sorted.end());
  h_sorted.erase(std::unique(h_sorted.begin(), h_sorted.end()), h_sorted.end());
  auto const k = h_sorted.size();
  vector<vector<size_t>> positions(k);
  auto normalize = [&](auto x) {
    return std::distance(h_sorted.begin(),
                         std::lower_bound(h_sorted.begin(),
                                          h_sorted.end(),
                                          x));
  };
  for (size_t i = 0; i != n; ++i) {
    auto& x = h[i];
    x = normalize(x);
    positions[x].push_back(i);
  }
  struct data {
    size_t pref{};
    size_t suff{};
    size_t max{};

    data() = default;
    data(size_t pref, size_t suff, size_t max) :
      pref(pref),
      suff(suff),
      max(max) {}
  };
  struct node {
    data d{};
    size_t l{};
    size_t r{};
    shared_ptr<node> left{};
    shared_ptr<node> right{};

    node(data d, size_t l, size_t r, shared_ptr<node> left,
            shared_ptr<node> right)
      : d(d),
        l(l),
        r(r),
        left(std::move(left)),
        right(std::move(right)) {}
  };
  using ptr_t = shared_ptr<node>;
  auto get = [](ptr_t const& n) -> data {
    return n ? n->d : data();
  };
  auto merge = [](data const& left, data const& right,
          size_t ls, size_t rs) -> data {
    return {left.pref == ls ? ls + right.pref : left.pref,
            right.suff == rs ? rs + left.suff : right.suff,
            std::max({left.max, right.max, left.suff + right.pref})};
  };
  function<ptr_t(ptr_t, size_t, size_t, size_t)> update =
          [&](auto v, auto l, auto r, auto i) {
    if (l + 1 == r) {
      return std::make_shared<node>(data{1, 1, 1}, i, i + 1, nullptr, nullptr);
    }
    auto m = (l + r) / 2;
    auto left = v ? v->left : v;
    auto right = v ? v->right : v;
    if (i < m) {
      left = update(v ? v->left : v, l, m, i);
    } else {
      right = update(v ? v->right : v, m, r, i);
    }
    return std::make_shared<node>(merge(get(left), get(right), m - l, r - m),
            l,
            r,
            left,
            right);
  };
  function<data(ptr_t, size_t, size_t)> query = [&](ptr_t const& v,
          size_t l, size_t r) -> data {
    if (!v || v->l >= r || l >= v->r) {
      return data{};
    }
    if (l <= v->l && v->r <= r) {
      return v->d;
    }
    auto left = v->l;
    auto right = v->r;
    auto middle = (left + right) / 2;
    return merge(
            query(v->left, l, r),
            query(v->right, l, r),
            middle - left,
            right - middle);
  };
  vector<ptr_t> trees(k + 1);
  for (auto i = k; i--; ) {
    trees[i] = trees[i + 1];
    for (auto pos : positions[i]) {
      trees[i] = update(trees[i], 0, n, pos);
    }
  }
  ui32 qs;
  read(qs);
  while (qs--) {
    size_t l, r, w;
    read(l, r, w);
    --l;
    size_t left = 0;
    size_t right = k;
    while (left + 1 != right) {
      auto middle = (left + right) / 2;
      auto max = query(trees[middle], l, r).max;
      if (max >= w) {
        left = middle;
      } else {
        right = middle;
      }
    }
    print(h_sorted[left]);
  }
  return 0;
}