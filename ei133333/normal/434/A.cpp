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
  int N, M;
  cin >> N >> M;
  vector< int > A(M);
  cin >> A;
  vector< int > V[100001];
  int64 all = 0;
  for(int i = 0; i < M; i++) {
    if(i and A[i - 1] != A[i]) {
      V[A[i]].emplace_back(A[i - 1]);
      all += abs(A[i] - A[i - 1]);
    }
    if(i + 1 < M and A[i + 1] != A[i]) {
      V[A[i]].emplace_back(A[i + 1]);
    }
  }
  int64 best = 0;
  for(int i = 1; i <= N; i++) {
    sort(begin(V[i]), end(V[i]));
    vector< int64 > S(V[i].size() + 1);
    int64 base = 0;
    for(int j = 0; j < V[i].size(); j++) {
      S[j + 1] = S[j] + V[i][j];
      base += abs(V[i][j] - i);
    }
    int64 ret = infll;
    for(int j = 0; j < V[i].size(); j++) {

      int64 uku = 0;
      /*
      for(int k = 0; k < V[i].size(); k++) {
        uku += abs(V[i][k] - V[i][j]);
      }
      chmin(ret, uku);
       */
      uku += 1LL * V[i][j] * j;
      uku -= S[j];
      uku -= (int64) (V[i].size() - j) * V[i][j];
      uku += S.back() - S[j];
      chmin(ret, uku);
    }
    chmax(best, base - ret);
  }
  cout << all - best << "\n";
}