#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }

// https://judge.yosupo.jp/submission/4649
using uint = unsigned int;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
struct Scanner {
    FILE* fp = nullptr;
    char line[(1 << 15) + 1];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
        line[ed] = '\0';
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) reread();
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            size_t sz = 0;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (!sz || st != ed) break;
            reread();
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] - '0');
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(V<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    Scanner(FILE* _fp) : fp(_fp) {}
};
struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T> void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }

    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }

  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val; // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        for (size_t i = 0; i < len; i++) {
            line[pos + i] = small[len - 1 - i];
        }
        pos += len;
    }
    void write_single(const string& s) {
        for (char c : s) write_single(c);
    }
    void write_single(const char* s) {
        size_t len = strlen(s);
        for (size_t i = 0; i < len; i++) write_single(s[i]);
    }
    template <class T> void write_single(const V<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};
Scanner sc(stdin);
Printer pr(stdout);

int mod = MOD;
struct ModInt {
  unsigned val;
  ModInt(): val(0) {}
  ModInt(ll x) : val(x >= 0 ? x % mod : x % mod + mod) {}
  ModInt pow(ll exponent) {
    ModInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  ModInt &operator+=(const ModInt &x) { if((val += x.val) >= mod) val -= mod; return *this; }
  ModInt &operator-=(const ModInt &x) { if((val += mod - x.val) >= mod) val -= mod; return *this; }
  ModInt &operator*=(const ModInt &x) { val = static_cast<unsigned long long>(val) * x.val % mod; return *this; }
  ModInt &operator/=(const ModInt &x) {
    // assert(__gcd(static_cast<int>(x.val), mod) == 1);
    unsigned a = x.val, b = mod; int u = 1, v = 0;
    while (b) {
      unsigned tmp = a / b;
      swap(a -= tmp * b, b);
      swap(u -= tmp * v, v);
    }
    return *this *= u;
  }
  bool operator==(const ModInt &x) const { return val == x.val; }
  bool operator!=(const ModInt &x) const { return val != x.val; }
  bool operator<(const ModInt &x) const { return val < x.val; }
  bool operator<=(const ModInt &x) const { return val <= x.val; }
  bool operator>(const ModInt &x) const { return val > x.val; }
  bool operator>=(const ModInt &x) const { return val >= x.val; }
  ModInt &operator++() { if (++val == mod) val = 0; return *this; }
  ModInt operator++(int) { ModInt res = *this; ++*this; return res; }
  ModInt &operator--() { val = (val == 0 ? mod : val) - 1; return *this; }
  ModInt operator--(int) { ModInt res = *this; --*this; return res; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt(val ? mod - val : 0); }
  ModInt operator+(const ModInt &x) const { return ModInt(*this) += x; }
  ModInt operator-(const ModInt &x) const { return ModInt(*this) -= x; }
  ModInt operator*(const ModInt &x) const { return ModInt(*this) *= x; }
  ModInt operator/(const ModInt &x) const { return ModInt(*this) /= x; }
  friend ostream &operator<<(ostream &os, const ModInt &x) { return os << x.val; }
  friend istream &operator>>(istream &is, ModInt &x) { ll val; is >> val; x = ModInt(val); return is; }
};
ModInt abs(const ModInt &x) { return x; }
struct Combinatorics {
  int val; // "val!" and "mod" must be disjoint.
  vector<ModInt> fact, fact_inv, inv;
  Combinatorics(int val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {
    fact[0] = 1;
    FOR(i, 1, val + 1) fact[i] = fact[i - 1] * i;
    fact_inv[val] = ModInt(1) / fact[val];
    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    FOR(i, 1, val + 1) inv[i] = fact[i - 1] * fact_inv[i];
  }
  ModInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) {
    if (n < 0 || n < k || k < 0) return ModInt(0);
    // assert(n <= val);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) {
    if (n < 0 || k < 0) return ModInt(0);
    return (k == 0 ? ModInt(1) : nCk(n + k - 1, k));
  }
};

using CostType = int;
struct Edge {
  int dst; CostType cost;
  Edge(int dst, CostType cost = 0) : dst(dst), cost(cost) {}
  inline bool operator<(const Edge &rhs) const {
    return cost != rhs.cost ? cost < rhs.cost : dst != rhs.dst;
  }
  inline bool operator<=(const Edge &rhs) const { return !(rhs < *this); }
  inline bool operator>(const Edge &rhs) const { return rhs < *this; }
  inline bool operator>=(const Edge &rhs) const { return !(*this < rhs); }
};

// template <int D>
// struct Basis {
//   vector<bitset<D> > v;
//   vector<int> msb;

//   bool add(bitset<D> val) {
//     int n = v.size();
//     if (n == D) return false;
//     REP(i, n) {
//       if (val[msb[i]]) val ^= v[i];
//     }
//     if (val.none()) return false;
//     int m = D - 1;
//     while (!val[m]) --m;
//     if (v.empty()) {
//       v.emplace_back(val);
//       msb.emplace_back(m);
//       return true;
//     }
//     int idx = n - distance(msb.rbegin(), upper_bound(msb.rbegin(), msb.rend(), m));
//     v.emplace(v.begin() + idx, val);
//     msb.emplace(msb.begin() + idx, m);
//     for (int i = n; i > idx; --i) {
//       if (v[idx][msb[i]]) v[idx] ^= v[i];
//     }
//     for (int i = idx - 1; i >= 0; --i) {
//       if (v[i][m]) v[i] ^= v[idx];
//     }
//     return true;
//   }

//   bool add(ll val) { return add(bitset<D>(val)); }

//   int rank() const { return v.size(); }

//   inline bool operator<(const Basis &x) const {
//     int n = v.size();
//     if (n != x.v.size()) return n < x.v.size();
//     if (n == D) return false;
//     REP(i, n) {
//       if (msb[i] != x.msb[i]) return msb[i] < x.msb[i];
//     }
//     REP(i, n) {
//       if (v[i] != x.v[i]) {
//         for (int j = msb[i] - 1; ; --j) {
//           if (v[i][j] != x.v[i][j]) return v[i][j] < x.v[i][j];
//         }
//       }
//     }
//     return false;
//   }
// };

template <int D>
struct Basis {
  int v[D] = {}, rank = 0, hash = 0;

  bool add(int val) {
    if (rank == D) return false;
    for (int i = 4; i >= 0; --i) {
      if (!(val >> i & 1)) continue;
      if (v[i]) {
        val ^= v[i];
        continue;
      }
      REP(j, i) {
        if (val >> j & 1) val ^= v[j];
      }
      ++rank;
      v[i] = val;
      hash |= val << (D * i);
      FOR(j, i + 1, D) {
        if (v[j] >> i & 1) {
          v[j] ^= val;
          hash ^= val << (D * j);
        }
      }
      return true;
    }
    return false;
  }

  inline bool operator==(const Basis &x) const { return hash == x.hash; }
  // inline bool operator<(const Basis &x) const { return hash < x.hash; }
};

namespace std {
  template <int D>
  struct hash<Basis<D> > {
    size_t operator()(const Basis<D> &x) const { return x.hash; }
  };
}

const int N = 100000, D = 5;

int n, x[N];
vector<Edge> graph[N];

int dst = -1, cost = -1, root;
Basis<D> now;
bool era = false;

void dfs(int par, int ver) {
  for (const Edge &e : graph[ver]) {
    if (era && ver != root) return;
    if (e.dst == par) continue;
    if (e.dst == 0) {
      dst = ver;
      cost = e.cost;
    } else if (x[e.dst] == -1) {
      x[e.dst] = x[ver] ^ e.cost;
      dfs(ver, e.dst);
    } else if (ver < e.dst) {
      era |= !now.add(x[ver] ^ x[e.dst] ^ e.cost);
    }
  }
}

int main() {
  // map<Basis<D>, int> mp;
  // mp[Basis<D>()] = 0;
  // FOR(i, 1, 32) {
  //   Basis<D> basis;
  //   basis.add(i);
  //   mp[basis] = basis.hash;
  //   FOR(j, i + 1, 32) {
  //     Basis<D> basis2 = basis;
  //     basis2.add(j);
  //     mp[basis2] = basis2.hash;
  //     FOR(k, j + 1, 32) {
  //       Basis<D> basis3 = basis2;
  //       basis3.add(k);
  //       mp[basis3] = basis3.hash;
  //       FOR(l, k + 1, 32) {
  //         Basis<D> basis4 = basis3;
  //         basis4.add(l);
  //         mp[basis4] = basis4.hash;
  //         FOR(m, l + 1, 32) {
  //           Basis<D> basis5 = basis4;
  //           basis5.add(m);
  //           mp[basis5] = basis5.hash;
  //         }
  //       }
  //     }
  //   }
  // }
  // cout << '{';
  // for (auto it = mp.begin(); it != mp.end(); ++it) {
  //   Basis<D> basis = it->first;
  //   cout << '{';
  //   REP(i, 5) cout << basis.v[i] << ",}"[i + 1 == 5];
  //   cout << ",}"[next(it) == mp.end()];
  // }
  // cout << '\n';
  // cout << '{';
  // for (auto it = mp.begin(); it != mp.end(); ++it) {
  //   Basis<D> basis = it->first;
  //   cout << basis.rank << ",}"[next(it) == mp.end()];
  // }
  // cout << '\n';
  // cout << '{';
  // for (auto it = mp.begin(); it != mp.end(); ++it) {
  //   Basis<D> basis = it->first;
  //   cout << basis.hash << ",}"[next(it) == mp.end()];
  // }
  // cout << '\n';

  const int M = 374;
  vector<vector<int> > v{{0,0,0,0,0},{1,0,0,0,0},{0,2,0,0,0},{1,2,0,0,0},{0,3,0,0,0},{0,0,4,0,0},{1,0,4,0,0},{0,2,4,0,0},{1,2,4,0,0},{0,3,4,0,0},{0,0,5,0,0},{0,2,5,0,0},{0,3,5,0,0},{0,0,6,0,0},{1,0,6,0,0},{0,0,7,0,0},{0,0,0,8,0},{1,0,0,8,0},{0,2,0,8,0},{1,2,0,8,0},{0,3,0,8,0},{0,0,4,8,0},{1,0,4,8,0},{0,2,4,8,0},{1,2,4,8,0},{0,3,4,8,0},{0,0,5,8,0},{0,2,5,8,0},{0,3,5,8,0},{0,0,6,8,0},{1,0,6,8,0},{0,0,7,8,0},{0,0,0,9,0},{0,2,0,9,0},{0,3,0,9,0},{0,0,4,9,0},{0,2,4,9,0},{0,3,4,9,0},{0,0,5,9,0},{0,2,5,9,0},{0,3,5,9,0},{0,0,6,9,0},{0,0,7,9,0},{0,0,0,10,0},{1,0,0,10,0},{0,0,4,10,0},{1,0,4,10,0},{0,0,5,10,0},{0,0,6,10,0},{1,0,6,10,0},{0,0,7,10,0},{0,0,0,11,0},{0,0,4,11,0},{0,0,5,11,0},{0,0,6,11,0},{0,0,7,11,0},{0,0,0,12,0},{1,0,0,12,0},{0,2,0,12,0},{1,2,0,12,0},{0,3,0,12,0},{0,0,0,13,0},{0,2,0,13,0},{0,3,0,13,0},{0,0,0,14,0},{1,0,0,14,0},{0,0,0,15,0},{0,0,0,0,16},{1,0,0,0,16},{0,2,0,0,16},{1,2,0,0,16},{0,3,0,0,16},{0,0,4,0,16},{1,0,4,0,16},{0,2,4,0,16},{1,2,4,0,16},{0,3,4,0,16},{0,0,5,0,16},{0,2,5,0,16},{0,3,5,0,16},{0,0,6,0,16},{1,0,6,0,16},{0,0,7,0,16},{0,0,0,8,16},{1,0,0,8,16},{0,2,0,8,16},{1,2,0,8,16},{0,3,0,8,16},{0,0,4,8,16},{1,0,4,8,16},{0,2,4,8,16},{1,2,4,8,16},{0,3,4,8,16},{0,0,5,8,16},{0,2,5,8,16},{0,3,5,8,16},{0,0,6,8,16},{1,0,6,8,16},{0,0,7,8,16},{0,0,0,9,16},{0,2,0,9,16},{0,3,0,9,16},{0,0,4,9,16},{0,2,4,9,16},{0,3,4,9,16},{0,0,5,9,16},{0,2,5,9,16},{0,3,5,9,16},{0,0,6,9,16},{0,0,7,9,16},{0,0,0,10,16},{1,0,0,10,16},{0,0,4,10,16},{1,0,4,10,16},{0,0,5,10,16},{0,0,6,10,16},{1,0,6,10,16},{0,0,7,10,16},{0,0,0,11,16},{0,0,4,11,16},{0,0,5,11,16},{0,0,6,11,16},{0,0,7,11,16},{0,0,0,12,16},{1,0,0,12,16},{0,2,0,12,16},{1,2,0,12,16},{0,3,0,12,16},{0,0,0,13,16},{0,2,0,13,16},{0,3,0,13,16},{0,0,0,14,16},{1,0,0,14,16},{0,0,0,15,16},{0,0,0,0,17},{0,2,0,0,17},{0,3,0,0,17},{0,0,4,0,17},{0,2,4,0,17},{0,3,4,0,17},{0,0,5,0,17},{0,2,5,0,17},{0,3,5,0,17},{0,0,6,0,17},{0,0,7,0,17},{0,0,0,8,17},{0,2,0,8,17},{0,3,0,8,17},{0,0,4,8,17},{0,2,4,8,17},{0,3,4,8,17},{0,0,5,8,17},{0,2,5,8,17},{0,3,5,8,17},{0,0,6,8,17},{0,0,7,8,17},{0,0,0,9,17},{0,2,0,9,17},{0,3,0,9,17},{0,0,4,9,17},{0,2,4,9,17},{0,3,4,9,17},{0,0,5,9,17},{0,2,5,9,17},{0,3,5,9,17},{0,0,6,9,17},{0,0,7,9,17},{0,0,0,10,17},{0,0,4,10,17},{0,0,5,10,17},{0,0,6,10,17},{0,0,7,10,17},{0,0,0,11,17},{0,0,4,11,17},{0,0,5,11,17},{0,0,6,11,17},{0,0,7,11,17},{0,0,0,12,17},{0,2,0,12,17},{0,3,0,12,17},{0,0,0,13,17},{0,2,0,13,17},{0,3,0,13,17},{0,0,0,14,17},{0,0,0,15,17},{0,0,0,0,18},{1,0,0,0,18},{0,0,4,0,18},{1,0,4,0,18},{0,0,5,0,18},{0,0,6,0,18},{1,0,6,0,18},{0,0,7,0,18},{0,0,0,8,18},{1,0,0,8,18},{0,0,4,8,18},{1,0,4,8,18},{0,0,5,8,18},{0,0,6,8,18},{1,0,6,8,18},{0,0,7,8,18},{0,0,0,9,18},{0,0,4,9,18},{0,0,5,9,18},{0,0,6,9,18},{0,0,7,9,18},{0,0,0,10,18},{1,0,0,10,18},{0,0,4,10,18},{1,0,4,10,18},{0,0,5,10,18},{0,0,6,10,18},{1,0,6,10,18},{0,0,7,10,18},{0,0,0,11,18},{0,0,4,11,18},{0,0,5,11,18},{0,0,6,11,18},{0,0,7,11,18},{0,0,0,12,18},{1,0,0,12,18},{0,0,0,13,18},{0,0,0,14,18},{1,0,0,14,18},{0,0,0,15,18},{0,0,0,0,19},{0,0,4,0,19},{0,0,5,0,19},{0,0,6,0,19},{0,0,7,0,19},{0,0,0,8,19},{0,0,4,8,19},{0,0,5,8,19},{0,0,6,8,19},{0,0,7,8,19},{0,0,0,9,19},{0,0,4,9,19},{0,0,5,9,19},{0,0,6,9,19},{0,0,7,9,19},{0,0,0,10,19},{0,0,4,10,19},{0,0,5,10,19},{0,0,6,10,19},{0,0,7,10,19},{0,0,0,11,19},{0,0,4,11,19},{0,0,5,11,19},{0,0,6,11,19},{0,0,7,11,19},{0,0,0,12,19},{0,0,0,13,19},{0,0,0,14,19},{0,0,0,15,19},{0,0,0,0,20},{1,0,0,0,20},{0,2,0,0,20},{1,2,0,0,20},{0,3,0,0,20},{0,0,0,8,20},{1,0,0,8,20},{0,2,0,8,20},{1,2,0,8,20},{0,3,0,8,20},{0,0,0,9,20},{0,2,0,9,20},{0,3,0,9,20},{0,0,0,10,20},{1,0,0,10,20},{0,0,0,11,20},{0,0,0,12,20},{1,0,0,12,20},{0,2,0,12,20},{1,2,0,12,20},{0,3,0,12,20},{0,0,0,13,20},{0,2,0,13,20},{0,3,0,13,20},{0,0,0,14,20},{1,0,0,14,20},{0,0,0,15,20},{0,0,0,0,21},{0,2,0,0,21},{0,3,0,0,21},{0,0,0,8,21},{0,2,0,8,21},{0,3,0,8,21},{0,0,0,9,21},{0,2,0,9,21},{0,3,0,9,21},{0,0,0,10,21},{0,0,0,11,21},{0,0,0,12,21},{0,2,0,12,21},{0,3,0,12,21},{0,0,0,13,21},{0,2,0,13,21},{0,3,0,13,21},{0,0,0,14,21},{0,0,0,15,21},{0,0,0,0,22},{1,0,0,0,22},{0,0,0,8,22},{1,0,0,8,22},{0,0,0,9,22},{0,0,0,10,22},{1,0,0,10,22},{0,0,0,11,22},{0,0,0,12,22},{1,0,0,12,22},{0,0,0,13,22},{0,0,0,14,22},{1,0,0,14,22},{0,0,0,15,22},{0,0,0,0,23},{0,0,0,8,23},{0,0,0,9,23},{0,0,0,10,23},{0,0,0,11,23},{0,0,0,12,23},{0,0,0,13,23},{0,0,0,14,23},{0,0,0,15,23},{0,0,0,0,24},{1,0,0,0,24},{0,2,0,0,24},{1,2,0,0,24},{0,3,0,0,24},{0,0,4,0,24},{1,0,4,0,24},{0,2,4,0,24},{1,2,4,0,24},{0,3,4,0,24},{0,0,5,0,24},{0,2,5,0,24},{0,3,5,0,24},{0,0,6,0,24},{1,0,6,0,24},{0,0,7,0,24},{0,0,0,0,25},{0,2,0,0,25},{0,3,0,0,25},{0,0,4,0,25},{0,2,4,0,25},{0,3,4,0,25},{0,0,5,0,25},{0,2,5,0,25},{0,3,5,0,25},{0,0,6,0,25},{0,0,7,0,25},{0,0,0,0,26},{1,0,0,0,26},{0,0,4,0,26},{1,0,4,0,26},{0,0,5,0,26},{0,0,6,0,26},{1,0,6,0,26},{0,0,7,0,26},{0,0,0,0,27},{0,0,4,0,27},{0,0,5,0,27},{0,0,6,0,27},{0,0,7,0,27},{0,0,0,0,28},{1,0,0,0,28},{0,2,0,0,28},{1,2,0,0,28},{0,3,0,0,28},{0,0,0,0,29},{0,2,0,0,29},{0,3,0,0,29},{0,0,0,0,30},{1,0,0,0,30},{0,0,0,0,31}};
  vector<int> rank{0,1,1,2,1,1,2,2,3,2,1,2,2,1,2,1,1,2,2,3,2,2,3,3,4,3,2,3,3,2,3,2,1,2,2,2,3,3,2,3,3,2,2,1,2,2,3,2,2,3,2,1,2,2,2,2,1,2,2,3,2,1,2,2,1,2,1,1,2,2,3,2,2,3,3,4,3,2,3,3,2,3,2,2,3,3,4,3,3,4,4,5,4,3,4,4,3,4,3,2,3,3,3,4,4,3,4,4,3,3,2,3,3,4,3,3,4,3,2,3,3,3,3,2,3,3,4,3,2,3,3,2,3,2,1,2,2,2,3,3,2,3,3,2,2,2,3,3,3,4,4,3,4,4,3,3,2,3,3,3,4,4,3,4,4,3,3,2,3,3,3,3,2,3,3,3,3,2,3,3,2,3,3,2,2,1,2,2,3,2,2,3,2,2,3,3,4,3,3,4,3,2,3,3,3,3,2,3,3,4,3,3,4,3,2,3,3,3,3,2,3,2,2,3,2,1,2,2,2,2,2,3,3,3,3,2,3,3,3,3,2,3,3,3,3,2,3,3,3,3,2,2,2,2,1,2,2,3,2,2,3,3,4,3,2,3,3,2,3,2,2,3,3,4,3,2,3,3,2,3,2,1,2,2,2,3,3,2,3,3,2,2,2,3,3,2,3,3,2,2,1,2,2,3,2,2,3,2,2,3,2,2,3,2,1,2,2,2,2,2,2,2,2,1,2,2,3,2,2,3,3,4,3,2,3,3,2,3,2,1,2,2,2,3,3,2,3,3,2,2,1,2,2,3,2,2,3,2,1,2,2,2,2,1,2,2,3,2,1,2,2,1,2,1};
  vector<int> hash{0,1,64,65,96,4096,4097,4160,4161,4192,5120,5184,5216,6144,6145,7168,262144,262145,262208,262209,262240,266240,266241,266304,266305,266336,267264,267328,267360,268288,268289,269312,294912,294976,295008,299008,299072,299104,300032,300096,300128,301056,302080,327680,327681,331776,331777,332800,333824,333825,334848,360448,364544,365568,366592,367616,393216,393217,393280,393281,393312,425984,426048,426080,458752,458753,491520,16777216,16777217,16777280,16777281,16777312,16781312,16781313,16781376,16781377,16781408,16782336,16782400,16782432,16783360,16783361,16784384,17039360,17039361,17039424,17039425,17039456,17043456,17043457,17043520,17043521,17043552,17044480,17044544,17044576,17045504,17045505,17046528,17072128,17072192,17072224,17076224,17076288,17076320,17077248,17077312,17077344,17078272,17079296,17104896,17104897,17108992,17108993,17110016,17111040,17111041,17112064,17137664,17141760,17142784,17143808,17144832,17170432,17170433,17170496,17170497,17170528,17203200,17203264,17203296,17235968,17235969,17268736,17825792,17825856,17825888,17829888,17829952,17829984,17830912,17830976,17831008,17831936,17832960,18087936,18088000,18088032,18092032,18092096,18092128,18093056,18093120,18093152,18094080,18095104,18120704,18120768,18120800,18124800,18124864,18124896,18125824,18125888,18125920,18126848,18127872,18153472,18157568,18158592,18159616,18160640,18186240,18190336,18191360,18192384,18193408,18219008,18219072,18219104,18251776,18251840,18251872,18284544,18317312,18874368,18874369,18878464,18878465,18879488,18880512,18880513,18881536,19136512,19136513,19140608,19140609,19141632,19142656,19142657,19143680,19169280,19173376,19174400,19175424,19176448,19202048,19202049,19206144,19206145,19207168,19208192,19208193,19209216,19234816,19238912,19239936,19240960,19241984,19267584,19267585,19300352,19333120,19333121,19365888,19922944,19927040,19928064,19929088,19930112,20185088,20189184,20190208,20191232,20192256,20217856,20221952,20222976,20224000,20225024,20250624,20254720,20255744,20256768,20257792,20283392,20287488,20288512,20289536,20290560,20316160,20348928,20381696,20414464,20971520,20971521,20971584,20971585,20971616,21233664,21233665,21233728,21233729,21233760,21266432,21266496,21266528,21299200,21299201,21331968,21364736,21364737,21364800,21364801,21364832,21397504,21397568,21397600,21430272,21430273,21463040,22020096,22020160,22020192,22282240,22282304,22282336,22315008,22315072,22315104,22347776,22380544,22413312,22413376,22413408,22446080,22446144,22446176,22478848,22511616,23068672,23068673,23330816,23330817,23363584,23396352,23396353,23429120,23461888,23461889,23494656,23527424,23527425,23560192,24117248,24379392,24412160,24444928,24477696,24510464,24543232,24576000,24608768,25165824,25165825,25165888,25165889,25165920,25169920,25169921,25169984,25169985,25170016,25170944,25171008,25171040,25171968,25171969,25172992,26214400,26214464,26214496,26218496,26218560,26218592,26219520,26219584,26219616,26220544,26221568,27262976,27262977,27267072,27267073,27268096,27269120,27269121,27270144,28311552,28315648,28316672,28317696,28318720,29360128,29360129,29360192,29360193,29360224,30408704,30408768,30408800,31457280,31457281,32505856};

  unordered_map<Basis<D>, int> basis;
  unordered_map<int, Basis<D> > rev;
  REP(i, M) {
    Basis<D> now;
    REP(j, D) now.v[j] = v[i][j];
    now.rank = rank[i];
    now.hash = hash[i];
    basis[now] = i;
    rev[i] = now;
  }
  vector<vector<int> > add(M, vector<int>(M, -1));
  REP(i, M) FOR(j, i, M) {
    if (rank[i] + rank[j] > D) continue;
    Basis<D> now = rev[i], ad = rev[j];
    REP(k, D) now.add(ad.v[k]);
    if (now.rank == rank[i] + rank[j]) add[i][j] = add[j][i] = basis[now];
  }

  int m; sc.read(n, m);
  memset(x, -1, sizeof(x));
  while (m--) {
    int a, b, w; sc.read(a, b, w); --a; --b;
    graph[a].emplace_back(b, w);
    graph[b].emplace_back(a, w);
  }
  unordered_map<int, ModInt> dp;
  dp[0] = 1;
  for (const Edge &edge : graph[0]) {
    if (x[edge.dst] != -1) continue;
    memset(now.v, 0, sizeof(now.v));
    now.rank = now.hash = 0;
    dst = -1;
    root = edge.dst;
    x[root] = edge.cost;
    era = false;
    dfs(0, root);
    if (era) continue;
    int weight = dst == -1 ? 1 : 2;
    unordered_map<int, ModInt> nx;
    for (auto pr : dp) {
      int key; ModInt val; tie(key, val) = pr;
      nx[key] += val;
      int now_idx = basis[now];
      if (add[key][now_idx] == -1) continue;
      nx[add[key][now_idx]] += val * weight;
      if (dst != -1) {
        Basis<D> last;
        if (last.add(x[dst] ^ cost)) {
          int last_idx = basis[last];
          if (add[add[key][now_idx]][last_idx] != -1) nx[add[add[key][now_idx]][last_idx]] += val;
        }
      }
    }
    dp.swap(nx);
    // for (auto pr : dp) cout << pr.first << ' ' << pr.second << '\n';
    // cout << '\n';
  }
  ModInt ans = 0;
  for (auto it = dp.begin(); it != dp.end(); ++it) ans += it->second;
  pr.writeln(ans.val);
  return 0;
}