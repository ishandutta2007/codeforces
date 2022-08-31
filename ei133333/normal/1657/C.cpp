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

vector< int > manacher(const string &s) {
  vector< int > radius(s.size());
  int i = 0, j = 0;
  while(i < s.size()) {
    while(i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) {
      ++j;
    }
    radius[i] = j;
    int k = 1;
    while(i - k >= 0 && i + k < s.size() && k + radius[i - k] < j) {
      radius[i + k] = radius[i - k];
      ++k;
    }
    i += k;
    j -= k;
  }
  return radius;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int now = 0;
    int ret = 0;
    while(now < N) {
      bool g = false;
      for(int len = 2;; len *= 2) {
        auto f = [&]() -> bool {
          int nxt = inf, d = 0;
          for(int i = 0; i < len; i++) {
            if(now + i < N) {
              d += S[now + i] == '(' ? 1 : -1;
              if(d < 0) break;
              if(d == 0) {
                nxt = now + i + 1;
                break;
              }
            }
          }
          string T;
          for(int i = 0; i < len; i++) {
            if(now + i < N) {
              T += S[now + i];
              T += "$";
            }
          }
          auto z = manacher(T);
          for(int i = 1; i < z.size(); i++) {
            if(z[i] == i + 1) {
              chmin(nxt, now + i + 1);
            }
          }
          if(nxt <= N) {
            now = nxt;
            return true;
          } else {
            return false;
          }
        };
        if(f()) {
          ++ret;
          g = true;
          break;
        }
        if(now + len >= N) {
          break;
        }
      }
      if(not g) break;
    }
    cout << ret << " " << N - now << "\n";
  }
}