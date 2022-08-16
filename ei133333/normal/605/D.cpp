#pragma GCC optimize ("O3")
#pragma GCC target ("avx")


#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

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
  // 
  int N;
  cin >> N;
  vector< int > A(N), B(N), C(N), D(N);
  vector< int > xs{0};
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    xs.emplace_back(A[i]);
    xs.emplace_back(C[i]);
  }
  A.emplace_back(0);
  B.emplace_back(0);
  C.emplace_back(0);
  D.emplace_back(0);
  ++N;

  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  for(int i = 0; i < N; i++) {
    A[i] = lower_bound(begin(xs), end(xs), A[i]) - begin(xs);
    C[i] = lower_bound(begin(xs), end(xs), C[i]) - begin(xs);
  }



  int n = (int) xs.size();
  int sz = 1;
  while(sz < n) sz <<= 1;
  vector< vector< int > > seg(2 * sz);
  auto add_point = [&](int k, int idx) {
    k += sz;
    seg[k].emplace_back(idx);
    while(k >>= 1) {
      seg[k].emplace_back(idx);
    }
  };
  vector< int > ord(N - 1);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int a, int b) {
    return B[a] > B[b];
  });
  for(int i : ord) {
    add_point(A[i], i);
  }

  vector< int > dp(N, -1), pre(N, -1);
  queue< int > que;
  que.emplace(N - 1);
  dp[N - 1] = 0;
  while(!que.empty()) {
    int idx = que.front();
    que.pop();
    auto add_que = [&](vector< int > &vs) {
      while(vs.size() && B[vs.back()] <= D[idx]) {
        if(dp[vs.back()] == -1) {
          dp[vs.back()] = dp[idx] + 1;
          pre[vs.back()] = idx;
          que.emplace(vs.back());
        }
        vs.pop_back();
      }
    };
    {
      int a = 0, b = C[idx] + 1;
      for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
        if(a & 1)add_que(seg[a++]);
        if(b & 1)add_que(seg[--b]);
      }
    }
  }
  cout << dp[N - 2] << "\n";
  if(dp[N - 2] == -1) return 0;
  int now = N - 2;
  vector< int > arr;
  while(now != N - 1) {
    arr.emplace_back(now + 1);
    now = pre[now];
  }
  reverse(begin(arr), end(arr));
  cout << arr << "\n";
}