#include <bits/stdc++.h>

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
    string S;
    cin >> S;
    int M;
    cin >> M;
    vector< int > B(M);
    cin >> B;

    vector< int > cnt(26);
    for(auto &p : S) cnt[p - 'a']++;


    vector< char > used(M, -1);
    int sum = 0;
    for(int i = 0; i < M; i++) {
      if(B[i] == 0) ++sum;
    }
    int now = 0;
    for(int i = 25; i >= 0; i--) {
      if(cnt[i] >= sum) {
        for(int j = 0; j < M; j++) {
          if(B[j] == 0) used[j] = i;
        }
        now = i - 1;
        break;
      }
    }
    bool update = true;
    while(update) {
      update = false;
      vector< int > d(M);
      for(int i = 0; i < M; i++) {
        if(used[i] >= 0) {
          for(int j = 0; j < M; j++) d[j] += abs(i - j);
        }
      }
      sum = 0;
      for(int i = 0; i < M; i++) {
        if(used[i] == -1 && B[i] == d[i]) ++sum;
      }
      for(int i = now; i >= 0; i--) {
        if(cnt[i] >= sum) {
          for(int j = 0; j < M; j++) {
            if(used[j] == -1 && B[j] == d[j]) used[j] = i;
          }
          now = i - 1;
          update = true;
          break;
        }
      }
    }
    for(auto &p : used) cout << (char) (p + 'a');
    cout << "\n";
  }
}