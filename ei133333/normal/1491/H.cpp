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

struct Block {
  int l, r; // [l, r)
  int64 mx; // max value
  int64 lz; // lazy prop
};

int main() {
  int N, Q;
  cin >> N >> Q;
  vector< int64 > A(N);
  for(int i = 1; i < N; i++) {
    cin >> A[i];
    --A[i];
  }
  const int B = 333;
  const int M = (N - 1) / B + 1;
  vector< Block > bs;
  vector< int > f(N);

  auto reset = [&](Block &p) {
    if(p.lz != 0) {
      for(int i = p.l; i < p.r; i++) {
        A[i] -= p.lz;
        chmax(A[i], 0);
      }
      p.lz = 0;
    }
  };
  auto modify = [&](Block &p) {
    p.mx = -inf;
    assert(p.lz == 0);
    for(int j = p.l; j < p.r; j++) {
      chmax(p.mx, A[j] + (j - p.l));
    }
    for(int j = p.l; j < p.r; j++) {
      if(p.l <= A[j]) {
        f[j] = f[A[j]];
      } else {
        f[j] = j;
      }
    }
  };

  for(int i = 0; i < M; i++) {
    Block comp;
    comp.l = i * B;
    comp.r = min(N, (i + 1) * B);
    comp.lz = 0;
    modify(comp);
    bs.emplace_back(comp);
  }


  while(Q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      --l;
      for(auto &p : bs) {
        if(p.r <= l or r <= p.l) {
          continue;
        } else if(l <= p.l and p.r <= r) {
          p.lz += x;
          if(p.mx >= p.l) {
            reset(p);
            modify(p);
          } else {
            p.mx -= x;
          }
        } else {
          reset(p);
          int a = max(l, p.l);
          int b = min(r, p.r);
          for(int k = a; k < b; k++) {
            A[k] -= x;
            chmax(A[k], 0);
          }
          modify(p);
        }
      }
    } else {
      int64 u, v;
      cin >> u >> v;
      --u, --v;
      while(f[u] != f[v]) {
        if(u > v) swap(u, v);
        v = f[v];
        v = A[v] - bs[v / B].lz;
        chmax(v, 0);
      }
      auto &x = bs[u / B];
      auto &y = bs[v / B];
      reset(x), modify(x);
      assert(y.lz == 0);
      reset(y), modify(y);
      while(u != v) {
        if(u > v) swap(u, v);
        v = A[v];
      }
      cout << u + 1 << "\n";
    }
  }
}