#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

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

template< typename structure_t, typename get_t, typename update_t, typename merge_f, typename range_get_f, typename update_f >
struct SegmentTree2DCompressed {


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

  void update(int a, int x, update_t z, int k, int l, int r) {
    if(r <= a || a + 1 <= l) return;
    if(a <= l && r <= a + 1) return h(seg[k], x, z);
    update(a, LL[k][x], z, 2 * k + 0, l, (l + r) >> 1);
    update(a, RR[k][x], z, 2 * k + 1, (l + r) >> 1, r);
    return h(seg[k], x, z);
  }

  void update(int x, int y, update_t z) {
    y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
    return update(x, y, z, 1, 0, sz);
  }

  get_t query(int a, int b, int y, int k, int l, int r) {
    if(a >= r || b <= l) return identity;
    if(a <= l && r <= b) return g(seg[k], y);
    return f(query(a, b, LL[k][y], 2 * k + 0, l, (l + r) >> 1),
             query(a, b, RR[k][y], 2 * k + 1, (l + r) >> 1, r));
  }

  get_t query(int a, int b, int y) {
    y = lower_bound(begin(beet[1]), end(beet[1]), y) - begin(beet[1]);
    return query(a, b, y, 1, 0, sz);
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

int main() {
  int N, M;
  cin >> N >> M;
  vector< int > P(N), S(N), B(N), za(N), inc(M), pref(M);
  cin >> P >> S >> B >> inc >> pref;

  map< int, vector< pair< int, int > > > ev;
  for(int i = 0; i < N; i++) ev[-S[i]].emplace_back(i, -1);
  for(int i = 0; i < M; i++) ev[-inc[i]].emplace_back(i, 1);


  vector< int > xs(B);
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));

  using BIT = BinaryIndexedTree< int >;
  auto f = [](int x, int y) { return x + y; };
  auto g = [](BIT &k, int y) { return k.sum(y - 1); };
  auto h = [](BIT &k, int x, int y) { k.add(x, y); };
  SegmentTree2DCompressed< BIT, int, int, decltype(f), decltype(g), decltype(h) > seg1(xs.size(), f, g, h, 0);
  SegmentTree2DCompressed< BIT, int, int, decltype(f), decltype(g), decltype(h) > seg2(xs.size(), f, g, h, 0);

  for(int i = 0; i < N; i++) {
    za[i] = lower_bound(begin(xs), end(xs), B[i]) - begin(xs);
    seg1.preupdate(za[i], B[i] + P[i]);
    seg2.preupdate(za[i], P[i] - B[i]);
  }
  seg1.build();
  seg2.build();

  // inc[i]S[j]
  vector< int > ans(M);
  for(auto _ : ev) {
    for(auto &p : _.second) {
      if(p.second == -1) {
        int i = p.first;
        seg1.update(za[i], B[i] + P[i], 1);
        seg2.update(za[i], P[i] - B[i], 1);
      } else {
        int i = p.first;

        // 
        // inc[i]-pref[i]

        // pref[i]B[j]
        // B[j]-pref[i]+P[j]inc[i]
        // B[j]+P[j]        inc[i]+pref[i]

        // pref[i]>B[j]
        // pref[i]-B[j]+P[j]inc[i]
        // P[j]-B[j]        inc[i]-pref[i]


        int add = 0;
        /*
        for(auto &j : idx) {
          if(abs(pref[i] - B[j]) + P[j] <= inc[i]) {
            ++add;
          }
        }
*/
        int po = lower_bound(begin(xs), end(xs), pref[i]) - begin(xs);
        ans[i] += seg1.query(po, xs.size(), inc[i] + pref[i] + 1);
        ans[i] += seg2.query(0, po, inc[i] - pref[i] + 1);
        //ans[i] = add;

      }
    }


  }

  cout << ans << endl;

}