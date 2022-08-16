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
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector< int > a(n);
    cin >> a;
    int l = 0;
    int ret = -inf, x = n, y = n;
    while(l < n) {
      if(a[l] == 0) {
        ++l;
        continue;
      }
      int r = l;
      vector< int > vs;
      int in = inf, out = -inf, cnt = 0;
      while(r < n and a[r] != 0) {
        if(a[r] < 0) {
          chmin(in, (int) vs.size());
          chmax(out, (int) vs.size());
          ++cnt;
        }
        vs.emplace_back(a[r]);
        ++r;
      }
      vector< pair< int, int > > ranges;
      if(cnt & 1) {
        ranges.emplace_back(in + 1, vs.size());
        ranges.emplace_back(0, out);
      } else {
        ranges.emplace_back(0, vs.size());
      }
      for(auto&[s, t]: ranges) {
        int score = 0;
        for(int i = s; i < t; i++) score += abs(vs[i]) == 2;
        if(chmax(ret, score)) {
          x = s + l;
          y = t + l;
        }
      }
      l = r;
    }
    cout << x << " " << n - y << "\n";
  }
}