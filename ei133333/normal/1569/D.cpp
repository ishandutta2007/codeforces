#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using pi = pair< int, int >;


tree< pi, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update > latteX[1000001], maltaY[1000001];

void beet() {

  int N, M, K;
  cin >> N >> M >> K;
  vector< int > X(N), Y(M);
  cin >> X >> Y;

  set< int > xs, ys;
  for(int i = 0; i < N; i++) xs.emplace(X[i]);
  for(int i = 0; i < M; i++) ys.emplace(Y[i]);

  int64 ret = 0;
  tree< pi, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update > latte, malta;

  for(int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;

    auto is_x = xs.find(x) != end(xs);
    auto is_y = ys.find(y) != end(ys);

    if(is_x and is_y) {
      continue;
    }
    if(is_x) {
      auto h = ys.lower_bound(y);
      auto l = prev(h);
      // count [l+1,h)
      ret += malta.order_of_key(pi(*h, -inf)) - malta.order_of_key(make_pair(*l, inf));
      ret -= maltaY[x].order_of_key(pi(*h, -inf)) - maltaY[x].order_of_key(make_pair(*l, inf));
      malta.insert(make_pair(y, i));
      maltaY[x].insert(make_pair(y, i));
    } else if(is_y) {
      auto h = xs.lower_bound(x);
      auto l = prev(h);
      ret += latte.order_of_key(pi(*h, -inf)) - latte.order_of_key(make_pair(*l, inf));
      ret -= latteX[y].order_of_key(pi(*h, -inf)) - latteX[y].order_of_key(make_pair(*l, inf));
      latte.insert(make_pair(x, i));
      latteX[y].insert(make_pair(x, i));
    } else {
      throw 0;
    }
  }
  cout << ret << "\n";
  for(int i = 0; i < N; i++) maltaY[X[i]].clear();
  for(int i = 0; i < M; i++) latteX[Y[i]].clear();
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    beet();
  }
}