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


int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> C(61, vector<int>(61));
  for (int i = 0; i <= 60; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      add(C[i][j], C[i - 1][j - 1]);
      add(C[i][j], C[i - 1][j]);
    }
  }
  ll D;
  cin >> D;
  vector<ll> pfacs;
  vector<int> cns;
  for (int x = 2; x * (ll)x <= D; ++x)
    if (D % x == 0) {
      int cnt = 0;
      while (D % x == 0) {
        D /= x;
        ++cnt;
      }
      pfacs.emplace_back(x);
      cns.push_back(cnt);
    }
  if (D != 1) {
    pfacs.emplace_back(D);
    cns.push_back(1);
  }
  int q;
  cin >> q;

  auto cnts = [&](ll v) {
    vector<int> ret;
    ret.reserve(pfacs.size());
    for (ll p : pfacs) {
      int cnt = 0;
      while (v % p == 0) {
        v /= p;
        ++cnt;
      }
      ret.push_back(cnt);
    }
    return ret;
  };

  while (q--) {
    ll u, v;
    cin >> u >> v;
    auto x = cnts(u), y = cnts(v);
    int a0 = 1, a1 = 1, tot0 = 0, tot1 = 0;
    for (int i = 0; i < pfacs.size(); ++i) {
      int d = x[i] - y[i];
      if (d >= 0) {
        tot0 += d;
        a0 = a0 * (ll)C[tot0][d] % P;
      } else {
        d = -d;
        tot1 += d;
        a1 = a1 * (ll)C[tot1][d] % P;
      }
    }
    cout << (a0 * (ll)a1 % P) << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}