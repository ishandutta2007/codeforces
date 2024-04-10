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
#include <map>

const int p = 1000000007;

int mul32(int x, int y) {
  return int(int64_t(x) * y % p);
}

int add32(int x, int y) {
  int res = x + y;
  if (res >= p) res -= p;
  return res;
}

template<class T>
std::pair<T, T> gcd2(T x, T y) {
  if (x == 0) {
    return {0, 1};
  }
  T s = y / x;
  std::pair<T, T> res = gcd2(y % x, x);
  return {res.second - s * res.first, res.first};
}

template<class T>
T inv(T x, T p) {
  x = x % p;
  if (x < 0) {
    x += p;
  }
  std::pair<T, T> res = gcd2(x, p);
  if (res.first < 0) {
    res.first += p;
  }
  if (res.first >= p) {
    res.first -= p;
  }
  return res.first;
}

struct request {
  int n;
  int k;
  int num;
  request(int n, int k, int num) : n(n), k(k), num(num) {

  }
};

int getK(std::istream& in) {
  std::string s;
  in >> s;
  return s.length();
}

void run(std::istream &in, std::ostream &out) {
  int m;
  in >> m;
  std::vector<request> requests;
  int curK = getK(in);
  for (int i = 0; i < m; i++) {
    int t;
    in >> t;
    if (t == 1) {
      curK = getK(in);
    } else {
      int n;
      in >> n;
      requests.emplace_back(n, curK, requests.size());
    }
  }
  std::map<int, std::vector<request>> requestMap;
  for (request& r : requests) {
    requestMap[r.k].push_back(r);
  }
  std::vector<int> pow25(100001);
  pow25[0] = 1;
  for (size_t i = 1; i < pow25.size(); i++) {
    pow25[i] = mul32(pow25[i - 1], 25);
  }
  std::vector<int> invTable(100001);
  for (int i = 1; i <= 100000; i++) {
    invTable[i] = inv(i, p);
  }
  std::vector<int> ans(requests.size());
  for (auto& entry : requestMap) {
    int k = entry.first;
    std::vector<request>& ns = entry.second;
    std::sort(ns.begin(), ns.end(), [](const request& left, const request& right) {
      return left.n < right.n;
    });
    size_t cur = 0;
    while (cur < ns.size() && ns[cur].n < k) {
      cur++;
    }
    int f = 1;
    int bin = 1;
    for (int n = k; cur < ns.size(); n++) {
      while (cur < ns.size() && ns[cur].n == n) {
        ans[ns[cur].num] = f;
        cur++;
      }
      f = mul32(f, 26);
      bin = mul32(mul32(bin, n), invTable[n - k + 1]);
      f = add32(f, mul32(bin, pow25[n - k + 1]));
    }
  }
  for (size_t i = 0; i < ans.size(); i++) {
    out << ans[i] << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}