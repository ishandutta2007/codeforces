#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

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

template< typename T >
void fwt(vector< T > &f) {
  int n = f.size();
  for(int i = 1; i < n; i <<= 1) {
    for(int j = 0; j < n; j++) {
      if((j & i) == 0) {
        T x = f[j], y = f[j | i];
        f[j] = x + y, f[j | i] = x - y;
      }
    }
  }
}

template< typename T >
void ifwt(vector< T > &f) {
  int n = f.size();
  for(int i = 1; i < n; i <<= 1) {
    for(int j = 0; j < n; j++) {
      if((j & i) == 0) {
        T x = f[j], y = f[j | i];
        f[j] = (x + y) / 2, f[j | i] = (x - y) / 2;
      }
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  auto A = make_v< string >(N);
  cin >> A;
  vector< int64 > a(1 << N), b(1 << N);
  for(int j = 0; j < M; j++) {
    int bit = 0;
    for(int i = 0; i < N; i++) {
      bit <<= 1;
      bit |= A[i][j] - '0';
    }
    a[bit]++;
  }
  for(int i = 1; i < (1 << N); i++) {
    b[i] = b[i & (i - 1)] + 1;
  }
  for(int i = 0; i < (1 << N); i++) {
    chmin(b[i], N - b[i]);
  }
  fwt(a);
  fwt(b);
  for(int i = 0; i < (1 << N); i++) a[i] *= b[i];
  ifwt(a);
  cout << *min_element(begin(a), end(a)) << endl;
}