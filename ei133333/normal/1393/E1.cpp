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
  int N;
  cin >> N;
  vector< string > S(N);
  cin >> S;
  auto cur_dp = make_v< modint >(S[0].size());
  modint none_dp = 1;
  for(int i = 0; i < S[0].size(); i++) cur_dp[i] = 1;

  for(int i = 1; i < N; i++) {
    auto nxt_dp = make_v< modint >(S[i].size());
    modint nxt_none = 0;
    auto &X = S[i - 1];
    auto &Y = S[i];

    vector< int > beet(max(X.size(), Y.size()) + 2, inf);
    auto latte{beet}, malta{beet};
    for(int j = (int) max(X.size(), Y.size()); j >= 0; j--) {
      beet[j] = beet[j + 1];
      if(j < X.size() && j < Y.size() && X[j] != Y[j]) {
        beet[j] = j;
      }
    }
    for(int j = (int) max(X.size(), Y.size()); j > 0; j--) {
      latte[j] = latte[j + 1];
      if(j - 1 < X.size() && j < Y.size() && X[j - 1] != Y[j]) {
        latte[j] = j;
      }
    }
    for(int j = (int) max(X.size(), Y.size()); j > 0; j--) {
      malta[j] = malta[j + 1];
      if(j < X.size() && j - 1 < Y.size() && X[j] != Y[j - 1]) {
        malta[j] = j;
      }
    }

    for(int pre = 0; pre < (int) cur_dp.size(); pre++) {
      for(int nxt = 0; nxt < (int) nxt_dp.size(); nxt++) {


        // compare O(1)
        // S[i-1][0,pre)+S[i-1][pre+1,)  S[i][0,nxt)+S[i][nxt+1,)
        //    A         +    B                C     +    D

        //  AAAA*BBBBBB
        //  CCCCCCCCC*D

        //  AAAAAA*BBBB
        //  CCCC*DDDDDD

        //  AAAA*BBBBBB
        //  CCCC*DDDDDD

        if(beet[0] < pre && beet[0] < nxt) {
          if(X[beet[0]] < Y[beet[0]]) {
            nxt_dp[nxt] += cur_dp[pre];
          }
          continue;
        }

        if(pre < nxt) {
          if(malta[pre + 1] <= nxt) {
            if(X[malta[pre + 1]] < Y[malta[pre + 1] - 1]) {
              nxt_dp[nxt] += cur_dp[pre];
            }
            continue;
          }
          if(beet[nxt + 1] != inf) {
            if(X[beet[nxt + 1]] < Y[beet[nxt + 1]]) {
              nxt_dp[nxt] += cur_dp[pre];
            }
            continue;
          }
        } else if(pre > nxt) {
          if(latte[nxt + 1] <= pre) {
            if(X[latte[nxt + 1] - 1] < Y[latte[nxt + 1]]) {
              nxt_dp[nxt] += cur_dp[pre];
            }
            continue;
          }
          if(beet[pre + 1] != inf) {
            if(X[beet[pre + 1]] < Y[beet[pre + 1]]) {
              nxt_dp[nxt] += cur_dp[pre];
            }
            continue;
          }
        } else {
          if(beet[nxt + 1] != inf) {
            if(X[beet[nxt + 1]] < Y[beet[nxt + 1]]) {
              nxt_dp[nxt] += cur_dp[pre];
            }
            continue;
          }
        }
        if(cur_dp.size() <= nxt_dp.size()) {
          nxt_dp[nxt] += cur_dp[pre];
        }
      }
    }


    if(X <= Y) {
      nxt_none += none_dp;
    }
    for(int j = 0; j < (int) cur_dp.size(); j++) {
      if(beet[0] < j) {
        if(X[beet[0]] < Y[beet[0]]) {
          nxt_none += cur_dp[j];
        }
        continue;
      }
      if(malta[j + 1] != inf) {
        if(X[malta[j + 1]] < Y[malta[j + 1] - 1]) {
          nxt_none += cur_dp[j];
        }
        continue;
      }
      if(cur_dp.size() <= nxt_dp.size() + 1) {
        nxt_none += cur_dp[j];
      }
    }

    for(int j = 0; j < (int) nxt_dp.size(); j++) {
      if(beet[0] < j) {
        if(X[beet[0]] < Y[beet[0]]) {
          nxt_dp[j] += none_dp;
        }
        continue;
      }
      if(latte[j + 1] != inf) {
        if(X[latte[j + 1] - 1] < Y[latte[j + 1]]) {
          nxt_dp[j] += none_dp;
        }
        continue;
      }
      if(cur_dp.size() + 1 <= nxt_dp.size()) {
        nxt_dp[j] += none_dp;
      }
    }

    cur_dp = move(nxt_dp);
    none_dp = nxt_none;
  }
  modint ret = 0;
  for(int i = 0; i < cur_dp.size(); i++) ret += cur_dp[i];
  cout << ret + none_dp << "\n";
}