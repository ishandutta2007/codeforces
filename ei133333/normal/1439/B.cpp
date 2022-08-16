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

/**
 * @brief Union-Find
 * @docs docs/union-find.md
 */
struct UnionFind {
  vector< int > data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) {
    return -data[find(k)];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  vector< vector< int > > g(N);
  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  for(int i = 0; i < N; i++) {
    sort(begin(g[i]), end(g[i]));
  }
  queue< int > que;
  vector< int > deg(N), used(N);
  for(int i = 0; i < N; i++) {
    deg[i] = g[i].size();
    if(deg[i] < K) {
      que.emplace(i);
    }
  }
  while(!que.empty()) {
    int idx = que.front();
    que.pop();
    if(used[idx]) continue;

    if(deg[idx] == K - 1) {
      vector< int > near{idx};
      for(auto &to : g[idx]) {
        if(used[to]) continue;
        near.emplace_back(to);
      }
      if([&]() {
        for(auto &p : near) {
          for(auto &q : near) {
            if(p < q) {
              if(!binary_search(begin(g[p]), end(g[p]), q)) return false;
            }
          }
        }
        return true;
      }()) {
        cout << 2 << "\n";
        for(auto& p : near) ++p;
        cout << near << "\n";
        return;
      }

    }

    used[idx] = true;
    for(auto &to : g[idx]) {
      if(used[to]) continue;
      --deg[to];
      if(deg[to] == K - 1) {
        que.emplace(to);
      }
    }
  }

  vector< int > rem;
  for(int i = 0; i < N; i++) {
    if(used[i]) continue;
    rem.emplace_back(i + 1);
  }
  if(rem.empty()) {
    cout << -1 << "\n";
    return;
  }
  cout << 1 << " " << rem.size() << "\n";
  cout << rem << "\n";
}


int main() {
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
}