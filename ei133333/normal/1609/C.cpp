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

vector< bool > prime_table(int n) {
  vector< bool > prime(n + 1, true);
  if(n >= 0) prime[0] = false;
  if(n >= 1) prime[1] = false;
  for(int i = 2; i * i <= n; i++) {
    if(!prime[i]) continue;
    for(int j = i + i; j <= n; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}

constexpr int MAX = 1000000;
auto P = prime_table(MAX);

void gazelle() {
  int n, e;
  cin >> n >> e;
  vector< int > a(n);
  cin >> a;
  vector< vector< int > > t(e);
  for(int i = 0; i < n; i++) {
    t[i % e].emplace_back(a[i]);
  }
  int64 ret = 0;
  for(int i = 0; i < e; i++) {
    vector< int > p{-1};
    for(int k = 0; k < t[i].size(); k++) {
      int s = p.back();
      p.emplace_back(s);
      if(t[i][k] != 1) p.back() = k;
    }
    vector< int > q{(int) t[i].size()};
    for(int k = (int) t[i].size() - 1; k >= 0; k--) {
      int s = q.back();
      q.emplace_back(s);
      if(t[i][k] != 1) q.back() = k;
    }
    reverse(begin(q), end(q));
    for(int k = 0; k < t[i].size(); k++) {
      if(P[t[i][k]]) {
        ret += 1LL * (q[k + 1] - k) * (k - p[k]) - 1;
      }
    }
  }
  cout << ret << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) gazelle();
}