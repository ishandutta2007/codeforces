#include<bits/stdc++.h>

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

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << " " << p.second;
  return os;
}

template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second;
  return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &in: v) is >> in;
  return is;
}

template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template<typename T = int64>
vector<T> make_v(size_t a) {
  return vector<T>(a);
}

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v) {
  t = v;
}

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v) {
  for (auto &e: t) fill_v(e, v);
}

template<typename F>
struct FixPoint : F {
  explicit FixPoint(F &&f) : F(forward<F>(f)) {}

  template<typename... Args>
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward<Args>(args)...);
  }
};

template<typename F>
inline decltype(auto) MFP(F &&f) {
  return FixPoint<F>{forward<F>(f)};
}

#line 2 "structure/union-find/union-find.hpp"

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

  vector< vector< int > > groups() {
    int n = (int) data.size();
    vector< vector< int > > ret(n);
    for(int i = 0; i < n; i++) {
      ret[find(i)].emplace_back(i);
    }
    ret.erase(remove_if(begin(ret), end(ret), [&](const vector< int > &v) {
      return v.empty();
    }), end(ret));
    return ret;
  }
};
#line 2 "other/offline-rmq.hpp"

/**
 * @brief Offline RMQ
 **/
template< typename Comp >
vector< int > offline_rmq(vector< pair< int, int > > &qs, const Comp &comp) {
  int n = 0;
  for(auto&[l, r]: qs) n = max(n, r);
  UnionFind uf(n);
  vector< int > st(n), mark(n), ans(qs.size());
  int top = -1;
  for(auto&[l, r]: qs) mark[r - 1]++;
  vector< vector< int > > q(n);
  for(int i = 0; i < n; i++) {
    q[i].reserve(mark[i]);
  }
  for(int i = 0; i < qs.size(); i++) {
    q[qs[i].second - 1].emplace_back(i);
  }
  for(int i = 0; i < n; i++) {
    while(~top and not comp(st[top], i)) {
      uf.unite(st[top--], i);
    }
    st[++top] = i;
    mark[uf.find(i)] = i;
    for(auto &j: q[i]) {
      ans[j] = mark[uf.find(qs[j].first)];
    }
  }
  return ans;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector< int > A(W);
  cin >> A;
  int Q;
  cin >> Q;
  vector< int > Y(Q);
  vector< pair< int, int > > X(Q);
  vector< int > ans(Q);
  for(int i = 0; i < Q; i++) {
    int y1, x1, y2, x2, k;
    cin >> y1 >> x1 >> y2 >> x2 >> k;
    --y1, --x1, --y2, --x2;
    if(x1 > x2) {
      swap(x1, x2);
      swap(y1, y2);
    }
    y1 = (H - y1 - 1) / k * k + y1;
    y2 = (H - y2 - 1) / k * k + y2;
    ans[i] = y1 == y2 and (x2 - x1) % k == 0;
    Y[i] = y1;
    X[i] = {x1, x2 + 1};
  }
  auto rmq = offline_rmq(X, [&](int a, int b) { return A[a] > A[b]; });
  for(int i = 0; i < Q; i++) {
    ans[i] &= A[rmq[i]] <= Y[i];
    if(ans[i]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}