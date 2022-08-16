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

/**
 * @brief Segment-Tree()
 * @docs docs/segment-tree.md
 */
template< typename Monoid, typename F >
struct SegmentTree {
  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

template< typename Monoid, typename F >
SegmentTree< Monoid, F > get_segment_tree(int N, const F &f, const Monoid &M1) {
  return {N, f, M1};
}


int main() {
  int N;
  cin >> N;
  vector< int > H(N);
  cin >> H;
  vector< int > G{H};
  for(auto &p : G) p *= -1;

  deque< pair< int, pair< int, int > > > latte;
  vector< int > dp(N, inf);
  dp[0] = 0;


  vector< int > xs{H};
  xs.emplace_back(-inf);
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  for(int i = 0; i < N; i++) {
    H[i] = lower_bound(begin(xs), end(xs), H[i]) - begin(xs);
  }
  auto f = [](int a, int b) { return min(a, b); };
  auto seg = get_segment_tree(xs.size() + 1, f, inf);

  vector< int > ys{G};
  ys.emplace_back(-inf);
  sort(begin(ys), end(ys));
  ys.erase(unique(begin(ys), end(ys)), end(ys));
  for(int i = 0; i < N; i++) {
    G[i] = lower_bound(begin(ys), end(ys), G[i]) - begin(ys);
  }

  vector< multiset< int > > ev(xs.size());

  auto rec = MFP([&](auto rec, int l, int r) -> void {
    if(l + 1 >= r) return;
    int m = (l + r) / 2;
    rec(l, m);

    chmin(dp[m], dp[m - 1] + 1);
    // max(h[i+1]..h[j-1]) < min(h[i],h[j])
    {
      int mx = 0;
      for(int j = m - 1; j >= l; j--) {
        if(mx < H[j]) latte.emplace_back(H[j], make_pair(mx, dp[j]));
        chmax(mx, H[j]);
      }
      for(auto &p : latte) {
        if(ev[p.second.first].empty() || *ev[p.second.first].rbegin() < p.second.second) {
          seg.update(p.second.first, p.second.second);
        }
        ev[p.second.first].emplace(p.second.second);
      }
      sort(begin(latte), end(latte));
      mx = 0;
      for(int j = m; j < r; j++) {
        if(mx < H[j]) {
          while(!latte.empty() && latte.front().first <= mx) {
            auto &p = latte.front();
            ev[p.second.first].erase(ev[p.second.first].find(p.second.second));
            if(ev[p.second.first].empty()) seg.update(p.second.first, inf);
            else seg.update(p.second.first, *ev[p.second.first].rbegin());
            latte.pop_front();
          }
          chmin(dp[j], seg.query(0, H[j]) + 1);
        }
        chmax(mx, H[j]);
      }
      while(!latte.empty()) {
        auto &p = latte.front();
        ev[p.second.first].erase(ev[p.second.first].find(p.second.second));
        if(ev[p.second.first].empty()) seg.update(p.second.first, inf);
        else seg.update(p.second.first, *ev[p.second.first].rbegin());
        latte.pop_front();
      }
    }



    H.swap(G);
    {
      int mx = 0;
      for(int j = m - 1; j >= l; j--) {
        if(mx < H[j]) latte.emplace_back(H[j], make_pair(mx, dp[j]));
        chmax(mx, H[j]);
      }
      for(auto &p : latte) {
        if(ev[p.second.first].empty() || *ev[p.second.first].rbegin() < p.second.second) {
          seg.update(p.second.first, p.second.second);
        }
        ev[p.second.first].emplace(p.second.second);
      }
      sort(begin(latte), end(latte));
      mx = 0;
      for(int j = m; j < r; j++) {
        if(mx < H[j]) {
          while(!latte.empty() && latte.front().first <= mx) {
            auto &p = latte.front();
            ev[p.second.first].erase(ev[p.second.first].find(p.second.second));
            if(ev[p.second.first].empty()) seg.update(p.second.first, inf);
            else seg.update(p.second.first, *ev[p.second.first].rbegin());
            latte.pop_front();
          }
          chmin(dp[j], seg.query(0, H[j]) + 1);
        }
        chmax(mx, H[j]);
      }
      while(!latte.empty()) {
        auto &p = latte.front();
        ev[p.second.first].erase(ev[p.second.first].find(p.second.second));
        if(ev[p.second.first].empty()) seg.update(p.second.first, inf);
        else seg.update(p.second.first, *ev[p.second.first].rbegin());
        latte.pop_front();
      }
    }

    rec(m, r);
  });
  rec(0, N);
  cout << dp.back() << "\n";
}