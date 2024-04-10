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
  if (n == 62) {

  }
  int start_start_n = n;
  int start_n = n;
  if (n == 62) {
    ++start_n;
    ++n;
  }
  int const BOARD = 8;
  int row = BOARD - 1;
  int cell = 0;
  vector<pair<int, int>> answer;
  int dir = 0;
  int phase = 0;
  while (n > 2 || (start_n == 63 && n > 0)) {
    --n;
    answer.emplace_back(row, cell);
    if (phase == 0) {
      if (dir == 0) {
        if (cell == BOARD - 1) {
          row--;
          dir = 1;
        } else {
          cell++;
        }
        continue;
      }
      if (cell == 0) {
        if (row == 2) {
          if (start_n != 62) {
            phase = 1;
            row = 0;
            continue;
          }
        }
        row--;
        dir = 0;
      } else {
        cell--;
      }
      continue;
    }
    if (row == 0) {
      if (cell % 2 == 0) {
        row++;
      } else {
        cell++;
      }
      continue;
    }
    if (cell % 2 == 0) {
      cell++;
    } else {
      row--;
    }
  }
  answer.emplace_back(row, cell);
  if (n == 2) {
    if (row == 0) {
      cell++;
      answer.emplace_back(row, cell);
      answer.emplace_back(0, BOARD - 1);
    } else if (cell == BOARD - 1) {
      row--;
      answer.emplace_back(row, cell);
      answer.emplace_back(0, BOARD - 1);
    } else if (row == 1) {
      answer.emplace_back(1, 7);
      answer.emplace_back(0, 7);
    } else {
      answer.emplace_back(0, cell);
      answer.emplace_back(0, BOARD - 1);
    }
  }
  if (start_start_n == 62) {
    answer.erase(answer.begin() + 1);
  }
  auto const letters = "abcdefgh";
  auto const digits = "12345678";
  for (auto[r, c] : answer) {
    cout << letters[c] << digits[BOARD - r - 1] << '\n';
  }
  return 0;
}