#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H, typename P >
struct LazySegmentTree {
  int sz;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const P p;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h, const P p,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), p(p), M1(M1), OM0(OM0) {
    sz = 1;
    while(sz < n) sz <<= 1;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  void propagate(int k, int len) {
    if(lazy[k] != OM0) {
      if(k < sz) {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], p(lazy[k], len));
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return data[k];
    } else if(a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      propagate(k, r - l);
      return data[k];
    } else {
      return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                         update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x) {
    return update(a, b, x, 1, 0, sz);
  }


  Monoid query(int a, int b, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {
      return data[k];
    } else {
      return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
               query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid query(int a, int b) {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }
};

vector< bool > get_prime(int n) {
  vector< bool > prime(n + 1, true);

  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;

  for(int i = 2; i * i <= n; i++) {
    if(prime[i]) {
      for(int j = i + i; j <= n; j += i) prime[j] = false;
    }
  }

  return (prime);
}

int64 mod_pow(int64 x, int64 n) {
  int64 ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}


int main() {
  int N, Q, A[400000];
  char T[16];

  scanf("%d %d", &N, &Q);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }


  auto f1 = [](int64 a, int64 b) { return a * b % mod; };
  auto p1 = [](int64 a, int64 p) { return mod_pow(a, p); };
  LazySegmentTree< int64, int64, decltype(f1), decltype(f1), decltype(f1), decltype(p1) > seg1(N, f1, f1, f1, p1, 1, 1);

  auto f2 = [](int64 a, int64 b) { return a | b; };
  auto p2 = [](int64 a, int64 p) { return a; };
  LazySegmentTree< int64, int64, decltype(f2), decltype(f2), decltype(f2), decltype(p2) > seg2(N, f2, f2, f2, p2, 0, 0);


  auto p = get_prime(300);
  vector< int > primes;
  for(int i = 0; i < p.size(); i++) {
    if(p[i]) primes.emplace_back(i);
  }
  int inv[301];
  for(int i = 0; i < 301; i++) {
    inv[i] = mod_pow(i, mod - 2);
  }
  int64 bits[301] = {};
  for(int i = 0; i < primes.size(); i++) {
    for(int j = primes[i]; j < 301; j += primes[i]) {
      bits[j] |= 1LL << i;
    }
  }
  for(int i = 0; i < N; i++) {
    seg1.set(i, A[i]);
    seg2.set(i, bits[A[i]]);
  }
  seg1.build();
  seg2.build();

  while(Q--) {
    scanf(" %s", T);
    if(T[0] == 'M') {
      int L, R, X;
      scanf("%d %d %d", &L, &R, &X);
      --L;
      seg1.update(L, R, X);
      seg2.update(L, R, bits[X]);
    } else {
      int L, R;
      scanf("%d %d", &L, &R);
      --L;
      int64 ret = seg1.query(L, R);
      int64 bit = seg2.query(L, R);
      for(int64 i = 0; i < primes.size(); i++) {
        if((bit >> i) & 1) (ret += mod - ret * inv[primes[i]] % mod) %= mod;
      }
      printf("%d\n", ret);
    }
  }
}