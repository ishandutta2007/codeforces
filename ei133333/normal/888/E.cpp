#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 104857601;


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
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
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
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

int main() {
  int N, M;
  cin >> N >> M;

  int V = N / 2;
  vector< int > A(V), B(N - V);
  cin >> A >> B;

  vector< int64 > tap;
  int64 uku = 0;
  for(int i = 0; i < (1 << A.size()); i++) {
    int64 ret = 0;
    for(int j = 0; j < A.size(); j++) {
      if((i >> j) & 1) ret += A[j];
    }
    ret %= M;
    tap.emplace_back(ret);
  }
  sort(begin(tap), end(tap));
  tap.erase(unique(begin(tap), end(tap)), end(tap));
  for(int i = 0; i < (1 << B.size()); i++) {
    int64 ret = 0;
    for(int j = 0; j < B.size(); j++) {
      if((i >> j) & 1) ret += B[j];
    }
    ret %= M;
    int sub = M - ret;
    auto p = lower_bound(begin(tap), end(tap), sub);
    if(begin(tap) == p) p = prev(end(tap));
    else --p;
    chmax(uku, (*p + ret) % M);
  }
  cout << uku << endl;
}