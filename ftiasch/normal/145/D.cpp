#include <bits/stdc++.h>

struct IO {
  IO(FILE *in = stdin) : in(in) {}

  int next_char() {
    if (position == length) {
      position = 0, length = fread(buffer, 1, LENGTH, in);
    }
    if (position == length) {
      eof = true;
      return -1;
    }
    return buffer[position++];
  }

  int next_uint() {
    int c = next_char(), x = 0;
    while (c <= 32) {
      c = next_char();
    }
    for (; '0' <= c && c <= '9'; c = next_char()) {
      x = x * 10 + c - '0';
    }
    return x;
  }

  int next_int() {
    int s = 1, c = next_char(), x = 0;
    while (c <= 32) {
      c = next_char();
    }
    if (c == '-') {
      s = -1, c = next_char();
    }
    for (; '0' <= c && c <= '9'; c = next_char()) {
      x = x * 10 + c - '0';
    }
    return x * s;
  }

  void next_string(char *s) {
    int c = next_char();
    while (c <= 32) {
      c = next_char();
    }
    for (; c > 32; c = next_char()) {
      *s++ = c;
    }
    *s = 0;
  }

private:
  static const int LENGTH = 1 << 16;

  char buffer[LENGTH];
  int position = 0, length = 0;
  bool eof = false;
  FILE *in;
};

bool is_lucky(int a) {
  for (; a; a /= 10) {
    int d = a % 10;
    if (d != 4 && d != 7) {
      return false;
    }
  }
  return true;
}

uint64_t binom2(int n) { return 1ULL * n * (n - 1) / 2; }

uint64_t sum_binom2(int n) { return 1ULL * (n + 1) * n * (n - 1) / 6; }

int main() {
  IO io;
  int n = io.next_int();
  std::vector<int> indexes{0}, values{-1};
  std::map<int, int> luckies;
  for (int i = 1; i <= n; ++i) {
    int a = io.next_int();
    if (is_lucky(a)) {
      indexes.push_back(i);
      if (!luckies.count(a)) {
        luckies[a] = luckies.size();
      }
      values.push_back(luckies[a]);
    }
  }
  indexes.push_back(n + 1);
  uint64_t result = 0;
  int m = indexes.size() - 1;
  // indexes[m] == n + 1
  for (int i = 0; i < m; ++i) {
    // r_1 in (indexes[i], indexes[i + 1])
    for (int r_1 = indexes[i] + 1; r_1 < indexes[i + 1]; ++r_1) {
      result += 1ULL * (r_1 - indexes[i]) * (n - r_1) * (n - r_1 + 1) / 2;
    }
  }
  std::vector<int> next_same(m), left_count(m), prev(m + 1), next(m + 1);
  {
    std::vector<int> next(m, m);
    for (int i = m; i-- > 1;) {
      next_same[i] = next[values[i]];
      next[values[i]] = i;
    }
  }
  for (int i = 1; i < m; ++i) {
    for (int j = i; j < m; ++j) {
      left_count[values[j]]++;
    }
    uint64_t case_result = 0;
    prev[m] = next[m] = m;
    for (int j = m - 1; j >= i; --j) {
      // Case: l_2 < common_indexes[0] => r_2 < common_indexes[0]
      result += 1ULL * (indexes[i] - indexes[i - 1]) *
                (sum_binom2(indexes[next[m]] - indexes[j]) -
                 sum_binom2(indexes[next[m]] - indexes[j + 1]));
      // Case: common_indexes[0] < l_2
      // uint64_t case_result = 0;
      // // for (int k = 0; k + 1 < static_cast<int>(common_indexes.size());
      // ++k) { for (int p = next[m]; p != m; p = next[p]) {
      //   int length = indexes[next[p]] - indexes[p] - 1;
      //   case_result += 1ULL * length * (length + 1) / 2;
      // }
      result += 1ULL * (indexes[i] - indexes[i - 1]) *
                (indexes[j + 1] - indexes[j]) * case_result;
      if (--left_count[values[j]] == 0) {
        for (int p = next_same[j]; p < m; p = next_same[p]) {
          int q = next[p], r = prev[p];
          case_result -= binom2(indexes[q] - indexes[p]);
          if (r != m) {
            case_result -= binom2(indexes[p] - indexes[r]);
            case_result += binom2(indexes[q] - indexes[r]);
          }
          next[r] = q;
          prev[q] = r;
        }
      } else {
        int first = next[m];
        case_result += binom2(indexes[first] - indexes[j]);
        next[j] = first;
        prev[first] = j;
        prev[j] = m;
        next[m] = j;
      }
    }
  }
  std::cout << result << std::endl;
}