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

void beet() {
  int N, M;
  cin >> N >> M;
  vector< int > A(N), B(M);
  cin >> A >> B;

  int ret = 0;

  auto solve = [](vector< int64 > a, vector< int64 > b) -> int {
    int n = (int) a.size();
    int m = (int) b.size();
    if(a.empty()) {
      return 0;
    }
    int ptr = 0;
    vector< int > suf(n + 1);
    for(int i = n - 1; i >= 0; i--) {
      suf[i] = suf[i + 1];
      suf[i] += binary_search(begin(b), end(b), a[i]);
    }
    int ret = 0;
    for(int p = 0; p < m; p++) {
      if(a[0] > b[p]) {
        continue;
      }
      int64 add = b[p] - a[0];
      while(ptr + 1 < n and a[0] + add + ptr >= a[ptr + 1]) {
        ++ptr;
      }
      // [b[p], b[p]+ptr] 
      int y = upper_bound(begin(b), end(b), b[p] + ptr) - begin(b);
      chmax(ret, suf[ptr + 1] + y - p);
    }
    return ret;
  };

  {
    vector< int64 > C, D;
    for(auto &p : A) {
      if(p < 0) C.emplace_back(-p);
    }
    for(auto &p : B) {
      if(p < 0) D.emplace_back(-p);
    }
    reverse(begin(C), end(C));
    reverse(begin(D), end(D));
    ret += solve(C, D);
  }

  {
    vector< int64 > C, D;
    for(auto &p : A) {
      if(p > 0) C.emplace_back(p);
    }
    for(auto &p : B) {
      if(p > 0) D.emplace_back(p);
    }
    ret += solve(C, D);
  }

  cout << ret << "\n";
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    beet();
  }
}