#include <bits/stdc++.h>

template <typename T> inline constexpr T type_min = std::numeric_limits<T>::min();

template <typename T> inline constexpr T type_max = std::numeric_limits<T>::max();

template <typename... Args>
void read(Args& ... args) {
  (std::cin >> ... >> args);
}

template <typename T>
T input() {
  T x{};
  std::cin >> x;
  return x;
}

void print() {
  std::cout << '\n';
}

template <typename T, typename... Args>
void print(T const& value, Args const& ... args) {
  std::cout << value;
  if constexpr (sizeof...(args)) {
    std::cout << ' ';
  }
  print(args...);
}

template <typename T>
T make_vector() {
  return T();
}

template <typename T, typename... Args>
auto make_vector(std::size_t n, Args... args) {
  return std::vector(n, make_vector<T>(args...));
}

int main() {
  unsigned n, k;
  read(n, k);
  auto is_black = make_vector<bool>(n, n);
  for (std::size_t r = 0; r != n; ++r) {
    for (std::size_t c = 0; c != n; ++c) {
      auto ch = input<char>();
      is_black[r][c] = ch == 'B';
    }
  }
  std::vector<unsigned> row_max_white_pref(n),
                        row_max_white_suff(n),
                        col_max_white_pref(n),
                        col_max_white_suff(n);
  for (std::size_t r = 0; r != n; ++r) {
    unsigned n_white = 0;
    while (n_white != n && !is_black[r][n_white]) {
      ++n_white;
    }
    row_max_white_pref[r] = n_white;
    n_white = 0;
    while (n_white != n && !is_black[r][n - n_white - 1]) {
      ++n_white;
    }
    row_max_white_suff[r] = n_white;
  }
  for (std::size_t c = 0; c != n; ++c) {
    unsigned n_white = 0;
    while (n_white != n && !is_black[n_white][c]) {
      ++n_white;
    }
    col_max_white_pref[c] = n_white;
    n_white = 0;
    while (n_white != n && !is_black[n - n_white - 1][c]) {
      ++n_white;
    }
    col_max_white_suff[c] = n_white;
  }
  std::vector<unsigned> full_white_row_pref(n),
                        full_white_row_suff(n),
                        full_white_col_pref(n),
                        full_white_col_suff(n);
  for (std::size_t i = 0; i != n; ++i) {
    full_white_row_pref[i] = row_max_white_pref[i] == n;
    if (i) {
      full_white_row_pref[i] += full_white_row_pref[i - 1];
    }
    full_white_row_suff[n - i - 1] = row_max_white_pref[n - i - 1] == n;
    if (i) {
      full_white_row_suff[n - i - 1] += full_white_row_suff[n - i];
    }
    full_white_col_pref[i] = col_max_white_pref[i] == n;
    if (i) {
      full_white_col_pref[i] += full_white_col_pref[i - 1];
    }
    full_white_col_suff[n - i - 1] = col_max_white_pref[n - i - 1] == n;
    if (i) {
      full_white_col_suff[n - i - 1] += full_white_col_suff[n - i];
    }
  }
  auto check_row = [&](std::size_t i, std::size_t j, std::size_t r) {
    return row_max_white_pref[r] >= j && row_max_white_suff[r] >= n - j - k;
  };
  auto check_col = [&](std::size_t i, std::size_t j, std::size_t c) {
    return col_max_white_pref[c] >= i && col_max_white_suff[c] >= n - i - k;
  };
  auto result = make_vector<std::pair<unsigned, unsigned>>(n, n);
  unsigned answer = 0;
  for (std::size_t i = 0; i != n - k + 1; ++i) {
    for (std::size_t j = 0; j != n - k + 1; ++j) {
      if (i) {
        auto old = check_row(i - 1, j, i - 1);
        auto new_ = check_row(i, j, i + k - 1);
        result[i][j].first = result[i - 1][j].first - old + new_;
      } else {
        for (std::size_t s = 0; s != k; ++s) {
          result[i][j].first += check_row(i, j, s);
        }
      }
      if (j) {
        auto old = check_col(i, j - 1, j - 1);
        auto new_ = check_col(i, j, j + k - 1);
        result[i][j].second = result[i][j - 1].second - old + new_;
      } else {
        for (std::size_t s = 0; s != k; ++s) {
          result[i][j].second += check_col(i, j, s);
        }
      }
      auto full_row_pref = i ? full_white_row_pref[i - 1] : 0;
      auto full_row_suff = i != n - k ? full_white_row_suff[i + k] : 0;
      auto full_col_pref = j ? full_white_col_pref[j - 1] : 0;
      auto full_col_suff = j != n - k ? full_white_col_suff[j + k] : 0;
      auto full = full_row_pref + full_row_suff + full_col_pref + full_col_suff;
      answer = std::max(answer, result[i][j].first + result[i][j].second + full);
    }
  }
  print(answer);
  return 0;
}