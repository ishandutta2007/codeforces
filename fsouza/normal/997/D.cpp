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
  uint nextpow2(uint v) { return v ? 1 << __lg(2*v-1) : 1; }
};
ModularFFT<int, uint, lint> nfft;

const int max_max_size = 75;
const int mod = 998244353, gen = 3;

template<typename T1, typename T2>
T1 &add_mod(T1 &a, T2 b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

template<typename T1, typename T2>
T1 &sub_mod(T1 &a, T2 b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}

void halve(vector<int> &v) {
  for (int i = 0; 2 * i < (int)v.size(); ++i)
    v[i] = v[2 * i];
  v.resize(((int)v.size() + 1) / 2);
}

vector<int> convolute_even(vector<int> v0, vector<int> v1) {
  int new_size = v0.size() - 1 + v1.size() - 1 + 1;
  halve(v0);
  halve(v1);
  vector<int> result = nfft.convolution(v0, v1, mod, gen);
  result.resize(new_size);
  for (int i = (int)result.size() - 1; i >= 0; --i)
    if (i % 2 == 0) result[i] = result[i / 2];
    else result[i] = 0;
  return result;
}

int modpow(int x, int y, int m) {
  int ret = 1 % m, x2p = x;
  while (y > 0) {
    if (y % 2) ret = (lint)ret * x2p % m;
    y /= 2;
    x2p = (lint)x2p * x2p % m;
  }
  return ret;
}

int inv(int a, int p) { return modpow(a, p - 2, p); }

vector<int> fact, inv_fact;

void prepare_binom(int lim) {
  fact.resize(lim + 1);
  fact[0] = 1;
  for (int i = 1; i <= lim; ++i)
    fact[i] = (lint)i * fact[i - 1] % mod;

  inv_fact.resize(lim + 1);
  inv_fact[lim] = inv(fact[lim], mod);
  for (int i = lim - 1; i >= 0; --i)
    inv_fact[i] = (lint)(i + 1) * inv_fact[i + 1] % mod;
}

int binom(int a, int b) {
  if (!(0 <= b && b <= a)) return 0;
  return (lint)fact[a] * inv_fact[b] % mod * inv_fact[a - b] % mod;
}

struct solver_t {
  int n, max_size;
  vector<vector<int>> adj;
  vector<int> subtree_size;
  vector<bool> removed;
  vector<vector<int>> any_path_count;
  vector<vector<int>> single_path_count;
  vector<int> final_result;
  solver_t(int _n, int _max_size)
      : n(_n)
      , max_size(_max_size)
      , adj(n)
      , subtree_size(n)
      , removed(n)
      , any_path_count(n, vector<int>(max_size + 1))
      , single_path_count(n, vector<int>(max_size + 1))
      , final_result(max_size + 1) {}
  void compute_subtree_sizes(int v, int p) {
    subtree_size[v] = 1;
    for (int u : adj[v])
      if (!removed[u] && u != p) {
        compute_subtree_sizes(u, v);
        subtree_size[v] += subtree_size[u];
      }
  }
  int get_centroid(int v, int p, int tree_size) {
    for (int u : adj[v])
      if (!removed[u] && u != p && 2 * subtree_size[u] > tree_size)
        return get_centroid(u, v, tree_size);
    return v;
  }
  void update_dps(int v, int p, int k, int c) {
    if (k == 0) {
      if (v == c) {
        any_path_count[c][0] = 1;
        single_path_count[c][0] = 1;
      } else {
        any_path_count[v][0] = 0;
        single_path_count[v][0] = 0;
      }
    } else {
      any_path_count[v][k] = 0;
      single_path_count[v][k] = 0;
      for (int u : adj[v])
        if (!removed[u]) {
          add_mod(any_path_count[v][k], any_path_count[u][k - 1]);
          if (u != c || k == 1) {
            add_mod(single_path_count[v][k], single_path_count[u][k - 1]);
          }
        }
    }
    for (int u : adj[v])
      if (!removed[u] && u != p)
        update_dps(u, v, k, c);
  }
  void solve(int v) {
    compute_subtree_sizes(v, -1);
    int c = get_centroid(v, -1, subtree_size[v]);
    for (int k = 0; k <= max_size; ++k)
      update_dps(c, -1, k, c);
    vector<int> weighted_single_paths(max_size + 1);
    for (int k = 0; k <= max_size; ++k)
      weighted_single_paths[k] = (lint)k * single_path_count[c][k] % mod;
    vector<int> result =
        convolute_even(weighted_single_paths, any_path_count[c]);
    for (int k = 0; k <= max_size && k < (int)result.size(); ++k)
      add_mod(final_result[k], result[k]);
    add_mod(final_result[0], 1);
    removed[c] = true;
    for (int u : adj[c])
      if (!removed[u])
        solve(u);
  }
  vector<int> read_and_solve() {
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      scanf("%d %d", &a, &b), --a, --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    solve(0);
    return final_result;
  }
};

int main() {
  prepare_binom(max_max_size);

  int n1, n2, max_size;
  scanf("%d %d %d", &n1, &n2, &max_size);
  solver_t solver1(n1, max_size), solver2(n2, max_size);
  vector<int> res1 = solver1.read_and_solve(), res2 = solver2.read_and_solve();
  int result = 0;
  for (int i = 0; i <= max_size; ++i) {
    result = (result +
              (lint)binom(max_size, i) * res1[i] % mod * res2[max_size - i]) %
             mod;
  }
  printf("%d\n", result);
  return 0;
}