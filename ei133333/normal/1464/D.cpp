#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

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
};


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

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;
    vector< int > P(N);
    cin >> P;
    for(auto &p : P) --p;

    UnionFind uf(N);
    for(int i = 0; i < N; i++) {
      uf.unite(i, P[i]);
    }
    vector< int > sz;
    for(int i = 0; i < N; i++) {
      if(uf.find(i) == i) {
        sz.emplace_back(uf.size(i));
      }
    }

    int two;
    if(N % 3 == 0) {
      two = 0;
    } else if(N % 3 == 1) {
      two = 2;
    } else {
      two = 1;
    }
    int three = (N - two * 2) / 3;

    cout << modint(3).pow(three) * modint(2).pow(two) << " ";


    int cost = 0;

    vector< int > S(5);
    for(auto &p : sz) {
      while(p > 4) {
        p -= 3;
        ++cost;
      }
      S[p]++;
    }


    auto get_cost = [&]() {
      auto T{S};
      if(two == 1) {
        if(T[2] >= 1) {
          T[2]--;
        } else {
          return inf;
        }
      } else if(two == 2) {
        if(T[4] >= 1) {
          T[4]--;
        } else if(T[2] >= 2) {
          T[2] -= 2;
        } else {
          return inf;
        };
      }
      int tap = 0;

      T[1] += T[4];
      tap += T[4];

      int f = min(T[1], T[2]);
      T[1] -= f;
      T[2] -= f;
      tap += f;

      if(T[1] == 0) {
        assert(T[2] * 2 % 3 == 0);
        int g = T[2] * 2 / 3;
        assert(g % 2 == 0);
        tap += g / 2;
        tap += g;
      } else {
        assert(T[1] % 3 == 0);
        tap += T[1] / 3 * 2;
      }
      return tap;
    };
    map< vector< int >, int > dp;
    auto rec = MFP([&](auto rec, int depth) -> int {
      if(depth >= 5) {
        return inf;
      }
      if(dp.count(S)) {
        return dp[S];
      }
      int cost = get_cost();
      for(int i = 1; i <= 4; i++) {
        if(S[i] > 0) {
          S[i]--;
          for(int j = i; j <= 4; j++) {
            if(S[j] > 0) {
              S[j]--;
              int sub = 0, s = i + j;
              while(s > 4) {
                s -= 3;
                ++sub;
              }
              S[s]++;
              chmin(cost, rec(depth + 1) + sub + 1);
              S[s]--;
              S[j]++;
            }
          }
          S[i]++;
        }
      }
      for(int i = 1; i <= 4; i++) {
        if(S[i] > 0) {
          S[i]--;
          for(int j = i - 1; j > 0; j--) {
            S[j]++;
            S[i - j]++;
            chmin(cost, rec(depth + 1) + 1);
            S[j]--;
            S[i - j]--;
          }
          S[i]++;
        }
      }
      return dp[S] = cost;
    });
    cout << cost + rec(0) << "\n";
  }
}