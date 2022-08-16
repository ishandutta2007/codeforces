#include<bits/stdc++.h>

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
    int N;
    cin >> N;
    string S;
    cin >> S;
    // A
    // 1(:  a
    //    ):  b
    // 0(:  c
    //   ):   d
    // a+c-(b+d) = 0
    // a+d-(b+c) = 0
    // a=b  c=d

    int one = 0, zero = 0;
    for(int i = 0; i < N; i++) {
      if(S[i] == '1') ++one;
      else zero++;
    }
    if(one % 2 or zero % 2) {
      cout << "NO\n";
      continue;
    } else {
      int o = 0, z = 0;
      vector< char > x(N), y(N);
      for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
          ++o;
          if(o + o <= one) {
            x[i] = '(';
            y[i] = '(';
          } else {
            x[i] = ')';
            y[i] = ')';
          }
        } else {
          ++z;
          if(z & 1) {
            x[i] = '(';
            y[i] = ')';
          } else {
            x[i] = ')';
            y[i] = '(';
          }
        }
      }

      int s = 0, t = 0;
      bool f = true;
      for(int i = 0; i < N; i++) {
        if(x[i] == '(') ++s;
        else --s;
        if(y[i] == '(') ++t;
        else --t;
        if(s < 0 or t < 0) {
          f = false;
        }
      }
      if(f) {
        cout << "YES\n";
        for(auto& c : x) cout << c;
        cout << "\n";
        for(auto& c : y) cout << c;
        cout << "\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}