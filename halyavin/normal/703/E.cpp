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

void factor(int64_t k, std::vector<int64_t>* ps, std::vector<int>* alphas) {
  if (k % 2 == 0) {
    ps->push_back(2);
    int count = 0;
    while (k % 2 == 0) {
      count++;
      k /= 2;
    }
    alphas->push_back(count);
  }
  for (int64_t i = 3; i * i <= k; i += 2) {
    if (k % i == 0) {
      ps->push_back(i);
      int count = 0;
      while (k % i == 0) {
        count++;
        k /= i;
      }
      alphas->push_back(count);
    }
  }
  if (k > 1) {
    ps->push_back(k);
    alphas->push_back(1);
  }
}

void run(std::istream& in, std::ostream& out) {
  int n;
  int64_t k;
  in >> n >> k;
  if (k == 1) {
    out << 1 << std::endl;
    std::vector<int64_t> xs(n);
    for (int i  = 0; i < n; i++) {
      in >> xs[i];
    }
    out << 1 + std::distance(xs.begin(), std::min_element(xs.begin(), xs.end())) << std::endl;
    return;
  }
  std::vector<int64_t> ps;
  std::vector<int> alphas;
  factor(k, &ps, &alphas);

  std::vector<int> mults = {1};
  int all = 1;
  for (int alpha : alphas) {
    all *= alpha + 1;
    mults.push_back(all);
  }
  std::vector<std::pair<int, int64_t>> dyn(all, std::make_pair(n + 1, 0));
  dyn[0] = std::make_pair(0, 0);
  std::vector<std::vector<int>> allAlphas(all, std::vector<int>(alphas.size()));
  for (int i = 0; i < all; i++) {
    int ci = i;
    for (int j = 0; j < alphas.size(); j++) {
      allAlphas[i][j] = ci % (alphas[j] + 1);
      ci /= (alphas[j] + 1);
    }
  }
  std::vector<int> xAlphas(alphas.size());
  std::vector<std::vector<int>> dynAns(all);
  for (int i = 1; i <= n; i++) {
    int64_t x;
    in >> x;
    int64_t originalX = x;
    for (size_t j = 0; j < alphas.size(); j++) {
      int count = 0;
      while (x % ps[j] == 0) {
        count++;
        x /= ps[j];
      }
      xAlphas[j] = count;
    }
    for (int j = all - 1; j >= 0; j--) {
      int next = 0;
      for (size_t k = 0; k < alphas.size(); k++) {
        next += std::min(allAlphas[j][k] + xAlphas[k], alphas[k]) * mults[k];
      }
      std::pair<int, int64_t> nextV = dyn[j];
      nextV.first++;
      nextV.second += originalX;
      if (dyn[next] > nextV) {
        dyn[next] = nextV;
        dynAns[next] = dynAns[j];
        dynAns[next].push_back(i);
      }
    }
  }
  if (dyn[all - 1].first > n) {
    out << -1 << std::endl;
    return;
  }
  std::vector<int>& answer = dynAns[all - 1];
  std::reverse(answer.begin(), answer.end());
  out << answer.size() << std::endl;
  for (int num : answer) {
    out << num << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}