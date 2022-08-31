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

using P = pair< int64, int64 >;

int main() {
  P a[3], b[3];
  for(int i = 0; i < 3; i++) cin >> a[i] >> b[i];


  auto solve = [](vector< P > a, vector< P > b) {
    int64 ret = 0;
    for(int i = 1; i < (1 << a.size()); i++) {
      P x(-infll, -infll), y(infll, infll);
      for(int j = 0; j < 3; j++) {
        if((i >> j) & 1) {
          chmax(x.first, a[j].first);
          chmax(x.second, a[j].second);
          chmin(y.first, b[j].first);
          chmin(y.second, b[j].second);
        }
      }
      if(x.first < y.first && x.second < y.second) {
        int64 add = (y.first - x.first) * (y.second - x.second);
        if(__builtin_parity(i)) ret += add;
        else ret -= add;
      }
    }
    return ret;
  };
  if(solve({a[0], a[1], a[2]}, {b[0], b[1], b[2]}) == solve({a[1], a[2]}, {b[1], b[2]})) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}