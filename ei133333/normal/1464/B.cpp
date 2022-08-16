#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

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
  string S;
  int64 X, Y;
  cin >> S >> X >> Y;
  int N = (int) S.size();

  int64 ret = infll;

  {
    // 000....111
    vector< int64 > one(N + 1), zero(N + 1), cost(N + 1);
    for(int i = N - 1; i >= 0; i--) {
      one[i] = one[i + 1];
      zero[i] = zero[i + 1];
      cost[i] = cost[i + 1];
      if(S[i] == '?' or S[i] == '1') {
        ++one[i];
        cost[i] += Y * zero[i];
      } else {
        ++zero[i];
        cost[i] += X * one[i];
      }
    }
    chmin(ret, cost[0]);
    int64 o = 0, z = 0, c = 0;
    for(int i = 0; i < N; i++) {
      if(S[i] == '0' or S[i] == '?') {
        ++z;
        c += Y * o;
      } else {
        ++o;
        c += X * z;
      }
      chmin(ret, cost[i + 1] + c + z * one[i + 1] * X + o * zero[i + 1] * Y);
    }
  }


  {
    // 111....000
    vector< int64 > one(N + 1), zero(N + 1), cost(N + 1);
    for(int i = N - 1; i >= 0; i--) {
      one[i] = one[i + 1];
      zero[i] = zero[i + 1];
      cost[i] = cost[i + 1];
      if(S[i] == '1') {
        ++one[i];
        cost[i] += Y * zero[i];
      } else {
        ++zero[i];
        cost[i] += X * one[i];
      }
    }
    chmin(ret, cost[0]);
    int64 o = 0, z = 0, c = 0;
    for(int i = 0; i < N; i++) {
      if(S[i] == '0') {
        ++z;
        c += Y * o;
      } else {
        ++o;
        c += X * z;
      }
      chmin(ret, cost[i + 1] + c + z * one[i + 1] * X + o * zero[i + 1] * Y);
    }
  }


  cout << ret << "\n";
}