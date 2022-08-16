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

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};


vector< int > tap[1000 * 2520];
vector< int > be[1000 * 2520];

int main() {
  int N;
  cin >> N;
  vector< int > K(N);
  cin >> K;
  vector< int > g[1000];
  for(int i = 0; i < N; i++) {
    int M;
    cin >> M;
    for(int j = 0; j < M; j++) {
      int x;
      cin >> x;
      --x;
      g[i].emplace_back(x);
    }
  }

  for(int i = 0; i < N; i++) {
    K[i] %= 2520;
    K[i] += 2520;
    K[i] %= 2520;
  }


  UnionFind uf(N * 2520);
  vector< int > in(N * 2520);
  for(int i = 0; i < N; i++) {
    for(int cur_v = 0; cur_v < 2520; cur_v++) {
      int to = g[i][cur_v % g[i].size()];
      int nxt_v = cur_v;
      nxt_v += K[to];
      nxt_v %= 2520;
      nxt_v += 2520;
      nxt_v %= 2520;
      tap[i * 2520 + cur_v].emplace_back(to * 2520 + nxt_v);
      uf.unite(i * 2520 + cur_v, to * 2520 + nxt_v);
      in[to * 2520 + nxt_v]++;
    }
  }




  // ()
  vector< int > ans(N * 2520);

  vector< int > used(N, -1);
  for(int i = 0; i < N * 2520; i++) {
    be[uf.find(i)].emplace_back(i);
  }
  for(int i = 0; i < N * 2520; i++) {
    if(be[i].empty()) continue;
    queue< int > que;
    for(auto &p : be[i]) {
      if(in[p] == 0) {
        que.emplace(p);
      }
    }
    while(que.size()) {
      int p = que.front();
      que.pop();
      for(auto &to : tap[p]) {
        --in[to];
        if(in[to] == 0) que.emplace(to);
      }
    }
    int add = 0;
    for(auto &p : be[i]) {
      if(in[p] > 0) {
        if(used[p / 2520] == i) continue;
        used[p / 2520] = i;
        ++add;
      }
    }
    for(auto &p : be[i]) {
      ans[p] = add;
    }
  }

  int Q;
  cin >> Q;
  while(Q--) {
    int X, Y;
    cin >> X >> Y;
    --X;
    Y += K[X];
    Y %= 2520;
    Y += 2520;
    Y %= 2520;
    cout << ans[X * 2520 + Y] << "\n";
  }
}