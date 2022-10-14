#include <bits/stdc++.h>

using LL = long long;

const int N = 100000;

int n, m;

struct Result {
  bool ok;
  int t, p, q;
  std::vector<int> solution;
};

struct Entry {
  int w, v, id, nid, l, r;

  int size() const { return std::max(r - l, 0); }

  int getr(int t, int p, int q) const {
    int x = std::min(1LL * m, 1LL * p * v / q);
    if (t < nid && 1LL * p * v == 1LL * q * x) {
      x--;
    }
    return x;
  }

  int getr(const Result &r) const { return getr(r.t, r.p, r.q); }
} e[N];

bool operator<(const Entry &a, const Entry &b) {
  return a.w != b.w ? a.w < b.w : a.v < b.v;
}

template <bool done = false> Result solve(LL rank) {
  int t = 0;
  while (rank >= e[t].size()) {
    rank -= e[t++].size();
  }
  int p = e[t].r - rank;
  int q = e[t].v;
  Result result{false, t, p, q, {}};
  int count = 0;
  for (int i = 0; i < n && count < m; ++i) {
    int r = e[i].getr(t, p, q);
    if (count < r) {
      if (done) {
        result.solution.push_back(e[i].id);
      }
      count++;
    }
  }
  result.ok = count == m;
  return result;
}

int main() {
  scanf("%d%d%*d", &n, &m);
  static int w[N];
  for (int i = 0; i < n; ++i) {
    scanf("%d", w + i);
  }
  for (int i = 0, v; i < n; ++i) {
    scanf("%d", &v);
    e[i] = {w[i], v, i, 0, 0, m};
  }
  std::sort(e, e + n);
  for (int i = 0; i < n; ++ i) {
    e[i].nid = i;
  }
  std::mt19937_64 gen{0};
  while (true) {
    LL sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += e[i].size();
    }
    if (sum == 1) {
      break;
    }
    Result result = solve(std::uniform_int_distribution<LL>(0, sum - 1)(gen));
    for (int i = 0; i < n; ++i) {
      int r = e[i].getr(result);
      if (result.ok) {
        e[i].r = std::min(e[i].r, r);
      } else {
        e[i].l = std::max(e[i].l, r);
      }
    }
  }
  Result result = solve<true>(0);
  for (int i = 0; i < m; ++i) {
    printf("%d%c", result.solution[i] + 1, " \n"[i == m - 1]);
  }
}