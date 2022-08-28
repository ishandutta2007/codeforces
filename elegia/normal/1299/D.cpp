#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <unordered_map>
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

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int P = 1000000007;

int norm(int x) { return x >= P ? (x - P) : x; }

void add(int &x, int y) { if ((x += y) >= P) x -= P; }

void sub(int &x, int y) { if ((x -= y) < 0) x += P; }

void exGcd(int a, int b, int &x, int &y) {
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
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unordered_map<ull, int> dp, newdp;
  dp[1] = 1;

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  int aux = -1;
  bool indep = true;
  vector<int> basis;
  vector<int> xsum(n), prt(n, -1), out(n);
  function<void(int)> ins = [&](int x) {
    //cerr << "INSTO BASIS " << x << '\n';
    for (int i = 0; i < 5; ++i)
      if ((x >> i) & 1) {
        if (basis[i])
          x ^= basis[i];
        else {
          basis[i] = x;
          return;
        }
      }
    indep = false;
  };
  function<void(int)> dfs = [&](int u) {
    for (auto[v, w] : g[u]) {
      if (v == prt[u]) continue;
      if (prt[v] == -1 && v != 0) {
        prt[v] = u;
        xsum[v] = w ^ xsum[u];
        dfs(v);
      } else if (v == 0)
        aux = w ^ xsum[u] ^ xsum[v];
      else if (!out[v])
        ins(w ^ xsum[u] ^ xsum[v]);
    }
    out[u] = true;
  };
  unordered_map<ull, ull> bt;
  auto trans = [&](int w) -> void {
    if (!indep)
      return;
    for (auto[key, y] : dp) {
      ull x = key;
      bool fl = true;
      for (int v : basis) {
        if (v == 0) continue;
        if ((x >> v) & 1) {
          fl = false;
          break;
        }
        if (bt.count(x | (1ull << v)))
          x = bt[x | (1ull << v)];
        else {
          ull past = x;
          for (int i = 0; i < 32; ++i)
            if ((x >> i) & 1)
              x |= 1ULL << (i ^ v);
          bt.insert(make_pair(past | (1ull << v), x));
        }
      }
      if (fl)
        add(newdp[x], norm(y * w));
    }
  };
  for (auto[v, w] : g[0])
    if (prt[v] == -1) {
      xsum[v] = w;
      prt[v] = 0;
      indep = true;
      basis.assign(5, 0);
      aux = -1;
      dfs(v);
      //cerr << "fafa " << aux << '\n';
      newdp = dp;
      if (aux == -1) {
        trans(1);
      } else {
        trans(2);
        ins(aux);
        trans(1);
      }
      swap(dp, newdp);
    }
  int ans = 0;
  for (auto[ig, v] : dp)
    add(ans, v);
  cout << ans;

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}