#include <bits/stdc++.h>

namespace {

struct FastIn {
  FastIn(FILE *in_ = stdin) : in(in_) {}

  char next_char() {
    if (head == length) {
      head = 0;
      length = fread(buffer, 1, LENGTH, in);
    }
    return buffer[head++];
  }

  uint64_t next_uint() {
    char c = next_char();
    while (!std::isdigit(c)) {
      c = next_char();
    }
    uint64_t x = 0;
    for (; std::isdigit(c); c = next_char()) {
      x = x * 10U + c - '0';
    }
    return x;
  }

private:
  static const int LENGTH = 1 << 16;

  char buffer[LENGTH];
  size_t head = 0;
  size_t length = 0;
  FILE *in;
};

const int N = 300000;
const int LOG_N = 19;

int a[N], count[LOG_N][N + 1];
std::vector<int> indices[1 << LOG_N];

} // namespace

int main() {
  FastIn fin;
  int n = fin.next_uint();
  int q = fin.next_uint();
  for (int i = 0; i < n; ++i) {
    a[i] = fin.next_uint() - 1;
    indices[a[i]].push_back(i);
  }
  for (int j = 0; j < LOG_N; ++j) {
    for (int i = n; i--;) {
      count[j][i] = count[j][i + 1] + (a[i] >> j & 1);
    }
  }
  while (q--) {
    int l = fin.next_uint() - 1;
    int r = fin.next_uint();
    int length = r - l;
    int majority = 0;
    for (int j = 0; j < LOG_N; ++j) {
      if ((count[j][l] - count[j][r]) << 1 > length) {
        majority |= 1 << j;
      }
    }
    auto &&majority_indices = indices[majority];
    int count =
        std::lower_bound(majority_indices.begin(), majority_indices.end(), r) -
        std::lower_bound(majority_indices.begin(), majority_indices.end(), l);
    printf("%d\n", count > (length + 1) >> 1 ? 2 * count - length : 1);
  }
}