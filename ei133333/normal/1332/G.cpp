#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 60) - 1;
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

  void update2(int k, const Monoid &x) {
    k += sz;
    seg[k] = f(seg[k], x);
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


int main() {


  int N, Q;
  cin >> N >> Q;
  vector< int > A(N);
  cin >> A;

  //cin >> A;
  auto xs{A};
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  for(auto &p : A) p = lower_bound(begin(xs), end(xs), p) - begin(xs);

  vector< int > latte(N), malta(N);

  auto f = [](int a, int b) { return min(a, b); };
  SegmentTree< int, decltype(f) > seg(xs.size() + 1, f, inf);
  auto g = [](int a, int b) { return max(a, b); };
  SegmentTree< int, decltype(g) > seg2(xs.size() + 1, g, -inf);

  vector< vector< vector< int > > > range(N), range2(N);

  vector< pair< int, int > > vs, ys;

  MFP([&](auto rec, int left, int right) -> void {
        if(right - left <= 3) return;
        int mid = (left + right) / 2;
        rec(left, mid);
        rec(mid, right);

        // min,max[left,mid)
        {
          int large = -inf, small = inf;
          int large_pos = -1, small_pos = -1;
          for(int k = mid - 1; k >= left; k--) {
            if(chmax(large, A[k])) large_pos = k;
            if(chmin(small, A[k])) small_pos = k;
            latte[k] = small_pos;
            malta[k] = large_pos;
          }
          for(int k = right - 1; k >= mid; k--) seg.update(A[k], k);
          for(int k = left; k < mid; k++) {
            if(latte[k] == -1) continue;
            int first = A[k];
            int second = A[latte[k]];
            int third = A[malta[k]];
            if(first == second || first == third || second == third) continue;
            if(second > third) swap(second, third);
            ++second;
            if(second >= third) continue;
            int po = seg.query(second, third);
            if(po != inf) {
              if(range[k].empty() || po < range[k].back().back()) range[k].emplace_back(vector< int >{k, latte[k], malta[k], po});
            }
          }
          for(int k = right - 1; k >= mid; k--) seg.update(A[k], inf);
        }


        // min,max[mid,right)
        {
          int large = -inf, small = inf;
          int large_pos = -1, small_pos = -1;
          for(int k = mid; k < right; k++) {
            if(chmax(large, A[k])) large_pos = k;
            if(chmin(small, A[k])) small_pos = k;
            latte[k] = small_pos;
            malta[k] = large_pos;
          }
          for(int k = left; k < mid; k++) seg2.update(A[k], k);
          for(int k = mid; k < right; k++) {
            if(latte[k] == -1) continue;
            int first = A[k];
            int second = A[latte[k]];
            int third = A[malta[k]];
            if(first == second || first == third || second == third) continue;
            if(second > third) swap(second, third);
            ++second;
            if(second >= third) continue;
            int po = seg2.query(second, third);
            if(po != -inf) {
              if(range[po].empty() || k < range[po].back().back()) range[po].emplace_back(vector< int >{po, latte[k], malta[k], k});
            }
          }
          for(int k = left; k < mid; k++) seg2.update(A[k], -inf);
        }

        // min[left,mid) max[mid,right)
        {
          for(int k = left; k < mid; k++) {
            if(latte[k] == -1) continue;
            int first = A[k];
            int second = A[latte[k]];
            if(first == second) continue;
            vs.emplace_back(k, latte[k]);
          }
          for(int k = right - 1; k >= mid; k--) {
            if(malta[k] == -1) continue;
            int third = A[malta[k]];
            int forth = A[k];
            if(third == forth) continue;
            ys.emplace_back(malta[k], k);
          }
          sort(begin(vs), end(vs), [&](auto p, auto q) {
            return A[p.first] > A[q.first];
          });
          int ptr = 0;
          for(auto &p : vs) {
            int first = A[p.first];
            int second = A[p.second];
            while(ptr < ys.size() && first < A[ys[ptr].first]) {
              seg.update2(A[ys[ptr].second], ys[ptr].second);
              ++ptr;
            }
            int po = seg.query(second + 1, xs.size() + 1);
            if(po != inf) {
              if(range[p.first].empty() || po < range[p.first].back().back()) range[p.first].emplace_back(vector< int >{p.first, p.second, malta[po], po});
            }
          }
          for(auto &p : ys) seg.update(A[p.second], inf);
          vs.clear();
          ys.clear();
        }

        // max[left,mid) min[mid,right)
        {
          for(int k = left; k < mid; k++) {
            if(latte[k] == -1) continue;
            int first = A[k];
            int second = A[malta[k]];
            if(first == second) continue;
            vs.emplace_back(k, malta[k]);
          }
          for(int k = right - 1; k >= mid; k--) {
            if(latte[k] == -1) continue;
            int third = A[latte[k]];
            int forth = A[k];
            if(third == forth) continue;
            ys.emplace_back(latte[k], k);
          }
          sort(begin(vs), end(vs), [&](auto p, auto q) {
            return A[p.first] < A[q.first];
          });
          int ptr = 0;
          for(auto &p : vs) {
            int first = A[p.first];
            int second = A[p.second];
            while(ptr < ys.size() && first > A[ys[ptr].first]) {
              seg.update2(A[ys[ptr].second], ys[ptr].second);
              ++ptr;
            }
            int po = seg.query(0, second);
            if(po != inf) {
              if(range[p.first].empty() || po < range[p.first].back().back()) range[p.first].emplace_back(vector< int >{p.first, p.second, latte[po], po});
            }
          }
          for(auto &p : ys) seg.update(A[p.second], inf);
          vs.clear();
          ys.clear();
        }
      }
  )(0, N);

  vector< int > near_small(N, -1), near_large(N, -1);
  for(int i = 0; i < N; i++) {
    seg2.update(A[i], i);
    int po = seg2.query(0, A[i]);
    if(po != -inf) near_small[i] = po;
    po = seg2.query(A[i] + 1, xs.size() + 1);
    if(po != -inf) near_large[i] = po;
  }
  for(int i = N - 1; i >= 0; i--) {
    seg.update(A[i], i);
    int po = seg.query(0, A[i]);
    if(po != inf && near_small[i] != -1) {
      range2[near_small[i]].emplace_back(vector< int >{near_small[i], i, po});
    }
    po = seg.query(A[i] + 1, xs.size() + 1);
    if(po != inf && near_large[i] != -1) {
      range2[near_large[i]].emplace_back(vector< int >{near_large[i], i, po});
    }
  }


  vector< vector< int > > ans(Q);
  vector< vector< pair< int, int > > > ev(N);
  for(int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    ev[l].emplace_back(r, i);
  }
  vector< int > now1, now2;
  for(int i = N - 1; i >= 0; i--) {
    for(auto &p : range[i]) {
      sort(begin(p), end(p));
      if(now1.empty() || now1.back() > p.back()) {
        now1 = p;
      }
    }
    for(auto &p : range2[i]) {
      sort(begin(p), end(p));
      if(now2.empty() || now2.back() > p.back()) {
        now2 = p;
      }
    }
    for(auto &p : ev[i]) {
      if(!now1.empty() && p.first >= now1.back()) {
        ans[p.second] = now1;
      } else if(!now2.empty() && p.first >= now2.back()) {
        ans[p.second] = now2;
      }
    }
  }

  for(auto &p : ans) {
    sort(begin(p), end(p));
    cout << p.size() << "\n";
    for(auto &t : p) ++t;
    cout << p << "\n";
  }
}