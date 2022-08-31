#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
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

int main() {
  // ORAND
  vector< int > dp(1 << 3);
  for(int i = 0; i < (1 << 3); i++) {
    int ask = 0;
    string S;
    for(int j = 0; j < 3; j++) {
      for(int k = j + 1; k < 3; k++) {
        int x = (i >> j) & 1;
        int y = (i >> k) & 1;
        S += ((x | y) == 1) ? '1' : '0';
        S += ((x & y) == 1) ? '1' : '0';
      }
    }
    for(int j = 0; j < 6; j++) {
      if(S[j] == '1') dp[i] |= 1 << j;
    }
  }

  int N, K;
  cin >> N >> K;
  auto ask = [&](string op, int i, int j) {
    cout << op << " " << i + 1 << " " << j + 1 << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
  };

  vector< int > A(N);

  {
    string S;
    vector< int > conf;
    for(int j = 0; j < 3; j++) {
      for(int k = j + 1; k < 3; k++) {
        conf.emplace_back(ask("or", j, k));
        conf.emplace_back(ask("and", j, k));
      }
    }
    for(int i = 30; i >= 0; i--) {
      int bit = 0;
      for(int j = 0; j < 6; j++) {
        if((conf[j] >> i) & 1) bit |= 1 << j;
      }
      for(int j = 0; j < (1 << 3); j++) {
        if(bit == dp[j]) {
          for(int k = 0; k < 3; k++) {
            if((j >> k) & 1) {
              A[k] |= 1 << i;
            }
          }
        }
      }
    }
  }

  for(int i = 3; i < N; i++) {
    int u = ask("and", i, 0);
    int v = ask("or", i, 0);
    for(int j = 30; j >= 0; j--) {
      int andj = (u >> j) & 1;
      int orj = (v >> j) & 1;
      if((A[0] >> j) & 1) {
        if(andj) A[i] |= 1 << j;
      } else {
        if(orj) A[i] |= 1 << j;
      }
    }
  }
  sort(begin(A), end(A));
  cout << "finish " << A[K - 1] << "\n";
  cout.flush();
}