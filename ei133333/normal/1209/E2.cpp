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


void beet() {
  int N, M;
  cin >> N >> M;

  auto A = make_v< int >(N, M);
  cin >> A;


  vector< pair< int, int > > ord(M);
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) chmax(ord[i].first, A[j][i]);
    ord[i].second = i;
  }

  sort(ord.rbegin(), ord.rend());
  while(ord.size() > 12) ord.pop_back();
  auto max_match = make_v< int >(ord.size(), 1 << N);

  vector< vector< int > > tap(1 << N);
  for(int i = 0; i < (1 << N); i++) {
    for(int j = 0; j < N; j++) {
      if((i >> j) & 1) tap[i].emplace_back(j);
    }
  }

  for(int i = 0; i < ord.size(); i++) {
    int idx = ord[i].second;
    for(int j = 0; j < (1 << N); j++) {
      int sum = 0;
      for(int k = 0; k < N; k++) {
        int add = 0;
        for(int l : tap[j]) {
          if(l + k >= N) add += A[(l + k) - N][idx];
          else add += A[l + k][idx];
        }
        chmax(sum, add);
      }
      max_match[i][j] = sum;
    }
  }
  auto dp = make_v< int >(1 << N, ord.size());
  fill_v(dp, -1);
  auto rec = MFP([&](auto rec, int bit, int idx) -> int {
    if(idx == ord.size()) return bit == 0 ? 0 : -inf;
    if(~dp[bit][idx]) return dp[bit][idx];
    int ret = rec(bit, idx + 1);
    for(int i = bit; i > 0; i = (i - 1) & bit) {
      chmax(ret, max_match[idx][i] + rec(i ^ bit, idx + 1));
    }
    return dp[bit][idx] = ret;
  });
  cout << rec((1 << N) - 1, 0) << endl;
}


int main() {
  int T;
  cin >> T;
  while(T--) beet();
}