#line 1 "/tmp/tmp-262300K9I5ZeQ3UBLj.cpp"
#include <bits/stdc++.h>

struct Mock {
  int n() const { return a.size(); }

  std::vector<int> ask(int l, int r) {
    std::vector<int> result(a.begin() + l - 1, a.begin() + r);
    std::sort(result.begin(), result.end());
    return result;
  }

  void report(int l) { assert(a[l - 1] == l); }

  std::vector<int> a;
};

struct IO {
  int n() {
    int n;
    std::cin >> n;
    return n;
  }

  std::vector<int> ask(int l, int r) {
    std::cout << "? " << l << " " << r << std::endl;
    std::vector<int> result(r - l + 1);
    for (int i = 0; i < r - l + 1; ++i) {
      std::cin >> result[i];
    }
    return result;
  }

  void report(int l) { std::cout << "! " << l << std::endl; }
};

template <typename IO> void solve(IO &&io) {
  int n = io.n();
  int l = 1;
  int r = n;
  while (l < r) {
    int m = (l + r) >> 1;
    int count = m - l + 1;
    for (int a : io.ask(l, m)) {
      if (a < l || m < a) {
        count--;
      }
    }
    if (count & 1) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  io.report(l);
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve(IO{});
  }
  // solve(Mock{std::vector<int>{4, 2, 5, 1, 3}});
}