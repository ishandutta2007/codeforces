#include <bits/stdc++.h>

using namespace std;


template< class T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

template< typename structure_t, typename get_t, typename update_t >
struct SegmentTree2DCompressed {

  using merge_f = function< get_t(get_t, get_t) >;
  using range_get_f = function< get_t(structure_t &, int, int) >;
  using update_f = function< void(structure_t &, int, update_t) >;

  int sz;
  vector< structure_t > seg;
  const merge_f f;
  const range_get_f g;
  const update_f h;
  const get_t identity;
  vector< vector< int > > LL, RR;
  vector< vector< int > > beet;

  SegmentTree2DCompressed(int n, const merge_f &f, const range_get_f &g, const update_f &h, const get_t &identity)
      : f(f), g(g), h(h), identity(identity) {
    sz = 1;
    while(sz < n) sz <<= 1;
    beet.resize(2 * sz);
    LL.resize(2 * sz);
    RR.resize(2 * sz);
  }

  
  void update(int x, int y, update_t z) {
    x += sz;
    h(seg[x], lower_bound(begin(beet[x]), end(beet[x]), y) - begin(beet[x]), z);
    while(x >>= 1) {
      h(seg[x], lower_bound(begin(beet[x]), end(beet[x]), y) - begin(beet[x]), z);
    }
  }

  get_t query(int a, int b, int x, int y, int k, int l, int r) {
    if(a >= r || b <= l) return identity;
    if(a <= l && r <= b) return g(seg[k], x, y);
    return f(query(a, b, LL[k][x], LL[k][y], 2 * k + 0, l, (l + r) >> 1),
             query(a, b, RR[k][x], RR[k][y], 2 * k + 1, (l + r) >> 1, r));
  }

  get_t query(int a, int b, int x, int y) {
    x = lower_bound(begin(beet[1]), end(beet[1]), x) - begin(beet[1]);
    y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
    return query(a, b, x, y, 1, 0, sz);
  }

  void build() {
    for(int k = (int) beet.size() - 1; k >= sz; k--) {
      sort(begin(beet[k]), end(beet[k]));
      beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
    }
    for(int k = sz - 1; k > 0; k--) {
      beet[k].resize(beet[2 * k + 0].size() + beet[2 * k + 1].size());
      merge(begin(beet[2 * k + 0]), end(beet[2 * k + 0]), begin(beet[2 * k + 1]), end(beet[2 * k + 1]), begin(beet[k]));
      beet[k].erase(unique(begin(beet[k]), end(beet[k])), end(beet[k]));
      LL[k].resize(beet[k].size() + 1);
      RR[k].resize(beet[k].size() + 1);
      int tail1 = 0, tail2 = 0;
      for(int i = 0; i < beet[k].size(); i++) {
        while(tail1 < beet[2 * k + 0].size() && beet[2 * k + 0][tail1] < beet[k][i]) ++tail1;
        while(tail2 < beet[2 * k + 1].size() && beet[2 * k + 1][tail2] < beet[k][i]) ++tail2;
        LL[k][i] = tail1, RR[k][i] = tail2;
      }
      LL[k][beet[k].size()] = (int) beet[2 * k + 0].size();
      RR[k][beet[k].size()] = (int) beet[2 * k + 1].size();
    }
    for(int k = 0; k < beet.size(); k++) {
      seg.emplace_back(structure_t(beet[k].size()));
    }
  }

  void preupdate(int x, int y) {
    beet[x + sz].push_back(y);
  }
};


const int INF = 1 << 30;

int main() {
  int S[3], N, M, K;
  int X[100000][3];
  int A[100000][3];
  int x[100000][3];
  scanf("%d %d %d %d %d %d", &S[0], &S[1], &S[2], &N, &M, &K);
  for(int i = 0; i < N; i++) scanf("%d %d %d", &X[i][0], &X[i][1], &X[i][2]);
  for(int i = 0; i < M; i++) scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);

  vector< pair< int, int > > mx(3);
  for(int i = 0; i < 3; i++) mx[i] = {S[i], 1};
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 3; j++) mx[j].first = min(mx[j].first, X[i][j]);
    for(int j = 0; j < 3; j++) mx[j].second = max(mx[j].second, X[i][j]);
  }
  for(int i = 0; i < M; i++) {
    bool f = true;
    for(int j = 0; j < 3; j++) {
      f &= mx[j].first <= A[i][j] && A[i][j] <= mx[j].second;
    }
    if(f) {
      cout << "INCORRECT\n";
      return 0;
    }
  }


  vector< pair< pair< pair< int, int >, pair< int, int > >, int > > add[100002];
  vector< pair< pair< pair< int, int >, pair< int, int > >, int > > del[100002];

  for(int i = 0; i < K; i++) {
    scanf("%d %d %d", &x[i][0], &x[i][1], &x[i][2]);
    vector< pair< int, int > > mz(mx);
    for(int j = 0; j < 3; j++) mz[j].first = min(mz[j].first, x[i][j]);
    for(int j = 0; j < 3; j++) mz[j].second = max(mz[j].second, x[i][j]);
    add[mz[0].first].emplace_back(make_pair(mz[1], mz[2]), i);
    del[mz[0].second + 1].emplace_back(make_pair(mz[1], mz[2]), i);
  }

  using BIT = BinaryIndexedTree< int >;
  auto f = [](int x, int y) { return x + y; };
  auto g = [](BIT &k, int x, int y) { return k.sum(y - 1) - k.sum(x - 1); };
  auto h = [](BIT &k, int x, int y) { k.add(x, y); };

  SegmentTree2DCompressed< BIT, int, int > seg(100002, f, g, h, 0);

  vector< pair< int, int > > point[100002];
  for(int i = 0; i < M; i++) {
    seg.preupdate(A[i][1], A[i][2]);
    point[A[i][0]].emplace_back(A[i][1], A[i][2]);
  }

  seg.build();
  vector< int > sum(K);
  for(int i = 0; i < 100002; i++) {
    for(auto &p : del[i]) sum[p.second] -= seg.query(p.first.first.first, p.first.first.second + 1, p.first.second.first, p.first.second.second + 1);
    for(auto &p : add[i]) sum[p.second] += seg.query(p.first.first.first, p.first.first.second + 1, p.first.second.first, p.first.second.second + 1);
    for(auto &p : point[i]) seg.update(p.first, p.second, 1);
  }

  puts("CORRECT");
  for(int i = 0; i < K; i++) {
    if(sum[i] != 0) {
      puts("CLOSED\n");
    } else {
      bool f = true;
      for(int j = 0; j < 3; j++) {
        f &= mx[j].first <= x[i][j] && x[i][j] <= mx[j].second;
      }
      if(f) puts("OPEN");
      else puts("UNKNOWN");
    }
  }
}