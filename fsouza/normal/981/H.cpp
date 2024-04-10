#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;
typedef unsigned int uint;

template<typename T, typename U, typename B> struct ModularFFT {
  //>> Only FFT.
  inline T ifmod(U v, T mod) { return v >= (U)mod ? v - mod : v; }
  T pow(T x, U y, T p) {
    T ret = 1, x2p = x;
    while (y) {
      if (y % 2) ret = (B)ret * x2p % p;
      y /= 2; x2p = (B)x2p * x2p % p;
    }
    return ret;
  }
  vector<T> fft(vector<T> y, T mod, T gen, bool invert = false) {
    int N = y.size(); assert(N == (N&-N));
    if (N == 0) return move(y);
    vector<int> rev(N);
    for (int i = 1; i < N; ++i) {
      rev[i] = (rev[i>>1]>>1) | (i&1 ? N>>1 : 0);
      if (rev[i] < i) swap(y[i], y[rev[i]]);
    }
    assert((mod-1)%N == 0);
    T rootN = pow(gen, (mod-1)/N, mod);
    if (invert) rootN = pow(rootN, mod-2, mod);
    vector<T> rootni(N/2);
    for (int n = 2; n <= N; n *= 2) {
      T rootn = pow(rootN, N/n, mod);
      rootni[0] = 1;
      for (int i = 1; i < n/2; ++i) rootni[i] = (B)rootni[i-1] * rootn % mod;
      for (int left = 0; left != N; left += n) {
	int mid = left + n/2;
	for (int i = 0; i < n/2; ++i) {
	  T temp = (B)rootni[i] * y[mid+i] % mod;
	  y[mid+i] = ifmod((U)y[left+i] + mod - temp, mod);
	  y[left+i] = ifmod((U)y[left+i] + temp, mod);
	}
      }
    }
    if (invert) {
      T invN = pow(N, mod-2, mod);
      for (T &v : y) v = (B)v * invN % mod;
    }
    return move(y);
  }
  //<<
  vector<T> convolution(vector<T> a, vector<T> b, T mod, T gen) {
    int N = a.size()+b.size()-1, N2 = nextpow2(N);
    a.resize(N2); b.resize(N2);
    vector<T> fa = fft(move(a), mod, gen), fb = fft(move(b), mod, gen), &fc = fa;
    for (int i = 0; i < N2; ++i) fc[i] = (B)fc[i] * fb[i] % mod;
    vector<T> c = fft(move(fc), mod, gen, true);
    c.resize(N); return move(c);
  }
  vector<T> circular_convolution(vector<T> a, vector<T> b, T mod, T gen) {
    assert(a.size() == b.size()); int N = a.size();
    vector<T> ret = convolution(move(a), move(b), mod, gen);
    for (int i = ret.size()-1; i >= N; --i) ret[i-N] = ifmod((U)ret[i-N] + ret[i], mod);
    ret.resize(N); return move(ret);
  }
  uint nextpow2(uint v) { return v ? 1 << __lg(2*v-1) : 1; }
};

int modpow(int x, int y, int mod) {
  int ret = 1 % mod, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % mod;
    y /= 2;
    x2p = (lint)x2p * x2p % mod;
  }
  return ret;
}

const int mod = 998244353, mod_gen = 3;

int inv(int v) { return modpow(v, mod - 2, mod); }

vector<int> convolute(const vector<int> &a, const vector<int> &b) {
  if (a.empty() || b.empty()) return {};
  ModularFFT<int, uint, lint> modular_fft;
  return modular_fft.convolution(a, b, mod, mod_gen);
}

vector<int> convolute_all(const vector<vector<int>> &polys, int begin,
                          int end) {
  if (end - begin == 0) return {1};
  else if (end - begin == 1) return polys[begin];
  else {
    int mid = begin + (end - begin) / 2;
    return convolute(convolute_all(polys, begin, mid),
                     convolute_all(polys, mid, end));
  }
}

vector<int> convolute_all(const vector<vector<int>> &polys) {
  return convolute_all(polys, 0, (int)polys.size());
}

void mod_add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

vector<int> fact, inv_fact;

void precalc(int lim) {
  fact.resize(lim + 1);
  fact[0] = 1;
  for (int i = 1; i <= lim; ++i)
    fact[i] = (lint)i * fact[i - 1] % mod;

  inv_fact.resize(lim + 1);
  inv_fact[lim] = inv(fact[lim]);
  for (int i = lim - 1; i >= 0; --i)
    inv_fact[i] = (lint)(i + 1) * inv_fact[i + 1] % mod;
}

int binom(int a, int b) {
  if (!(0 <= b && b <= a)) return 0;
  return (lint)fact[a] * inv_fact[b] % mod * inv_fact[a - b] % mod;
}

struct solver_t {
  int n, k;
  vector<vector<int>> adj;
  vector<int> subtree_size, subtree_nway;
  int final_result = 0;
  solver_t(int _n, int _k): n(_n), k(_k), adj(n), subtree_size(n)
                          , subtree_nway(n) {}
  vector<int> compute_partial_nway(const vector<int> &sizes) {
    vector<vector<int>> polys;
    for (int s : sizes)
      polys.push_back({1, s});
    return convolute_all(polys);
  }
  int compute_nway(const vector<int> &partial) {
    if (k == 1) return 1;
    int result = 0;
    for (int i = 0; i <= min((int)partial.size() - 1, k); ++i)
      result = (result + (lint)binom(k, i) * partial[i] % mod * fact[i]) % mod;
    return result;
  }
  void dfs(int v, int p) {
    map<int, vector<int>> children_with_size;
    vector<int> children_sizes;
    subtree_size[v] = 1;
    subtree_nway[v] = 0;
    for (int u : adj[v])
      if (u != p) {
        dfs(u, v);
        subtree_size[v] += subtree_size[u];
        mod_add(subtree_nway[v], subtree_nway[u]);
        children_with_size[subtree_size[u]].push_back(u);
        children_sizes.push_back(subtree_size[u]);
      }

    vector<int> partial_nway = compute_partial_nway(children_sizes);
    mod_add(subtree_nway[v], compute_nway(partial_nway));

    if (p != -1) {
      partial_nway_add(partial_nway, n - subtree_size[v]);
    }
    int children_acc_nway = 0;
    for (const auto &it : children_with_size) {
      int size = it.first;
      const vector<int> &children = it.second;
      partial_nway_remove(partial_nway, size);
      int others_nway = compute_nway(partial_nway);
      for (int c : children) {
        final_result =
          (final_result + (lint)children_acc_nway * subtree_nway[c]) % mod;
        mod_add(children_acc_nway, subtree_nway[c]);

        final_result =
          (final_result + (lint)others_nway * subtree_nway[c]) % mod;
      }
      partial_nway_add(partial_nway, size);
    }
  }
  void partial_nway_add(vector<int> &partial, int size) {
    if (!partial.empty() && partial.back() > 0 && size > 0)
      partial.push_back(0);
    for (int i = (int)partial.size() - 1; i >= 1; --i)
      partial[i] = (partial[i] + (lint)size * partial[i - 1]) % mod;
  }
  void partial_nway_remove(vector<int> &partial, int size) {
    for (int i = 1; i < (int)partial.size(); ++i) {
      partial[i] = (partial[i] - (lint)size * partial[i - 1]) % mod;
      if (partial[i] < 0) partial[i] += mod;
    }
  }
  int solve() {
    dfs(0, -1);
    return final_result;
  }
};

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  precalc(max(n, k));
  solver_t solver(n, k);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b), --a, --b;
    solver.adj[a].push_back(b);
    solver.adj[b].push_back(a);
  }
  printf("%d\n", solver.solve());
  return 0;
}