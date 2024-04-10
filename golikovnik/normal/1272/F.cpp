//  Copyright 2019 Nikita Golikov

#include <bits/stdc++.h>

#define BITSET_ITER(i, bt) for (auto i = bt._Find_first(); i != bt.size();\
i = bt._Find_next(i))

using namespace std;

#ifdef GOLIKOV
mt19937 rng(566);
#else
mt19937 rng(static_cast<unsigned>(std::chrono::high_resolution_clock::now()
        .time_since_epoch()
        .count()));
#endif

template <typename T>
T rnd(T l, T r) {
  if constexpr (is_integral_v<T>) {
    return uniform_int_distribution<T>(l, r)(rng);
  } else {
    return uniform_real_distribution<T>(l, r)(rng);
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
    cout << endl;
  } else {
    cout << '\n';
  }
}

template <bool flush = false, typename T, typename... Args>
void print(T const& x, Args const& ... args) {
  cout << x;
  if constexpr (bool(sizeof...(args))) {
    cout << ' ';
  }
  print<flush>(args...);
}

template <typename T, typename F>
void foreach_rec(T& x, F&& f) {
  f(x);
}

template <typename T, typename F>
void foreach_rec(vector<T>& v, F&& f) {
  for (auto& vv : v) {
    foreach_rec(vv, forward<F>(f));
  }
}

using ui32 = uint32_t;
using i64 = int64_t;
using ui64 = uint64_t;

bool check_bounds() {
  return true;
}

template <typename... Ns>
bool check_bounds(int i, int n, Ns... args) {
  return i >= 0 && i < n && check_bounds(args...);
}

int main() {
  if constexpr (golikov()) {
    freopen("in", "rt", stdin);
  } else {
//    string const TASK = "schedule";
//    freopen((TASK + ".in").c_str(), "rt", stdin);
//    freopen((TASK + ".out").c_str(), "wt", stdout);
  }
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(12) << fixed;

  string s, t;
  cin >> s >> t;
  int n = (int) s.size();
  int m = (int) t.size();

  int const MAX_BAL = 600;
  auto dp = make_vector<int>(MAX_BAL, n + 1, m + 1);
  foreach_rec(dp, [](auto& x) {x = -1;});
  dp[0][0][0] = 0;

  struct state {
    int bal;
    int ps;
    int pt;

    state() = default;
    state(int bal, int ps, int pt) : bal(bal), ps(ps), pt(pt) {
    }
  };
  auto parent = make_vector<state>(MAX_BAL, n + 1, m + 1);
  auto upd = [&](int& x, int y) {
    if (x < 0) {
      x = y;
      return true;
    }
    return false;
  };
  queue<state> q;
  q.emplace(0, 0, 0);
  auto const BRACKETS = ")(";
  auto get_bal = [&](int open) {
    return open ? 1 : -1;
  };
  while (!q.empty()) {
    auto cur = q.front();
    auto[bal, ps, pt] = cur;
    q.pop();

    for (int open : {0, 1}) {
      auto new_bal = bal + get_bal(open);
      if (!check_bounds(new_bal, MAX_BAL)) {
        continue;
      }
      auto ch = BRACKETS[open];

      auto new_ps = ps + (s[ps] == ch);
      auto new_pt = pt + (t[pt] == ch);
      if (upd(dp[new_bal][new_ps][new_pt], dp[bal][ps][pt])) {
        state to{new_bal, new_ps, new_pt};
        parent[new_bal][new_ps][new_pt] = cur;
        q.push(to);
      }
    }
  }
  string answer;
  for (int bal = 0, ps = n, pt = m; bal || ps || pt; ) {
    auto p = parent[bal][ps][pt];
    if (p.bal < bal) {
      answer += '(';
    } else {
      answer += ')';
    }
    bal = p.bal;
    ps = p.ps;
    pt = p.pt;
  }
  reverse(answer.begin(), answer.end());
  print(answer);
  return 0;
}