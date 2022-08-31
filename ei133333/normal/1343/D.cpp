#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

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

/**
 * @brief Binary-Indexed-Tree(BIT)
 * @docs docs/binary-indexed-tree.md
 */
template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree() = default;

  explicit BinaryIndexedTree(size_t sz) : data(sz + 1, 0) {}

  void add(int k, const T &x) {
    for(++k; k < (int) data.size(); k += k & -k) data[k] += x;
  }

  T query(int k) const {
    T ret = T();
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return ret;
  }

  int lower_bound(T x) const {
    int i = 0;
    for(int k = 1 << (__lg(data.size() - 1) + 1); k > 0; k >>= 1) {
      if(i + k < data.size() && data[i + k] < x) {
        x -= data[i + k];
        i += k;
      }
    }
    return i;
  }

  int upper_bound(T x) const {
    int i = 0;
    for(int k = 1 << (__lg(data.size() - 1) + 1); k > 0; k >>= 1) {
      if(i + k < data.size() && data[i + k] <= x) {
        x -= data[i + k];
        i += k;
      }
    }
    return i;
  }
};

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, K;
    cin >> N >> K;
    vector< int > A(N);
    cin >> A;
    for(int i = 0; i < N / 2; i++) {
      if(A[i] > A[N - 1 - i]) swap(A[i], A[N - 1 - i]);
    }
    vector< int > sum(2 * K + 1);
    for(int i = 0; i < N / 2; i++) {
      sum[A[i] + A[N - i - 1]]++;
    }
    vector< pair< int, int > > tap;
    for(int i = 0; i < N / 2; i++) {
      tap.emplace_back(A[i], A[N - i - 1]);
    }
    sort(begin(tap), end(tap));

    int ret = inf;
    int ptr = 0;

    BinaryIndexedTree< int > bit(2 * K + 1);
    for(int k = 2; k <= 2 * K; k++) {
      while(ptr < tap.size() && tap[ptr].first < k) {
        bit.add(tap[ptr].second + K, 1);
        ++ptr;
      }
      int UU = bit.query(2 * K) - bit.query(k-1);
      chmin(ret, N - UU - sum[k]);
    }
    cout << ret << endl;
  }
}