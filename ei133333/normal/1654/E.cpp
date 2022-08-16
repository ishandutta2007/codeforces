#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
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
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
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


int vs[60000001];
int ptr[60000001];
const int S = 50000000;

int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  memset(ptr, -1, sizeof(ptr));
  int luz = 0;

  auto solve = [&]() -> int {
    int ret = 0;
    for(int i = 0; i <= 333; i++) {
      for(int j = 0; j < N; j++) {
        int d = A[j] - j * i + S;
        if(ptr[d] != luz) {
          ptr[d] = luz;
          vs[d] = 0;
        }
        chmax(ret, ++vs[d]);
      }
      ++luz;
    }
    for(int i = 0; i < N; i++) {
      for(int j = 1; j <= 333 and i + j < N; j++) {
        if((A[i] < A[i + j]) and (A[i + j] - A[i]) % j == 0) {
          int d = (A[i + j] - A[i]) / j;
          if(ptr[d] != luz) {
            ptr[d] = luz;
            vs[d] = 1;
          }
          chmax(ret, ++vs[d]);
        }
      }
      ++luz;
    }
    return ret;
  };
  reverse(begin(A), end(A));
  int ret = solve();
  reverse(begin(A), end(A));
  cout << N - max(ret, solve()) << "\n";
}