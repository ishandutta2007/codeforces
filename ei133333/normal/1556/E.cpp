#include <bits/stdc++.h>

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
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
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
 * @brief Sparse-Table()
 * @docs docs/sparse-table.md
 */
template< typename T, typename F >
struct SparseTable {
  F f;
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable() = default;

  explicit SparseTable(const vector< T > &v, const F &f) : f(f) {
    const int n = (int) v.size();
    const int b = 32 - __builtin_clz(n);
    st.assign(b, vector< T >(n));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= n; j++) {
        st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T fold(int l, int r) const {
    int b = lookup[r - l];
    return f(st[b][l], st[b][r - (1 << b)]);
  }
};

template< typename T, typename F >
SparseTable< T, F > get_sparse_table(const vector< T > &v, const F &f) {
  return SparseTable< T, F >(v, f);
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector< int64 > A(N), B(N);
  cin >> A >> B;
  for(int i = 0; i < N; i++) {
    B[i] -= A[i];
  }

  vector< int64 > X(N), Y(N);
  for(int i = 0; i < N; i++) {
    if(B[i] < 0) X[i] = -B[i];
    else Y[i] = B[i];
  }


  vector< int64 > X_sum(N + 1), Y_sum(N + 1);
  vector< int64 > S(N + 1);
  for(int i = 0; i < N; i++) {
    S[i + 1] = S[i] + B[i];
    X_sum[i + 1] = X_sum[i] + Y[i] - X[i];
    Y_sum[i + 1] = Y_sum[i] + X[i] - Y[i];
  }

  vector< int64 > latte(N + 1), malta(N + 1);
  for(int i = 0; i < N; i++) {
    latte[i] = X[i] - X_sum[i];
    malta[i] = Y[i] - Y_sum[i];
  }
  auto f = [](int64 a, int64 b) { return max(a, b); };
  auto latte_t = get_sparse_table(latte, f);
  auto malta_t = get_sparse_table(malta, f);

  while(Q--) {
    int L, R;
    cin >> L >> R;
    --L;
    if(B[L] < 0 or S[R] - S[L] != 0) {
      cout << "-1\n";
      continue;
    }
    auto check = [&](int64 p) {
      int64 nx_plus = 0, nx_minus = p;

      if(latte_t.fold(L, R) > -X_sum[L]) return false;
      /*
      for(int l = L; l < R; l++) {
        if(X[l] - X_sum[l] > -X_sum[L]) return false;
      }
       */
      if(malta_t.fold(L, R) > -Y_sum[L] + p) return false;
      /*
      for(int l = L; l < R; l++) {
        if(Y[l] - Y_sum[l] > -Y_sum[L] + p) return false;
      }
       */
      return true;
    };
    int64 ok = infll, ng = -1;
    while(ok - ng > 1) {
      int64 mid = (ok + ng) / 2;
      if(check(mid)) ok = mid;
      else ng = mid;
    }
    cout << ok << "\n";
  }
}