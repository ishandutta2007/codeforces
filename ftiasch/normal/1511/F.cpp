#include <bits/stdc++.h>

const int MOD = 998'244'353;
const int C = 26;
const int M = 161;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

struct Matrix {
  Matrix() { memset(data, 0, sizeof(data)); }

  const int *operator[](int i) const { return data[i]; }

  int *operator[](int i) { return data[i]; }

  int data[M][M];
};

Matrix multiply(int dim, const Matrix &a, const Matrix &b) {
  Matrix c;
  for (int i = 0; i < dim; ++i) {
    for (int j = 0; j < dim; ++j) {
      for (int k = 0; k < dim; ++k) {
        add(c[i][j], 1LL * a[i][k] * b[k][j] % MOD);
      }
    }
  }
  return c;
}

using Pair = std::pair<std::string, std::string>;

int main() {
  int n, m;
  std::cin >> n >> m;
  std::map<std::string, bool> prefixes;
  prefixes[""] = false;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 1; j <= static_cast<int>(s.size()); ++j) {
      auto p = s.substr(0, j);
      prefixes.emplace(p, false);
    }
    prefixes[s] = true;
  }
  std::map<Pair, int> pairs;
  std::queue<Pair> queue;
  auto get_id = [&](const std::string &a, const std::string &b) {
    Pair p{a, b};
    auto result = pairs.emplace(p, pairs.size());
    if (result.second) {
      queue.push(p);
    }
    return result.first->second;
  };
  get_id("", "");
  Matrix ma;
  while (!queue.empty()) {
    auto [a, b] = queue.front();
    queue.pop();
    int u = pairs[{a, b}];
    for (char c = 'a'; c <= 'z'; ++c) {
      auto aa = a + c;
      auto bb = b + c;
      auto pa = prefixes.find(aa);
      auto pb = prefixes.find(bb);
      if (pa != prefixes.end() && pb != prefixes.end()) {
        ma[u][get_id(aa, bb)]++;
        if (pa->second) {
            ma[u][get_id(bb, "")] ++;
        }
        if (pb->second) {
            ma[u][get_id(aa, "")] ++;
        }
        if (pa->second && pb->second) {
            ma[u][get_id("", "")] ++;
        }
      }
    }
  }
  int dim = pairs.size();
  Matrix result;
  for (int i = 0; i < dim; ++ i) {
      result[i][i] = 1;
  }
  while (m) {
      if (m & 1) {
          result = multiply(dim, result, ma);
      }
      ma = multiply(dim, ma, ma);
      m >>= 1;
  }
  printf("%d\n", result[0][0]);
}