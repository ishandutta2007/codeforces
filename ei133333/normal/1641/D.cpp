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
  int N, M;
  cin >> N >> M;

  vector< vector< int > > A(N);
  vector< int > W(N);

  {
    auto $ = make_v< int >(N, M);
    vector< pair< int, int > > $$(N);
    for(int i = 0; i < N; i++) {
      cin >> $[i] >> $$[i].first;
      $$[i].second = i;
    }
    sort(begin($$), end($$));
    for(int i = 0; i < $$.size(); i++) {
      W[i] = $$[i].first;
      A[i] = $[$$[i].second];
    }
  }
  {
    vector< int > vs;
    vs.reserve(N * M);
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) vs.emplace_back(A[i][j]);
    }
    sort(begin(vs), end(vs));
    vs.erase(unique(begin(vs), end(vs)), end(vs));
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        A[i][j] = lower_bound(begin(vs), end(vs), A[i][j]) - begin(vs);
      }
      sort(begin(A[i]), end(A[i]));
    }
  }

  using i128 = __int128_t;
  vector< vector< vector< i128 > > > dp(M + 1, vector< vector< i128 > >(N));
  for(int j = 0; j < (1 << M); j++) {
    for(int i = 0; i < N; i++) {
      i128 d = 0;
      for(int k = 0; k < M; k++) {
        if((j >> k) & 1) {
          d *= 1000000;
          d += A[i][k];
        }
      }
      dp[__builtin_popcount(j)][i].emplace_back(d);
    }
  }
  int mx = 0;
  for(int i = 0; i <= M; i++) {
    vector< i128 > xs;
    xs.reserve(dp[i][0].size() * N);
    for(int j = 0; j < N; j++) {
      for(auto &k: dp[i][j]) {
        xs.emplace_back(k);
      }
    }
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
    for(int j = 0; j < N; j++) {
      for(int k = 0; k < dp[i][j].size(); k++) {
        dp[i][j][k] = lower_bound(begin(xs), end(xs), dp[i][j][k]) - begin(xs);
      }
    }
    chmax(mx, xs.size() + 1);
  }

  auto check = [&](int64 d) -> bool {
    vector< int > sum(N);
    for(int i = 0; i <= M; i++) {
      int j = 0;
      vector< int > uku(mx);
      for(int k = N - 1; k >= 0; k--) {
        while(j < N and W[k] + W[j] <= d) {
          for(auto &p: dp[i][j]) uku[p]++;
          ++j;
        }
        for(auto &p: dp[i][k]) {
          sum[k] += (i % 2 ? -1 : 1) * uku[p];
        }
      }
    }
    for(auto &p: sum) if(p) return true;
    return false;
  };
  int64 lim = 2000000000ll;
  int64 ok = lim + 1, ng = 1;
  while(ok - ng > 1ll) {
    int64 mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  if(ok == lim + 1) cout << "-1\n";
  else cout << ok << "\n";
}