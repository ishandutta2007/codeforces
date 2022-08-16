#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

template< typename T, typename E = int >
struct SqrtDecomposition {

  vector< E > block_add, elem_add;
  vector< int > block_pos;
  vector< T > data, lsum;
  vector< vector< T > > sum;
  int N, B, K;
  E L;

  SqrtDecomposition(int N, E L = 0) : N(N), L(L) { // low
    B = 128;//(int) sqrt(N);
    K = (N + B - 1) / B;

    block_add.assign(K, 0);
    block_pos.resize(N);
    for(int k = 0; k < K; k++) {
      for(int i = k * B; i < min((k + 1) * B, N); i++) block_pos[i] = k;
    }
    elem_add.assign(N, 0);
    data.assign(N, 0);
    sum.assign(K, vector< T >(B, 0));
    lsum.assign(K, 0);
  }


  void build(const vector< E > &add, const vector< T > &dat) {
    assert(add.size() == elem_add.size());
    assert(dat.size() == data.size());
    elem_add = add;
    data = dat;
    for(int k = 0; k < K; k++) {
      E tap = elem_add[k * B];
      for(int i = k * B; i < min((k + 1) * B, N); i++) tap = min(tap, elem_add[i]);
      block_add[k] = tap;
      for(int i = k * B; i < min((k + 1) * B, N); i++) {
        elem_add[i] -= block_add[k];
        set(i, dat[i]);
      }
    }
  }

  inline void del(int k) {
    sum[block_pos[k]][elem_add[k]] -= data[k];
    if(block_add[block_pos[k]] + elem_add[k] >= L) lsum[block_pos[k]] -= data[k];
  }

  inline void set(int k) {
    while(sum[block_pos[k]].size() <= elem_add[k]) sum[block_pos[k]].push_back(0);
    sum[block_pos[k]][elem_add[k]] += data[k];
    if(block_add[block_pos[k]] + elem_add[k] >= L) lsum[block_pos[k]] += data[k];
  }

  void set(int k, T x) {
    data[k] = x;
    set(k);
  }

  void add(int a, int b) {
    for(int k = 0; k < K; k++) {
      int l = k * B;
      int r = min(l + B, N);

      if(r <= a || b <= l) {

      } else if(a <= l && r <= b) {
        block_add[k]++;
        if(0 <= L - block_add[k] && L - block_add[k] < sum[k].size()) {
          lsum[k] += sum[k][L - block_add[k]];
        }
      } else {
        for(int i = max(a, l); i < min(b, r); i++) {
          del(i);
          elem_add[i]++;
          set(i);
        }
      }
    }
  }


  void sub(int a, int b) {
    for(int k = 0; k < K; k++) {
      int l = k * B;
      int r = min(l + B, N);

      if(r <= a || b <= l) {

      } else if(a <= l && r <= b) {
        if(0 <= L - block_add[k] && L - block_add[k] < sum[k].size()) {
          lsum[k] -= sum[k][L - block_add[k]];
        }
        block_add[k]--;
      } else {
        if(0 <= L - block_add[k] && L - block_add[k] < sum[k].size()) {
          lsum[k] -= sum[k][L - block_add[k]];
        }
        block_add[k]--;
        for(int i = l; i < max(a, l); i++) {
          del(i);
          elem_add[i]++;
          set(i);
        }
        for(int i = min(b, r); i < r; i++) {
          del(i);
          elem_add[i]++;
          set(i);
        }
      }
    }
  }


  T query(int a, int b, E x) {
    T ret = 0;
    for(int k = 0; k < K; k++) {
      int l = k * B;
      int r = min(l + B, N);

      if(r <= a || b <= l) {

      } else if(a <= l && r <= b) {
        if(0 <= x - block_add[k] && x - block_add[k] < sum[k].size()) {
          ret += sum[k][x - block_add[k]];
        }
      } else {
        for(int i = max(a, l); i < min(b, r); i++) {
          if(block_add[k] + elem_add[i] == x) ret += data[i];
        }
      }
    }
    return ret;
  }


  T query_low(int a, int b) {
    T ret = 0;
    for(int k = 0; k < K; k++) {
      int l = k * B;
      int r = min(l + B, N);

      if(r <= a || b <= l) {

      } else if(a <= l && r <= b) {
        ret += lsum[k];
      } else {
        for(int i = max(a, l); i < min(b, r); i++) {
          if(block_add[k] + elem_add[i] >= L) ret += data[i];
        }
      }
    }
    return ret;
  }

};

template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

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
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return ModInt(u);
  }

  friend ostream &operator<<(ostream &os, const ModInt< mod > &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt< mod > &a) {
    long long x;
    is >> x;
    a = ModInt< mod >(x);
    return (is);
  }

};

const int mod = 998244353;
using modint = ModInt< mod >;


int main() {
  int K, N, A[100000];
  cin >> N >> K;
  ++K;
  vector< int > ap[100000];
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    --A[i];
    ap[A[i]].emplace_back(i);
  }
  int last[100000];
  memset(last, -1, sizeof(last));
  for(int i = 0; i < N; i++) {
    for(int j = 1; j < ap[i].size(); j++) {
      last[ap[i][j]] = ap[i][j - 1];
    }
  }

  vector< int > dp(N + 1);
  dp[0] = 1;

  int appear[100000];
  int cor[100000];
  memset(appear, -1, sizeof(appear));
  memset(cor, -1, sizeof(cor));

  set< pair< pair< int, int >, int > > range;
  SqrtDecomposition< modint > seg(N + 1, K);
  modint all = 1;
  seg.set(0, 1);
  for(int i = 1; i <= N; i++) {

    if(range.count({make_pair(appear[A[i - 1]] + 1, cor[A[i - 1]] + 1), A[i - 1]})) {
      range.erase({make_pair(appear[A[i - 1]] + 1, cor[A[i - 1]] + 1), A[i - 1]});
      seg.sub(appear[A[i - 1]] + 1, cor[A[i - 1]] + 1);
    }
    appear[A[i - 1]] = last[i - 1];
    cor[A[i - 1]] = i - 1;
    seg.add(appear[A[i - 1]] + 1, cor[A[i - 1]] + 1);
    range.emplace(make_pair(appear[A[i - 1]] + 1, cor[A[i - 1]] + 1), A[i - 1]);
    modint add = (all - seg.query_low(0, N + 1));
    all += add;
    if(i == N) cout << add.x << endl;
    seg.set(i, add);
  }
}