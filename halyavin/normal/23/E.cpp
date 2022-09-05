#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif

#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

using BigInteger = std::string;

BigInteger multiply(const BigInteger& in, int mult) {
  int c = 0;
  BigInteger res;
  for (size_t i = 0; i < in.length(); i++) {
    c += (in[i] - '0') * mult;
    res.push_back((c % 10) + '0');
    c /= 10;
  }
  while (c != 0) {
    res.push_back((c % 10) + '0');
    c /= 10;
  }
  return res;
}

BigInteger multiply(const BigInteger& in1, const BigInteger& in2) {
  int c = 0;
  BigInteger res(in1.length() + in2.length(), '0');
  for (size_t i = 0; i < in1.length(); i++) {
    int c = 0;
    for (size_t j = 0; j < in2.length(); j++) {
      c += res[i + j] - '0' + (in1[i] - '0') * (in2[j] - '0');
      res[i + j] = (c % 10) + '0';
      c /= 10;
    }
    if (c != 0) {
      res[i + in2.length()] += c;
    }
  }
  if (res.back() == '0') {
    res.resize(res.length() - 1);
  }
  return res;
}

BigInteger max(const BigInteger& in1, const BigInteger& in2) {
  if (in1.length() > in2.length()) {
    return in1;
  }
  if (in1.length() < in2.length()) {
    return in2;
  }
  for (size_t i = in1.length(); i-- > 0;) {
    if (in1[i] > in2[i]) {
      return in1;
    }
    if (in1[i] < in2[i]) {
      return in2;
    }
  }
  return in1;
}

bool less(const BigInteger& in1, const BigInteger& in2) {
  if (in1.length() > in2.length()) {
    return false;
  }
  if (in1.length() < in2.length()) {
    return true;
  }
  for (size_t i = in1.length(); i-- > 0;) {
    if (in1[i] > in2[i]) {
      return false;
    }
    if (in1[i] < in2[i]) {
      return true;
    }
  }
  return false;
}

struct Solution {

  std::vector<std::vector<int>> graph;
  std::vector<std::array<BigInteger, 3>> dyn;

  void dfs(int v, int prev) {
    std::vector<int>& neib = graph[v];
    auto it = std::find(neib.begin(), neib.end(), prev);
    if (it != neib.end()) {
      neib.erase(it);
    }
    for (int nv : neib) {
      dfs(nv, v);
    }
    // 0 - occupied
    // 1 - center + 1
    // 2 - anything
    BigInteger mult = "1";
    for (int nv: neib) {
      mult = multiply(mult, dyn[nv][2]);
    }
    dyn[v][0] = mult;
    BigInteger res = multiply(mult, 2);
    std::vector<std::pair<BigInteger, BigInteger>> children;
    for (int nv : neib) {
      children.emplace_back(dyn[nv][2], dyn[nv][0]);
    }
    mult = "1";
    std::sort(children.begin(), children.end(), [](const std::pair<BigInteger, BigInteger>& left,
                                                   const std::pair<BigInteger, BigInteger>& right) {
      return less(multiply(left.first, right.second), multiply(left.second, right.first));
    });
    std::vector<BigInteger> mult0(children.size());
    mult = "1";
    for (size_t i = 0; i < children.size(); i++) {
      mult = multiply(mult, children[i].second);
      mult0[i] = mult;
    }
    mult = "1";
    for (size_t i = children.size(); i-- > 0;) {
      res = max(res, multiply(mult0[i], multiply(mult, i + 3)));
      mult = multiply(mult, children[i].first);
    }
    dyn[v][1] = res;
    res = dyn[v][0];
    mult = "1";
    for (size_t i = children.size(); i-- > 0;) {
      res = max(res, multiply(mult0[i], multiply(mult, i + 2)));
      mult = multiply(mult, children[i].first);
    }
    if (neib.size() > 0) {
      std::vector<BigInteger> before(neib.size());
      std::vector<BigInteger> after(neib.size());
      BigInteger mult = "1";
      for (size_t i = 0; i < neib.size(); i++) {
        before[i] = mult;
        mult = multiply(mult, dyn[neib[i]][2]);
      }
      mult = "1";
      for (size_t i = neib.size(); i-- > 0;) {
        after[i] = mult;
        mult = multiply(mult, dyn[neib[i]][2]);
      }
      for (size_t i = 0; i < neib.size(); i++) {
        BigInteger cur = multiply(before[i], after[i]);
        cur = multiply(cur, dyn[neib[i]][1]);
        res = max(res, cur);
      }
    }
    dyn[v][2] = res;
  }

  void run(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    graph.resize(n);
    for (int i = 0; i < n - 1; i++) {
      int from, to;
      in >> from >> to;
      from--;
      to--;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    dyn.resize(n);
    dfs(0, -1);
    BigInteger res = dyn[0][2];
    std::reverse(res.begin(), res.end());
    out << res << std::endl;
  }

};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}