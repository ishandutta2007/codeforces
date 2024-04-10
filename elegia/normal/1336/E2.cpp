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

  int n, m;
  cin >> n >> m;
  vector<ll> a(n); cin >> a;
  vector<ll> basis(m);
  int dim = 0;
  for (ll x : a) {
    for (int i = 0; i < m; ++i)
      if ((x >> i) & 1) {
        if (basis[i])
          x ^= basis[i];
        else {
          basis[i] = x;
          ++dim;
          break;
        }
      }
  }
  {
    vector<int> bitf(m);
    int l = 0, r = m;
    for (int i = 0; i < m; ++i)
      if (basis[i])
        bitf[i] = l++;
      else
        bitf[i] = --r;
    auto bitwist = [&](ll x) {
      ll ret = 0;
      for (int i = 0; i < m; ++i)
        ret |= ((x >> i) & 1) << bitf[i];
      return ret;
    };
    vector<ll> tmp;
    for (int i = 0; i < m; ++i)
      if (basis[i])
        tmp.push_back(bitwist(basis[i]));
    swap(basis, tmp);
  }
  vector<int> tmp(m + 1), ans(m + 1);
  function<void(int, ll)> dfs = [&](int k, ll xs) {
    if (k == 0) {
      ++tmp[__builtin_popcountll(xs)];
      return;
    }
    dfs(k - 1, xs);
    dfs(k - 1, xs ^ basis[k - 1]);
  };
  if (dim <= m / 2) { // original basis
    dfs(dim, 0);
    ans = tmp;
  } else {
    for (int i = 0; i < dim; ++i)
      for (int j = 0; j < i; ++j)
        if ((basis[j] >> i) & 1)
          basis[j] ^= basis[i];
    vector<ll> zeroBasis;
    for (int i = dim; i < m; ++i) {
      ll x = 1LL << i;
      for (int j = 0; j < dim; ++j)
        x |= ((basis[j] >> i) & 1) << j;
      zeroBasis.push_back(x);
    }
    swap(basis, zeroBasis);
    dfs(m - dim, 0);

    vector<vector<int>> C(m + 1, vector<int>(m + 1));
    for (int i = 0; i <= m; ++i) {
      C[i][0] = 1;
      for (int j = 1; j <= i; ++j)
        C[i][j] = norm(C[i - 1][j] + C[i - 1][j - 1]);
    }
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= m; ++j) {
        int fwtpc = 0;
        for (int k = 0; k <= i; ++k) {
          int cur = C[j][k] * (ll)C[m - j][i - k] % P;
          if (k & 1) sub(fwtpc, cur);
          else add(fwtpc, cur);
        }
        add(ans[i], fwtpc * (ll)tmp[j] % P * mpow(2, P - 1 + dim - m) % P);
      }
    }
  }

  for (int i = 0; i <= m; ++i) {
    ans[i] = ans[i] * (ll)mpow(2, n - dim) % P;
  }
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}