#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

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
inline bool chmin(T1 &a, T2 b) {
  // if(b < 0)b *= -1; // 
  return a > b && (a = b, true);
}

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
  // 4, 7, 0
  vector< tuple< int, int, int > > nxt[10];
  for(int i = 0; i <= 6; i++) {
    for(int j = 0; i + j <= 6; j++) {
      nxt[(i * 4 + j * 7) % 10].emplace_back(i * 4 + j * 7, i, j);
    }
  }
  for(int i = 0; i < 10; i++) {
    sort(nxt[i].rbegin(), nxt[i].rend());
  }

  auto buf = make_v< int >(20, 2);
  while(T--) {
    int64 N;
    cin >> N;
    auto rec = MFP([&](auto rec, int64 N, int dep) -> bool {
      if(N == 0) {
        vector< int64 > ans(6);
        for(int64 i = 0, v = 1; i < dep; i++, v *= 10) {
          int k = 0;
          for(int j = 0; j < buf[i][0]; j++) {
            ans[k++] += 4 * v;
          }
          for(int j = 0; j < buf[i][1]; j++) {
            ans[k++] += 7 * v;
          }
        }
        cout << ans << "\n";
        return true;
      }
      for(auto&[coef, i, j] : nxt[N % 10]) {
        buf[dep][0] = i;
        buf[dep][1] = j;
        if(coef <= N and rec((N - coef) / 10, dep + 1)) {
          return true;
        }
      }
      return false;
    });
    if(not rec(N, 0)) {
      cout << -1 << "\n";
    }
  }
}