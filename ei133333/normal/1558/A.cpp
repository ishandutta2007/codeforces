#pragma GCC optimize ("O3")
#pragma GCC target ("avx")

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
    int A, B;
    cin >> A >> B;

    vector< pair< int, int > > vs;
    int C = (A + B);
    if(C % 2 == 0) {
      vs.emplace_back(C / 2, C / 2);
    } else {
      vs.emplace_back(C / 2, C / 2 + 1);
      vs.emplace_back(C / 2 + 1, C / 2);
    }
    vector< int > imos(C + 10);
    for(auto&[x, y]:vs) {
      for(int a = 0; a <= min(y, A); a++) {
        int L = (B + a) - y;
        int R = (x + a) - A + 1;
        if(L < R) {
          L = max(L, 0);
          if(R > 0) {
            imos[min(C + 9, L + a)]++;
            imos[min(C + 9, R + a)]--;
          }
        }
      }
    }
    vector< int > ans;
    for(int i = 0; i <= C; i++) {
      if(i) imos[i] += imos[i - 1];
      if(imos[i]) ans.emplace_back(i);
    }
    cout << ans.size() << "\n";
    for(auto &p : ans) cout << p << " ";
    cout << "\n";
  }
}