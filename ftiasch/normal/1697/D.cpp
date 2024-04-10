#line 1 "/tmp/tmp-368362d7yIXaT7vudk.cpp"
#include <bits/stdc++.h>

struct Mock {
  int n() { return s_.size(); }

  char at(int i) { return s_[i]; }

  int distincts(int l, int r) {
    std::set<char> cs;
    for (int i = l; i <= r; ++i) {
      cs.emplace(s_[i]);
    }
    return cs.size();
  }

  void report(const std::string &s) {
    assert(s == s_);
    std::cerr << "OK" << std::endl;
  }

  std::string s_;
};

struct IO {
  IO() {
    std::ios::sync_with_stdio(false);
    std::cin >> n_;
  }

  int n() { return n_; }

  char at(int i) {
    std::cout << "? 1 " << i + 1 << std::endl;
    std::string c;
    std::cin >> c;
    return c[0];
  }

  int distincts(int l, int r) {
    if (l > r) {
      return 0;
    }
    if (l == r) {
      return 1;
    }
    std::cout << "? 2 " << l + 1 << " " << r + 1 << std::endl;
    int d;
    std::cin >> d;
    return d;
  }

  void report(const std::string &s_) { std::cout << "! " << s_ << std::endl; }

  int n_;
};

template <typename IO> void solve(IO &&io) {
  int n = io.n();
  std::vector<char> result(n + 1);
  result[n - 1] = io.at(n - 1);
  std::vector<int> occ{n - 1};
  for (int i = n - 2; i >= 0; --i) {
    // distincts(i + 1, occ[j]) == j + 1
    int low = 0, high = occ.size();
    while (low < high) {
      int middle = (low + high) >> 1;
      if (io.distincts(i, occ[middle]) == middle + 1) { // N
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    if (high == occ.size()) {
      result[i] = io.at(i);
    } else {
      result[i] = result[occ[high]];
      occ.erase(occ.begin() + high);
    }
    occ.insert(occ.begin(), i);
  }
  io.report(result.data());
}

int main() { solve(IO{}); }