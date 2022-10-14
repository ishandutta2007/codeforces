#include <bits/stdc++.h>

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

  int64_t next_int() {
    char c = next_char();
    while (!std::isdigit(c) && c != '-') {
      c = next_char();
    }
    int64_t sign = 1;
    if (c == '-') {
      sign = -1;
      c = next_char();
    }
    int64_t x = 0;
    for (; std::isdigit(c); c = next_char()) {
      x = x * 10 + c - '0';
    }
    return sign * x;
  }

private:
  static const int LENGTH = 1 << 16;

  char buffer[LENGTH];
  size_t head = 0;
  size_t length = 0;
  FILE *in;
};

template <typename T>
using PQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int main() {
  FastIn io;
  int n = io.next_uint();
  int q = io.next_uint();
  int source = io.next_uint() - 1;
  int d0 = io.next_uint();
  std::vector<int> a(n);
  std::map<int, int> candidates;
  for (int i = 0; i < n; ++i) {
    a[i] = io.next_uint();
    if (i != source) {
      candidates.emplace(a[i], i);
    }
  }
  static const int M = 2000000;
  std::vector<int> bwd(n, M), fwd(n, -M), mink(n, M);
  PQ<std::pair<int, int>> pq;
  pq.emplace(mink[source] = 0, source);
  auto update = [&](int i, int d) {
    if (mink[i] > d) {
      pq.emplace(mink[i] = d, i);
    }
  };
  auto update_bwd = [&](int i, int x) {
    bwd[i] = std::min(bwd[i], x);
    update(i, bwd[i] - a[i]);
  };
  auto update_fwd = [&](int i, int x) {
    fwd[i] = std::max(fwd[i], x);
    update(i, a[i] - fwd[i]);
  };
  auto add = [&](int x0, int k0) {
    auto iterator = candidates.lower_bound(x0 - k0);
    if (iterator != candidates.begin()) {
      update_bwd(std::prev(iterator)->second, x0);
    }
    while (iterator != candidates.end()) {
      auto backup = iterator;
      int x = iterator->first;
      if (x > x0 + k0) {
        break;
      }
      int id = iterator->second;
      update(id, k0);
      iterator++;
      candidates.erase(backup);
    }
    if (iterator != candidates.end()) {
      update_fwd(iterator->second, x0);
    }
  };
  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    int id = top.second;
    if (top.first == mink[id]) {
      int x = a[id];
      int k = top.first;
      add(x - d0, k);
      add(x + d0, k);
      auto iterator = candidates.lower_bound(x);
      if (iterator->first == x) {
        auto backup = iterator;
        iterator ++;
        candidates.erase(backup);
      }
      if (iterator != candidates.end()) {
        update_fwd(iterator->second, fwd[id]);
      }
      if (iterator != candidates.begin()) {
        update_bwd(std::prev(iterator)->second, bwd[id]);
      }
    }
  }
  while (q--) {
    int target = io.next_uint() - 1;
    int delta = io.next_uint();
    puts(delta >= mink[target] ? "Yes" : "No");
  }
}