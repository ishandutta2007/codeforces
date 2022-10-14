#line 1 "sol.cpp"
#include <bits/stdc++.h>

struct Mock {
  Mock(std::mt19937 &&gen, int n) : n(n), s_(n, ' '), t_(n, ' '), p(n) {
    for (int i = 0; i < n; ++i) {
      s_[i] = 'a' + std::uniform_int_distribution<>(0, 25)(gen);
    }
    std::iota(p.begin(), p.end(), 0);
    std::shuffle(p.begin(), p.end(), gen);
    for (int i = 0; i < n; ++i) {
      t_[p[i]] = s_[i];
    }
  }

  const std::string &get_str() const { return t_; }

  std::string ask(const std::string &s) const {
    std::string t(n, ' ');
    for (int i = 0; i < n; ++i) {
      t[p[i]] = s[i];
    }
    return t;
  }

  bool report(const std::string &s) const { return s == s_; }

private:
  int n;
  std::string s_, t_;
  std::vector<int> p;
};

struct RealWorld {
  RealWorld() { std::cin >> t_; }

  const std::string &get_str() const { return t_; }

  std::string ask(const std::string &s) const {
    std::cout << "? " << s << std::endl;
    std::string t;
    std::cin >> t;
    return t;
  }

  bool report(const std::string &s) const {
    std::cout << "! " << s << std::endl;
    return true;
  }

  std::string t_;
};

template <typename IO> void solve(IO &&io) {
  std::string t = io.get_str();
  int n = t.size();
  std::vector<std::string> result(3);
  for (int i = 0, denom = 1; i < 3; ++i, denom *= 26) {
    std::string s(n, ' ');
    for (int j = 0; j < n; ++j) {
      s[j] = 'a' + (j / denom) % 26;
    }
    result[i] = io.ask(s);
  }
  std::vector<int> invp(n);
  for (int i = 0; i < n; ++i) {
    int j = (result[0][i] - 'a') + (result[1][i] - 'a') * 26 +
            (result[2][i] - 'a') * 26 * 26;
    invp[i] = j;
  }
  std::string s(n, ' ');
  for (int i = 0; i < n; ++i) {
    s[invp[i]] = t[i];
  }
  assert(io.report(s));
}

int main() { solve(RealWorld{}); }