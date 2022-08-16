#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = (int) (1e9 + 7);

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

template< typename Monoid, typename OperatorMonoid, typename F, typename G, typename H >
struct LazySegmentTree {

  int sz;
  vector< Monoid > data;
  vector< OperatorMonoid > lazy;
  const F f;
  const G g;
  const H h;
  const Monoid M1;
  const OperatorMonoid OM0;


  LazySegmentTree(int n, const F f, const G g, const H h,
                  const Monoid &M1, const OperatorMonoid OM0)
      : f(f), g(g), h(h), M1(M1), OM0(OM0) {
    sz = 1;
    while(sz < n) sz <<= 1;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x) {
    data[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  void propagate(int k, int len) {
    if(lazy[k] != OM0) {
      if(k < sz) {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], lazy[k], len);
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return data[k];
    } else if(a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      propagate(k, r - l);
      return data[k];
    } else {
      return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                         update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x) {
    return update(a, b, x, 1, 0, sz);
  }


  Monoid query(int a, int b, int k, int l, int r) {
    propagate(k, r - l);
    if(r <= a || b <= l) {
      return M1;
    } else if(a <= l && r <= b) {
      return data[k];
    } else {
      return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
               query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid query(int a, int b) {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k) {
    return query(k, k + 1);
  }
};


int main() {
  int N, M, K, Q;
  cin >> N >> M >> K >> Q;
  vector< int > e[202020];
  e[1].emplace_back(1);
  for(int i = 0; i < K; i++) {
    int r, c;
    cin >> r >> c;
    e[r].emplace_back(c);
  }
  vector< int > B(Q);
  cin >> B;
  sort(begin(B), end(B));


  int last = 0;
  for(int i = 1; i < 202020; i++) {
    if(e[i].size()) last = i;
  }

  int64 ret = 0;

  using pi = pair< int64, int64 >;

  auto f = [](int64 a, int64 b) {
    return min(a, b);
  };
  auto g = [](int64 a, const pi& b, int k) {
    if(b.second == 1) return b.first;
    return min(a, b.first);
  };
  auto h = [](const pi& a, const pi& b) {
    if(a.second == 0 || b.second == 1) return b;
    return pi(min(a.first, b.first), a.second);
  };
  LazySegmentTree< int64, pi, decltype(f), decltype(g), decltype(h) > seg1(B.size(), f, g, h, infll, pi());
  LazySegmentTree< int64, pi, decltype(f), decltype(g), decltype(h) > seg2(B.size(), f, g, h, infll, pi());

  auto f2 = [](const pi& a, const pi& b) {
    return pi(min(a.first, b.first), min(a.second, b.second));
  };
  auto g2 = [](const pi& a, const pi& b, int k) {
    if(b.second == 1) return pi(b.first + a.second, a.second);
    return pi(min(a.first, b.first + a.second), a.second);
  };
  auto rad = pi(infll, infll / 10);


  LazySegmentTree< pi, pi, decltype(f2), decltype(g2), decltype(h) > seg3(B.size(), f2, g2, h, rad, pi());
  LazySegmentTree< pi, pi, decltype(f2), decltype(g2), decltype(h) > seg4(B.size(), f2, g2, h, rad, pi());


  for(int i = 0; i < B.size(); i++) {
    seg3.set(i, pi(infll, -B[i] * 2));
    seg4.set(i, pi(infll, B[i] * 2));
  }
  seg3.build();
  seg4.build();

  for(int i = 1; i <= last; i++) {

    if(e[i].size()) {

      sort(begin(e[i]), end(e[i]));
      e[i].erase(unique(begin(e[i]), end(e[i])), end(e[i]));

      vector< int64 > dp2(e[i].size(), infll);
      if(i == 1) {
        dp2[0] = 0;
      } else {
        for(int k = 0; k < e[i].size(); k++) {
          int cur = lower_bound(begin(B), end(B), e[i][k]) - begin(B);
          chmin(dp2[k], seg1.query(0, cur) + e[i][k]);
          chmin(dp2[k], seg2.query(cur, B.size()) - e[i][k]);
          chmin(dp2[k], seg3.query(0, cur).first + e[i][k]);
          chmin(dp2[k], seg4.query(cur, B.size()).first - e[i][k]);
        }
      }


      vector< int64 > dp3(e[i].size(), infll);
      {
        int64 res = infll;
        for(int k = 0; k < e[i].size(); k++) {
          int64 nxt = infll;
          if(k) chmin(nxt, res + e[i][k] - e[i][k - 1]);
          chmin(nxt, (e[i][k] - e[i].front()) * 2 + dp2[k]);
          chmin(dp3[k], nxt + (e[i].back() - e[i][k]) * 2);
          res = nxt;
        }
      }

      {
        int64 res = infll;
        for(int k = (int) e[i].size() - 1; k >= 0; k--) {
          int64 nxt = infll;
          if(k + 1 < e[i].size()) chmin(nxt, res + e[i][k + 1] - e[i][k]);
          chmin(nxt, (e[i].back() - e[i][k]) * 2 + dp2[k]);
          chmin(dp3[k], nxt + (e[i][k] - e[i].front()) * 2);
          res = nxt;
        }
      }


      if(i == last) {
        ret = *min_element(begin(dp3), end(dp3));
      } else {
        seg1.update(0, B.size(), pi(infll, 1));
        seg2.update(0, B.size(), pi(infll, 1));
        seg3.update(0, B.size(), pi(infll, 1));
        seg4.update(0, B.size(), pi(infll, 1));
        for(int j = 0; j < e[i].size(); j++) {
          int cur = lower_bound(begin(B), end(B), e[i][j]) - begin(B);
          seg2.update(0, cur, pi(dp3[j] + e[i][j], 2));
          seg1.update(cur, B.size(), pi(dp3[j] - e[i][j], 2));
          seg3.update(0, cur, pi(dp3[j] + e[i][j], 2));
          seg4.update(cur, B.size(), pi(dp3[j] - e[i][j], 2));
        }
      }
    }
  }
  cout << ret + last - 1 << endl;
}