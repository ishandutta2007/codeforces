#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
// const int mod = 1e9 + 7;
const int mod = 998244353;

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
 * @brief Union-Find
 * @docs docs/union-find.md
 */
struct UnionFind {
  vector< int > data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) {
    return -data[find(k)];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  vector< vector< int > > groups() {
    int n = (int) data.size();
    vector< vector< int > > ret(n);
    for(int i = 0; i < n; i++) {
      ret[find(i)].emplace_back(i);
    }
    ret.erase(remove_if(begin(ret), end(ret), [&](const vector< int > &v) {
      return v.empty();
    }));
    return ret;
  }
};

void beet() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  vector< int > B(N, -1), C(N);
  int ret = 0;
  for(int i = 0; i < N; i++) {
    --A[i];
    if(C[A[i]]++) continue;
    ++ret;
    B[i] = A[i];
  }

  vector< int > nots, beet;
  for(int i = 0; i < N; i++) {
    if(B[i] != -1) {
      continue;
    }
    if(C[i] == 0) {
      B[i] = i;
      C[i] = 1;
      beet.emplace_back(i);
    }
  }
  for(int i = 0; i < N; i++) {
    if(C[i] == 0) {
      nots.emplace_back(i);
    }
  }
  for(int i = 0; i < N; i++) {
    if(B[i] == -1) {
      B[i] = nots.back();
      nots.pop_back();
    }
  }
  for(int i = 0; i < beet.size(); i++) {
    B[beet[i]] = beet[(i + 1) % beet.size()];
  }
  if(beet.size() == 1) {
    for(int k = 0; k < N; k++) {
      if(beet[0] == k) {
        continue;
      }
      if(A[beet[0]] == A[k]) {
        swap(B[k], B[beet[0]]);
        break;
      }
    }
  }
  cout << ret << "\n";
  for(auto &p : B) ++p;
  cout << B << endl;
}

int main() {
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    beet();
  }
}