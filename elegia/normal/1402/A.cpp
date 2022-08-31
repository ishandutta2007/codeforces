/*
_/_/_/_/    _/_/_/_/_/  _/_/_/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/      _/
_/      _/      _/    _/  _/  _/
_/      _/  _/  _/    _/    _/_/
_/_/_/_/      _/_/     _/_/_/_/_/

_/_/_/_/    _/    _/  _/      _/
_/      _/   _/  _/   _/_/  _/_/
_/      _/    _/_/    _/ _/_/ _/
_/      _/     _/     _/  _/  _/
_/      _/    _/_/    _/      _/
_/      _/   _/  _/   _/      _/
_/_/_/_/    _/    _/  _/      _/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/

_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/
*/
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

class vector_hasher {
public:
  std::size_t operator()(std::vector<int> const& vec) const {
    std::size_t seed = vec.size();
    for (auto& i : vec) {
      seed ^= (unsigned int)i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

using vm = vector<int>;

const int P = 998244353;

int norm(int x) { return x >= P ? (x - P) : x; }

void add(int& x, int y) { if ((x += y) >= P) x -= P; }

void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, P, x, y);
  return norm(x + P);
}

int mpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % P;
    x = x * (ll)x % P;
    k >>= 1;
  }
  return ret;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, c;
  cin >> n >> k >> c;

  int mult = inv((mpow(n, k) * (1LL << c)) % P);
  vm nv(k + 1), ifac(k + 1);
  for (int i = 1; i <= k; ++i) nv[i] = inv(i);
  ifac[0] = 1;
  for (int i = 1; i <= k; ++i) ifac[i] = ifac[i - 1] * (ll)nv[i] % P;

  unordered_map<vector<int>, int, vector_hasher> mp;
  int xsum = 0;
  while (n--) {
    int x; cin >> x;
    xsum ^= x;
    vector<int> seq(k);
    for (int i = 1; i <= k; ++i) seq[i - 1] = x ^ (x - i);
    ++mp[seq];
  }
  vector<vm> val(k + 1, vm(1 << c));
  for (const auto& [seq, cnt] : mp) {
    vector<int> basis(c), id(c, -1), red(k);
    int dim = 0;
    auto ins = [&](int x) {
      for (int i = 0; i < c; ++i)
        if ((x >> i) & 1) {
          if (basis[i]) x ^= basis[i];
          else {
            basis[i] = x;
            id[i] = dim++;
            return;
          }
        }
    };
    auto reduce = [&](int x) {
      int red = 0;
      for (int i = 0; i < c; ++i)
        if ((x >> i) & 1) {
          x ^= basis[i];
          red ^= 1 << id[i];
        }
      return red;
    };
    auto comb = [&](int x) {
      int ret = 0;
      for (int i = 0; i < c; ++i)
        if (id[i] != -1)
          if ((x >> id[i]) & 1)
            ret ^= basis[i];
      return ret;
    };
    for (int x : seq) ins(x);
    for (int i = 0; i < k; ++i) red[i] = reduce(seq[i]);
    vector<vm> ln(k + 1, vm(1 << dim));
    for (int i = 1; i <= k; ++i) {
      for (int s = 0; s != 1 << dim; ++s) {
        ull v = 0;
        for (int j = 1; j <= i; ++j)
          v += ln[i - j][s ^ red[j - 1]] * (ull)ifac[j];
        ln[i][s] = norm(P - int(v % P));
      }
      add(ln[i][red[i - 1]], ifac[i - 1]);
    }
    //cerr << ln << '\n';
    for (int i = 1; i <= k; ++i) {
      for (int s = 0; s != 1 << dim; ++s)
        ln[i][s] = ln[i][s] * (ull)nv[i] % P;
    }

    vector<int> remp(1 << dim);
    for (int i = 0; i != 1 << dim; ++i) remp[i] = comb(i);
    for (int i = 1; i <= k; ++i) {
      for (int s = 0; s != 1 << dim; ++s)
        val[i][remp[s]] = (val[i][remp[s]] + ln[i][s] * (ull)cnt) % P;
    }
  }
  auto FWT = [&](vm& vec) {
    for (int i = 0; i != c; ++i) {
      for (int s = 0; s != 1 << c; ++s) {
        if ((s >> i) & 1) {
          int a0 = vec[s ^ (1 << i)], a1 = vec[s];
          vec[s ^ (1 << i)] = norm(a0 + a1);
          vec[s] = norm(P + a0 - a1);
        }
      }
    }
  };
  for (int i = 1; i <= k; ++i) FWT(val[i]);
  vm res(1 << c);
  for (int s = 0; s != 1 << c; ++s) {
    vm f(k + 1), exp(k + 1);
    for (int i = 1; i <= k; ++i) f[i] = val[i][s] * (ull)i % P;
    exp[0] = 1;
    for (int i = 1; i <= k; ++i) {
      ull v = 0;
      for (int j = 1; j <= i; ++j)
        v += f[j] * (ull)exp[i - j];
      exp[i] = v % P * nv[i] % P;
    }
    res[s] = exp[k];
  }
  FWT(res);
  for (int i = 1; i <= k; ++i) mult = mult * (ull)i % P;
  for (int s = 0; s != 1 << c; ++s)
    cout << (res[s ^ xsum] * (ull)mult % P) << ' ';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}