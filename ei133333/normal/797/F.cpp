#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
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
  int N, M;
  cin >> N >> M;
  vector< int64 > X(N);
  cin >> X;
  sort(begin(X), end(X));

  vector< int64 > P(M), C(M);
  int64 sum = 0;
  vector< int64 > xs;
  for(int i = 0; i < M; i++) {
    cin >> P[i] >> C[i];
    sum += C[i];
    xs.emplace_back(P[i]);
  }
  if(sum < N) {
    cout << -1 << endl;
    return 0;
  }
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  vector< int64 > D(N + 1);
  for(int i = 0; i < N; i++) {
    D[i + 1] += D[i];
    D[i + 1] += X[i];
  }
  vector< int64 > mx(xs.size());
  for(int i = 0; i < M; i++) {
    P[i] = lower_bound(begin(xs), end(xs), P[i]) - begin(xs);
    mx[P[i]] += C[i];
  }
  auto dp = make_v< int64 >(N + 1);
  fill_v(dp, infll);
  dp[0] = 0;
  int64 ptr = 0;

  int used = 0;

  for(int i = 0; i < xs.size(); i++) {
    if(mx[i] > 0) {


      auto dp2(dp);
      while(ptr < N && X[ptr] < xs[i]) ++ptr;
      // [0, ptr) [ptr, N)

      {
        vector< int64 > ushitapu(N + 1, infll);
        for(int k = ptr; k <= N; k++) {
          ushitapu[k] = dp[k] - D[k] + xs[i] * k;
        }
        for(int k = N - 2; k >= ptr; k--) {
          chmin(ushitapu[k], ushitapu[k + 1]);
        }
        for(int j = ptr + 1; j <= N; j++) {
          int left = max(j - mx[i], ptr);
          chmin(dp2[j], ushitapu[left] + D[j] - xs[i] * j);
        }
      }


      {
        vector< int64 > ushitapu(ptr);
        for(int k = 0; k < ptr; k++) {
          ushitapu[k] = dp[k] - xs[i] * k + D[k];
        }
        for(int k = ptr - 2; k >= 0; k--) {
          chmin(ushitapu[k], ushitapu[k + 1]);
        }

        for(int j = ptr + 1; j <= N; j++) {
          int64 malta = (D[j] - D[ptr]) - xs[i] * (j - ptr);
          int left = max(0LL, j - mx[i]);
          if(left <= ptr - 1) {
            chmin(dp2[j], ushitapu[left] + malta + xs[i] * ptr - D[ptr]);
          }
        }
      }

      {

        vector< int64 > ushitapu(ptr);
        for(int k = 0; k < ptr; k++) {
          ushitapu[k] = -xs[i] * k + D[k] + dp[k];
        }
        for(int k = ptr - 2; k >= 0; k--) {
          chmin(ushitapu[k], ushitapu[k + 1]);
        }

        for(int j = 1; j <= ptr; j++) {
          int left = max(j - mx[i], 0LL);
          chmin(dp2[j], ushitapu[left]+xs[i]*j-D[j]);
        }
      }

      used += mx[i];

      dp.swap(dp2);
    }
  }
  cout << dp[N] << endl;
}