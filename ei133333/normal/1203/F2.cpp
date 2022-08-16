#include <bits/stdc++.h>

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
  int64 N, R;
  cin >> N >> R;
  vector< int > po[30001];
  vector< pair< int, int > > neg;
  for(int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    if(b >= 0) po[a].emplace_back(b);
    else neg.emplace_back(a, -b);
  }

  int64 ret = 0;
  for(int i = 0; i <= 30000; i++) {
    for(auto &p : po[i]) {
      if(R >= i) {
        R += p;
        ++ret;
      }
    }
  }

  if(neg.size()) {
    sort(begin(neg), end(neg), [](auto p, auto q) {
      return p.first - p.second > q.first - q.second;
    });
    vector< int64 > dp(neg.size() + 1);
    fill_v(dp, -infll);
    dp[0] = R;
    for(auto p : neg) {
      for(int j = (int) neg.size() - 1; j >= 0; j--) {
        if(dp[j] >= p.first && dp[j] - p.second >= 0) {
          chmax(dp[j + 1], dp[j] - p.second);
        }
      }
    }
    for(int j = neg.size(); j >= 0; j--) {
      if(dp[j] >= 0) {
        ret += j;
        break;
      }
    }
  }
  cout << ret << endl;
}