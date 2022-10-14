#include <bits/stdc++.h>

struct Mock {
  Mock(const std::vector<int> &p) : n(p.size()), p(p) {}

  int get_n() const { return n; }

  // the minimum 0-based duplicated index
  // if distinct, returns n
  int ask(const std::vector<int> &a) const {
    std::map<int, int> count;
    for (int i = 0; i < n; ++i) {
      assert(1 <= a[i] && a[i] <= n);
      count[p[i] + a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
      if (count[p[i] + a[i]] >= 2) {
        return i;
      }
    }
    return -1;
  }

  void report(const std::vector<int> &q) const {
    for (int i = 0; i < n; ++i) {
      assert(p[i] == q[i]);
    }
    std::cerr << "OK" << std::endl;
  }

  int n;
  std::vector<int> p;
};

struct IO {
  IO() { scanf("%d", &n); }

  int get_n() const { return n; }

  int ask(const std::vector<int> &a) const {
    printf("?");
    for (int i = 0; i < n; ++i) {
      printf(" %d", a[i]);
    }
    printf("\n");
    fflush(stdout);
    int result;
    scanf("%d", &result);
    return result - 1;
  }

  void report(const std::vector<int> &a) const {
    printf("!");
    for (int i = 0; i < n; ++i) {
      printf(" %d", a[i]);
    }
    printf("\n");
    fflush(stdout);
  }

  int n;
};

template <typename IO> void solve(IO &&io) {
  int n = io.get_n();
  std::vector<int> p(n), a(n, 1), doing;
  // 0 - todo, -1 - doing, >= 1 - done
  int m = n;
  while (true) {
    int last = n - 1;
    while (last >= 0 && p[last] >= 1) {
      last--;
    }
    if (last < 0) {
      break;
    }
    doing.clear();
    doing.push_back(last);
    while (a[last] < n) {
      a[last]++;
      int i = io.ask(a);
      if (i == -1) {
        break;
      }
      doing.push_back(i);
    }
    m -= doing.size();
    for (int i = 0; i < static_cast<int>(doing.size()); ++i) {
      p[doing[i]] = m + 1 + i;
      a[doing[i]] = 2;
    }
  }
  io.report(p);
}

int main() {
  //   solve(Mock{{3, 2, 1, 5, 4}});
  //   solve(Mock{{3, 5, 4, 2, 6, 1}});
  solve(IO());
}