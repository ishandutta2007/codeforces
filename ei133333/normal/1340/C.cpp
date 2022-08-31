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
  int N, M, G, R;
  cin >> N >> M;
  vector< int > D(M);
  cin >> D;
  sort(begin(D), end(D));
  cin >> G >> R;
  auto dp = make_v< int >(M, G + 1);
  fill_v(dp, inf);
  dp[0][0] = 0;
  using pii = pair< int, pair< int, int > >;
  deque< pii > que;
  que.emplace_back(0, make_pair(0, 0));
  while(!que.empty()) {
    int cost = que.front().first;
    int idx = que.front().second.first;
    int md = que.front().second.second;
    que.pop_front();

    if(idx > 0) {
      int nxt_add = D[idx] - D[idx - 1];
      if(md + nxt_add <= G) {
        if(chmin(dp[idx - 1][md + nxt_add], cost)) {
          que.emplace_front(cost, make_pair(idx - 1, md + nxt_add));
        }
      }
    }

    if(idx + 1 < M) {
      int nxt_add = D[idx + 1] - D[idx];
      if(md + nxt_add <= G) {
        if(chmin(dp[idx + 1][md + nxt_add], cost)) {
          que.emplace_front(cost, make_pair(idx + 1, md + nxt_add));
        }
      }
    }

    if(md == G) {
      if(chmin(dp[idx][0], cost + 1)) {
        que.emplace_back(cost + 1, make_pair(idx, 0));
      }
    }
  }
  int64 ret = infll;
  for(int i = 0; i <= G; i++) {
    if(dp[M - 1][i] == inf) continue;
    int64 add = dp[M - 1][i];
    chmin(ret, add * (G + R) + i);
  }
  if(ret >= infll) ret = -1;
  cout << ret << endl;
}