#include<bits/stdc++.h>

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

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;


    vector< int > L(N + 1), R(N + 1), Q(N + 1);
    int X = 0;
    for(int i = 1; i <= N; i++) {
      if(S[i - 1] == '+') {
        ++X;
      } else {
        --X;
      }
      L[i] = min(L[i - 1], X);
      R[i] = max(R[i - 1], X);
      Q[i] = X;
    }

    vector< int > A(N + 1), B(N + 1), C(N + 1);
    X = 0;
    for(int i = N - 1; i >= 0; i--) {
      if(S[i] == '+') {
        --X;
      } else {
        ++X;
      }
      A[i] = min(A[i + 1], X);
      B[i] = max(B[i + 1], X);
      C[i] = X;
    }

    for(int i = 0; i < M; i++) {
      int l, r;
      cin >> l >> r;
      --l;
      // [l, r) 
      int left = L[l];
      int right = R[l];
      int now = Q[l];
      chmin(left, now - (C[r] - A[r]));
      chmax(right, now + (B[r] - C[r]));
      cout << right - left + 1 << "\n";
    }
  }
}