#include<bits/stdc++.h>

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
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    vector< int > L(N), R(N);
    vector< int > xs;
    for(int i = 0; i < N; i++) {
      cin >> L[i] >> R[i];
      xs.emplace_back(L[i]);
      xs.emplace_back(R[i]);
    }
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
    vector< vector< int > > latte(xs.size()), malta(xs.size());
    int add = 0;
    for(int i = 0; i < N; i++) {
      if(L[i] < R[i]) {
        L[i] = lower_bound(begin(xs), end(xs), L[i]) - begin(xs);
        R[i] = lower_bound(begin(xs), end(xs), R[i]) - begin(xs);
        latte[L[i]].emplace_back(R[i]);
        malta[R[i]].emplace_back(L[i]);
      } else {
        ++add;
      }
    }
    auto dp = make_v< int >(xs.size(), xs.size());
    fill_v(dp, -1);
    auto rec = MFP([&](auto rec, int l, int r) -> int {
      if(l > r) return 0;
      if(~dp[l][r]) return dp[l][r];
      int ret = max(rec(l + 1, r), rec(l, r - 1));
      int tap = 0;
      for(auto &m : latte[l]) {
        if(m == r) ++tap;
        if(m < r) chmax(ret, rec(l, m) + rec(m + 1, r));
      }
      for(auto &m : malta[r]) {
        if(l < m) chmax(ret, rec(l, m - 1) + rec(m, r));
      }
      return dp[l][r] = ret + tap;
    });
    cout << rec(0, (int) xs.size() - 1) + add << "\n";
  }
}