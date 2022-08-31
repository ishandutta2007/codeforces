#include <bits/stdc++.h>

using namespace std;


using int64 = long long;
const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

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

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

int main() {
  int N;
  cin >> N;
  vector< int64 > A(N);
  cin >> A;
  map< int64, queue< int > > que;
  for(int i = 0; i < N; i++) {
    que[A[i]].emplace(i);
  }

  int M;
  cin >> M;


  auto B(A);
  sort(B.rbegin(), B.rend());

  vector< pair< int, int > > qs[200001];
  for(int i = 0; i < M; i++) {
    int k, p;
    cin >> k >> p;
    --k, --p;
    qs[k].emplace_back(p, i);
  }

  vector< int > ans(M);
  using pi = pair< int, int >;
  tree< pi, null_type, less< pi >, rb_tree_tag, tree_order_statistics_node_update > beet;
  for(int i = 0; i < N; i++) {
    int idx = que[B[i]].front();
    que[B[i]].pop();
    beet.insert(pi(idx, B[i]));
    for(auto &q : qs[i]) {
      ans[q.second] = beet.find_by_order(q.first)->second;
    }
  }
  for(auto &p : ans) cout << p << "\n";
}