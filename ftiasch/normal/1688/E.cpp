#line 1 "/tmp/tmp-47869083HZlylFqui1.cpp"
#include <bits/stdc++.h>

struct It {
  std::pair<int, int> get_nm() {
    int n, m;
    std::cin >> n >> m;
    return {n, m};
  }

  int ask(const std::vector<char> &s) {
    std::cout << "? " << s.data() << std::endl;
    int result;
    std::cin >> result;
    return result;
  }

  void report(int r) { std::cout << "! " << r << std::endl; }
};

template <typename It> void solve(It &&it) {
  auto [n, m] = it.get_nm();
  std::vector<std::pair<int, int>> weight(m);
  std::vector<char> buffer(m + 1, '0');
  buffer[m] = '\0';
  for (int i = 0; i < m; ++i) {
    buffer[i] = '1';
    weight[i] = {it.ask(buffer), i};
    buffer[i] = '0';
  }
  std::sort(weight.begin(), weight.end());
  int current = 0;
  for (auto [w, i] : weight) {
    buffer[i] = '1';
    int new_ = it.ask(buffer);
    if (new_ == current + w) {
      current += w;
    } else {
      buffer[i] = '0';
    }
  }
  it.report(current);
}

int main() { solve(It{}); }