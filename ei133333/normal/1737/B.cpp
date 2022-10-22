#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;

const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for (int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for (T &in: v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for (auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint: F {
  explicit FixPoint(F &&f): F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

#line 1 "math/number-theory/kth-root-integer.hpp"
/**
 * @brief Kth Root Integer
 * @docs docs/kth-root-integer.md
 */
uint64_t kth_root_integer(uint64_t a, int k) {
  if(k == 1) return a;
  auto check = [&](uint32_t x) {
    uint64_t mul = 1;
    for(int j = 0; j < k; j++) {
      if(__builtin_mul_overflow(mul, x, &mul)) return false;
    }
    return mul <= a;
  };
  uint64_t ret = 0;
  for(int i = 31; i >= 0; i--) {
    if(check(ret | (1u << i))) ret |= 1u << i;
  }
  return ret;
}

void beet() {
  int64 l, r;
  cin >> l >> r;
  auto f = [](int64 n)-> int64 {
    if(n == 0) return 0;
    int64 ret = -2;
    ret += n % kth_root_integer(n, 2) == 0;
    ret += kth_root_integer(4 * n, 2) + kth_root_integer(n - 1, 2);
    return ret;
  };
  cout << f(r) - f(l - 1) << endl;
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    beet();
  }
}