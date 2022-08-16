#include<bits/stdc++.h>

using namespace std;
using int64 = long long;
//const int mod = 1e9 + 7;
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

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using modint = ModInt< mod >;


// 

// C[0]==0 
// (10)+(010)
// (10)+(010)+(11)
// (10)+(010)+(21)+(0)

// P[0]==0 
// (21)+(00)
// (1)+(10)+(010)
// (1)+(10)+(010)+(11)
// (1)+(10)+(010)+(21)+(0)

/**
 * @brief Binary-Indexed-Tree(BIT)
 * @docs docs/binary-indexed-tree.md
 */
template< typename T >
struct BinaryIndexedTree {
private:
  vector< T > data;

public:
  BinaryIndexedTree() = default;

  explicit BinaryIndexedTree(size_t sz) : data(sz + 1, 0) {}

  explicit BinaryIndexedTree(const vector< T > &vs) : data(vs.size() + 1, 0) {
    for(size_t i = 0; i < vs.size(); i++) data[i + 1] = vs[i];
    for(size_t i = 1; i < data.size(); i++) {
      size_t j = i + (i & -i);
      if(j < data.size()) data[j] += data[i];
    }
  }

  void add(int k, const T &x) {
    for(++k; k < (int) data.size(); k += k & -k) data[k] += x;
  }

  T sum(int r) const {
    T ret = T();
    for(; r > 0; r -= r & -r) ret += data[r];
    return ret;
  }

  T sum(int l, int r) const {
    return sum(r) - sum(l);
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

void beet() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;

  if(N == 1) {
    cout << 1 << "\n";
    return;
  }

  modint ret = 0;

  {
    // C[0]==0 
    // (10)+(010)
    {
      vector< int64 > rep(N + 1);
      for(int i = N - 2; i >= 0; i -= 2) {
        rep[i] = rep[i + 2] + A[i] - A[i + 1]; // 
      }
      int64 sum = 0;
      for(int i = 0; i < N; i++) {
        sum -= A[i];
        if((N - i) & 1 and sum + rep[i + 1] > 0) {
          ret += 1;
        }
      }
    }
    // (10)+(010)+(11)
    {
      vector< int64 > S(N);
      for(int i = N - 1; i >= 0; i--) {
        S[i] = A[i];
        if(i + 1 < N) S[i] += S[i + 1];
      }
      vector< int64 > V(N);
      for(int i = 0; i + 2 < N; i++) {
        V[i + 2] = V[i] + A[i] - A[i + 1];
      }
      int64 sum = 0;
      vector< int64 > xs;
      for(int r = 1; r < N; r++) xs.emplace_back(S[r] + V[r]);
      sort(begin(xs), end(xs));
      xs.erase(unique(begin(xs), end(xs)), end(xs));
      BinaryIndexedTree< modint > bit1(xs.size() + 2);
      BinaryIndexedTree< modint > bit2(xs.size() + 2);
      vector< int > type(N);
      for(int r = N - 1; r >= 1; r--) {
        if(r & 1) bit1.add(lower_bound(begin(xs), end(xs), S[r] + V[r]) - begin(xs), 1);
        else bit2.add(lower_bound(begin(xs), end(xs), S[r] + V[r]) - begin(xs), 1);
      }
      for(int l = 1; l < N; l++) {
        sum -= A[l - 1];

        if(l & 1) {
          ret += bit1.sum(upper_bound(begin(xs), end(xs), V[l] - sum) - begin(xs), xs.size());
          bit1.add(lower_bound(begin(xs), end(xs), S[l] + V[l]) - begin(xs), -1);
        } else {
          ret += bit2.sum(upper_bound(begin(xs), end(xs), V[l] - sum) - begin(xs), xs.size());
          bit2.add(lower_bound(begin(xs), end(xs), S[l] + V[l]) - begin(xs), -1);
        }
        /*
        for(int r = l; r < N; r += 2) {
          if(S[r] + V[r] > V[l] - sum) {
            ret += 1;
          }
        }
         */
      }
    }
    // (10)+(010)+(21)+(0)
    {
      vector< int64 > S(N);
      S[N - 1] = -A[N - 1];
      for(int i = N - 2; i >= 0; i--) {
        S[i] = A[i];
        if(i + 1 < N) S[i] += S[i + 1];
      }
      vector< int64 > V(N);
      for(int i = 0; i + 2 < N; i++) {
        V[i + 2] = V[i] + A[i] - A[i + 1];
      }
      int64 sum = 0;

      vector< int64 > xs;
      for(int r = 1; r < N; r++) xs.emplace_back(S[r] + V[r]);
      sort(begin(xs), end(xs));
      xs.erase(unique(begin(xs), end(xs)), end(xs));
      BinaryIndexedTree< modint > bit1(xs.size() + 2);
      BinaryIndexedTree< modint > bit2(xs.size() + 2);
      vector< int > type(N);
      for(int r = N - 3; r >= 1; r--) {
        if(r & 1) bit1.add(lower_bound(begin(xs), end(xs), S[r] + V[r]) - begin(xs), 1);
        else bit2.add(lower_bound(begin(xs), end(xs), S[r] + V[r]) - begin(xs), 1);
      }

      for(int l = 1; l + 2 < N; l++) {
        sum -= A[l - 1];

        if(l & 1) {
          ret += bit1.sum(upper_bound(begin(xs), end(xs), V[l] - sum) - begin(xs), xs.size());
          bit1.add(lower_bound(begin(xs), end(xs), S[l] + V[l]) - begin(xs), -1);
        } else {
          ret += bit2.sum(upper_bound(begin(xs), end(xs), V[l] - sum) - begin(xs), xs.size());
          bit2.add(lower_bound(begin(xs), end(xs), S[l] + V[l]) - begin(xs), -1);
        }
        /*
        for(int r = l; r + 2 < N; r += 2) {
          if(S[r] + V[r] > V[l]-sum) {
            ret += 1;
          }
        }
         */
      }
    }
  }

  {
    // P[0]==0 
    // (21)+(00)
    {
      vector< int64 > rep(N + 1);
      for(int i = N - 1; i >= 0; i--) {
        rep[i] = rep[i + 1] - A[i];
      }
      int64 sum = 0;
      for(int i = 0; i < N; i++) {
        sum += A[i];
        if(i >= 1 and sum + rep[i + 1] > 0) {
          ret += 1;
        }
      }
    }
    // (1)+(10)+(010)
    {
      vector< int64 > rep(N + 1), check(N + 1);
      check[N] = true;
      for(int i = N - 2; i >= 0; i -= 2) {
        rep[i] = rep[i + 2] + A[i] - A[i + 1];
        check[i] = true;
      }
      int64 sum = A[0];
      for(int i = 1; i < N; i++) {
        sum -= A[i];
        if(check[i + 1] and sum + rep[i + 1] > 0) {
          ret += 1;
        }
      }
    }
    // (1)+(10)+(010)+(11)
    {
      int64 sum = A[0];
      vector< int64 > S(N + 1);
      for(int i = N - 1; i >= 0; i--) {
        S[i] = S[i + 1] + A[i];
      }
      vector< int64 > V(N);
      for(int i = 0; i + 2 < N; i++) {
        V[i + 2] = V[i] + A[i] - A[i + 1];
      }

      vector< int64 > xs;
      for(int r = 1; r < N; r++) xs.emplace_back(S[r] + V[r]);
      sort(begin(xs), end(xs));
      xs.erase(unique(begin(xs), end(xs)), end(xs));
      BinaryIndexedTree< modint > bit1(xs.size() + 2);
      BinaryIndexedTree< modint > bit2(xs.size() + 2);
      vector< int > type(N);
      for(int r = N - 1; r >= 2; r--) {
        if(r & 1) bit1.add(lower_bound(begin(xs), end(xs), S[r] + V[r]) - begin(xs), 1);
        else bit2.add(lower_bound(begin(xs), end(xs), S[r] + V[r]) - begin(xs), 1);
      }

      for(int i = 2; i < N; i++) {
        sum -= A[i - 1];

        if(i & 1) {
          ret += bit1.sum(upper_bound(begin(xs), end(xs), V[i] - sum) - begin(xs), xs.size());
          bit1.add(lower_bound(begin(xs), end(xs), S[i] + V[i]) - begin(xs), -1);
        } else {
          ret += bit2.sum(upper_bound(begin(xs), end(xs), V[i] - sum) - begin(xs), xs.size());
          bit2.add(lower_bound(begin(xs), end(xs), S[i] + V[i]) - begin(xs), -1);
        }

        /*
        for(int j = i; j < N; j += 2) {
          if(S[j] + V[j] > V[i] - sum) {
            ret += 1;
          }
        }
         */
      }
    }
    // (1)+(10)+(010)+(21)+(0)
    {
      vector< int64 > S(N + 1);
      S[N - 1] = -A[N - 1];
      for(int i = N - 2; i >= 0; i--) {
        S[i] = S[i + 1] + A[i];
      }
      vector< int64 > V(N);
      for(int i = 0; i + 2 < N; i++) {
        V[i + 2] = V[i] + A[i] - A[i + 1];
      }
      int64 sum = A[0];


      vector< int64 > xs;
      for(int r = 1; r < N; r++) xs.emplace_back(S[r] + V[r]);
      sort(begin(xs), end(xs));
      xs.erase(unique(begin(xs), end(xs)), end(xs));
      BinaryIndexedTree< modint > bit1(xs.size() + 2);
      BinaryIndexedTree< modint > bit2(xs.size() + 2);
      vector< int > type(N);
      for(int r = N - 3; r >= 2; r--) {
        if(r & 1) bit1.add(lower_bound(begin(xs), end(xs), S[r] + V[r]) - begin(xs), 1);
        else bit2.add(lower_bound(begin(xs), end(xs), S[r] + V[r]) - begin(xs), 1);
      }

      for(int i = 2; i + 2 < N; i++) {
        sum -= A[i - 1];
        if(i & 1) {
          ret += bit1.sum(upper_bound(begin(xs), end(xs), V[i] - sum) - begin(xs), xs.size());
          bit1.add(lower_bound(begin(xs), end(xs), S[i] + V[i]) - begin(xs), -1);
        } else {
          ret += bit2.sum(upper_bound(begin(xs), end(xs), V[i] - sum) - begin(xs), xs.size());
          bit2.add(lower_bound(begin(xs), end(xs), S[i] + V[i]) - begin(xs), -1);
        }

        /*
        for(int j = i; j + 2 < N; j += 2) {
          if(S[j] + V[j] > V[i] - sum) {
            ret += 1;
          }
        }
         */
      }
    }
  }
  cout << ret << "\n";
}

int main() {

  int T;
  cin >> T;
  while(T--) beet();
}