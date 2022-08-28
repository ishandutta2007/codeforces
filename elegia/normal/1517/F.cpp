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
#include <vector>
#include <chrono>
#include <iostream>
#include <iomanip>
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

const int N = 310;

int n, r;
vector<int> g[N];

vector<int> dfs(int u, int p) {
  vector<int> vec(r * 2);
  vec[r * 2 - 1] = 1; vec[r - 1] = 1;
  for (int v : g[u])
    if (v != p) {
      auto cev = dfs(v, u);
      vector<int> dp(r * 2);
      cev.erase(cev.begin());
      cev.push_back(0);
      /*
      for (int i = 0; i < r * 2; ++i)
        for (int j = 1; j < r * 2; ++j) {
          if (i + j >= r * 2) add(dp[max(i, j - 1)], vec[i] * (ull)cev[j] % P);
          else { add(dp[min(i, j - 1)], vec[i] * (ull)cev[j] % P); }
        }*/
      {
        vector<int> A = vec, B = cev;
        vector<int> C(r * 2);


        for (int i = r - 1; i; --i) add(A[i - 1], A[i]);
        for (int i = r - 1; i; --i) add(B[i - 1], B[i]);
        for (int i = r; i != r * 2 - 1; ++i) add(A[i + 1], A[i]);
        for (int i = r; i != r * 2 - 1; ++i) add(B[i + 1], B[i]);
        /*
        for (int i = r * 2 - 1; i > r; --i) add(A[i - 1], A[i]);
        for (int i = r * 2 - 1; i > r; --i) add(B[i - 1], B[i]);
        for (int i = 1; i != r; ++i) add(A[i], A[i - 1]);
        for (int i = 1; i != r; ++i) add(B[i], B[i - 1]);*/

        for (int i = 0; i != r * 2; ++i) C[i] = A[i] * (ull)B[i] % P;
        for (int i = 1; i != r; ++i) sub(C[i - 1], C[i]);
        for (int i = r + r - 1; i > r; --i) sub(C[i], C[i - 1]);

        for (int i = r * 2 - 1; i >= 0; --i) add(dp[i], C[i]);

        //cerr << vec << ", " << cev << " -> " << dp << '\n';

        //A = vec;
        //B = cev;
        //cerr << vec << " -> " << A << ", " << cev << " -> " << B << '\n';
        for (int i = 0; i != r * 2; ++i) {
          if (i >= r) {
            add(dp[i], vec[i] * (ull) B[2 * r - 1 - i] % P);
            add(dp[i], cev[i] * (ull) A[2 * r - 1 - i] % P);
          } else if (i < r - 1) {
            add(dp[i], vec[i] * (ull) B[2 * r - i - 2] % P);
            add(dp[i], cev[i] * (ull) A[2 * r - i - 2] % P);
          }
        }
      }
      swap(dp, vec);
    }
  return vec;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int rep = 1; rep != n; ++rep) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int ans = 0;
  for (r = n + 1; r > 1; --r) {
    auto vec = dfs(1, -1);
    ans = (ans + accumulate(vec.begin() + r, vec.end(), 0ULL)) % P;
    //cerr << accumulate(vec.begin() + r, vec.end(), 0ULL) << '\n';
  }
  ans = (P - ans + n * (ull)mpow(2, n)) % P;
  sub(ans, 1);
  ans = ans * (ull)mpow(2, P - 1 - n) % P;

  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}