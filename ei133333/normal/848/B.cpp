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

int main() {
  //X[i]-T[i], Y[i]-T[i]

  int N, W, H;
  cin >> N >> W >> H;
  vector< int > G(N), P(N), T(N);
  vector< int > ev[202020];
  for(int i = 0; i < N; i++) {
    cin >> G[i] >> P[i] >> T[i];
    ev[P[i] - T[i] + 101010].emplace_back(i);
  }
  vector< int > X(N), Y(N);
  auto beet = [&](vector< int > &idx) {
    vector< pair< int, int > > xs;
    vector< int > ys;
    for(auto &i : idx) {
      if(G[i] == 2) {
        xs.emplace_back(-P[i], i);
        ys.emplace_back(inf - P[i]);
      } else {
        xs.emplace_back(P[i], i);
        ys.emplace_back(P[i]);
      }
    }
    sort(begin(xs), end(xs));
    sort(begin(ys), end(ys));
    for(int i = 0; i < xs.size(); i++) {
      if(ys[i] >= inf / 2) {
        ys[i] -= inf;
        ys[i] *= -1;
        X[xs[i].second] = W;
        Y[xs[i].second] = ys[i];
      } else {
        X[xs[i].second] = ys[i];
        Y[xs[i].second] = H;
      }
    }
  };

  for(int i = 0; i < 202020; i++) {
    if(ev[i].empty()) continue;
    beet(ev[i]);
  }
  for(int i = 0; i < N; i++) {
    cout << X[i] << " " << Y[i] << "\n";
  }
}