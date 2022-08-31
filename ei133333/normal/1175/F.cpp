#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
const int inf = (1 << 30) - 1;
const int64 infll = (1LL << 61) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;

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

struct UnionFindRange {
  vector< int > data;
  vector< int > left, right;

  UnionFindRange(int sz) {
    data.assign(sz, -1);
    left.resize(sz);
    right.resize(sz);
    for(int i = 0; i < sz; i++) left[i] = i;
    for(int i = 0; i < sz; i++) right[i] = i;
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    left[x] = min(left[x], left[y]);
    right[x] = max(right[x], right[y]);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  pair< int, int > range(int k) {
    k = find(k);
    return {left[k], right[k]};
  };

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

struct SuccinctIndexableDictionary {
  size_t length;
  size_t blocks;
  vector< unsigned > bit, sum;

  SuccinctIndexableDictionary() {
  }

  SuccinctIndexableDictionary(size_t _length) {
    length = _length;
    blocks = (length + 31) >> 5;
    bit.assign(blocks, 0U);
    sum.assign(blocks, 0U);
  }

  void set(int k) {
    bit[k >> 5] |= 1U << (k & 31);
  }

  void build() {
    sum[0] = 0U;
    for(int i = 1; i < blocks; i++) {
      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);
    }
  }

  bool operator[](int k) const {
    return (bool((bit[k >> 5] >> (k & 31)) & 1));
  }

  int rank(int k) {
    return (sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));
  }

  int rank(bool val, int k) {
    return (val ? rank(k) : k - rank(k));
  }

  int select(bool val, int k) {
    if(k < 0 || rank(val, length) <= k) return (-1);
    int low = 0, high = length;
    while(high - low > 1) {
      int mid = (low + high) >> 1;
      if(rank(val, mid) >= k + 1) high = mid;
      else low = mid;
    }
    return (high - 1);
  }

  int select(bool val, int i, int l) {
    return select(val, i + rank(val, l));
  }
};

template< class T, int MAXLOG >
struct WaveletMatrix {
  size_t length;
  SuccinctIndexableDictionary matrix[MAXLOG];
  int zs[MAXLOG];
  int buff1[MAXLOG], buff2[MAXLOG];

  void max_dfs(int d, int l, int r, int &k, T val, vector< T > &vs) {
    if(l >= r || !k) return;
    if(d == MAXLOG) {
      while(l++ < r && k > 0) vs.push_back(val), k--;
      return;
    }
    int lc = matrix[d].rank(1, l), rc = matrix[d].rank(1, r);
    max_dfs(d + 1, lc + zs[d], rc + zs[d], k, 1ULL << (MAXLOG - d - 1) | val, vs);
    max_dfs(d + 1, l - lc, r - rc, k, val, vs);
  }

  T max_dfs(int d, int l, int r, T val, T a, T b) {
    if(r - l <= 0 || val >= b) return -1;
    if(d == MAXLOG) return val >= a ? val : -1;
    int lc = matrix[d].rank(1, l), rc = matrix[d].rank(1, r);
    T ret = max_dfs(d + 1, lc + zs[d], rc + zs[d], 1ULL << (MAXLOG - d - 1) | val, a, b);
    if(~ret) return ret;
    return max_dfs(d + 1, l - lc, r - rc, val, a, b);
  }

  int freq_dfs(int d, int l, int r, T val, T a, T b) {
    if(l == r) return 0;
    if(d == MAXLOG) return (a <= val && val < b) ? r - l : 0;
    T nv = 1ULL << (MAXLOG - d - 1) | val, nnv = ((1ULL << (MAXLOG - d - 1)) - 1) | nv;
    if(nnv < a || b <= val) return 0;
    if(a <= val && nnv < b) return r - l;
    int lc = matrix[d].rank(1, l), rc = matrix[d].rank(1, r);
    return freq_dfs(d + 1, l - lc, r - rc, val, a, b) +
           freq_dfs(d + 1, lc + zs[d], rc + zs[d], nv, a, b);
  }

  void list_dfs(int d, int l, int r, T val, T a, T b, vector< pair< T, int>> &vs) {
    if(val >= b || r - l <= 0) return;
    if(d == MAXLOG) {
      if(a <= val) vs.push_back(make_pair(val, r - l));
      return;
    }
    T nv = val | (1LL << (MAXLOG - d - 1)), nnv = nv | (((1LL << (MAXLOG - d - 1)) - 1));
    if(nnv < a) return;
    int lc = matrix[d].rank(1, l), rc = matrix[d].rank(1, r);
    list_dfs(d + 1, l - lc, r - rc, val, a, b, vs);
    list_dfs(d + 1, lc + zs[d], rc + zs[d], nv, a, b, vs);
  }


  WaveletMatrix(vector< T > data) {
    length = data.size();
    vector< T > l(length), r(length);
    for(int depth = 0; depth < MAXLOG; depth++) {
      matrix[depth] = SuccinctIndexableDictionary(length + 1);
      int left = 0, right = 0;
      for(int i = 0; i < length; i++) {
        bool k = (data[i] >> (MAXLOG - depth - 1)) & 1;
        if(k) r[right++] = data[i], matrix[depth].set(i);
        else l[left++] = data[i];
      }
      zs[depth] = left;
      matrix[depth].build();
      swap(l, data);
      for(int i = 0; i < right; i++) data[left + i] = r[i];
    }
  }

  T access(int k) {
    int ret = 0;
    bool bit;
    for(int depth = 0; depth < MAXLOG; depth++) {
      bit = matrix[depth][k];
      ret = (ret << 1) | bit;
      k = matrix[depth].rank(bit, k) + zs[depth] * bit;
    }
    return (ret);
  }

  int rank(T val, int k) {
    int l = 0, r = k;
    for(int depth = 0; depth < MAXLOG; depth++) {
      buff1[depth] = l, buff2[depth] = r;
      bool bit = (val >> (MAXLOG - depth - 1)) & 1;
      l = matrix[depth].rank(bit, l) + zs[depth] * bit;
      r = matrix[depth].rank(bit, r) + zs[depth] * bit;
    }
    return (r - l);
  }

  int select(T val, int kth) {
    rank(val, length);
    for(int depth = MAXLOG - 1; depth >= 0; depth--) {
      bool bit = (val >> (MAXLOG - depth - 1)) & 1;
      kth = matrix[depth].select(bit, kth, buff1[depth]);
      if(kth >= buff2[depth] || kth < 0) return (-1);
      kth -= buff1[depth];
    }
    return (kth);
  }

  int select(T val, int k, int l) {
    return (select(val, k + rank(val, l)));
  }


  int quantile(int left, int right, int kth) {
    if(right - left <= kth || kth < 0) return (-1);
    T ret = 0;
    for(int depth = 0; depth < MAXLOG; depth++) {
      int l = matrix[depth].rank(1, left);
      int r = matrix[depth].rank(1, right);
      if(r - l > kth) {
        left = l + zs[depth];
        right = r + zs[depth];
        ret |= 1ULL << (MAXLOG - depth - 1);
      } else {
        kth -= r - l;
        left -= l;
        right -= r;
      }
    }
    return (ret);
  }

  vector< T > topk(int l, int r, int k) {
    if(r - l < k) k = r - l;
    if(k < 0) return (vector< T >());
    vector< T > ret;
    max_dfs(0, l, r, k, 0, ret);
    return (ret);
  }

  vector< pair< T, int > > freq_list(int l, int r, T a, T b) {
    vector< pair< T, int > > ret;
    list_dfs(0, l, r, 0, a, b, ret);
    return (ret);
  }

  vector< pair< int, T > > get_rect(int l, int r, T a, T b) {
    vector< pair< T, int > > res = freq_list(l, r, a, b);
    vector< pair< int, T > > ret;
    for(auto &e : res) {
      for(int i = 0; i < e.second; i++) {
        ret.emplace_back(select(e.first, i, l), e.first);
      }
    }
    return (ret);
  }

  int rangefreq(int left, int right, T lower, T upper) {
    return (freq_dfs(0, left, right, 0, lower, upper));
  }
};


int main() {
  int N;
  cin >> N;
  vector< int > A(N);
  cin >> A;
  vector< int > belong[303030];
  for(int i = 0; i < N; i++) {
    belong[A[i]].emplace_back(i);
  }

  vector< int > add(N + 1);
  vector< int > pos(N);
  int ptr = 0;
  for(int i = 0; i < N; i++) {
    while(ptr < N && add[A[ptr]] == 0) add[A[ptr++]]++;
    pos[i] = ptr - i;
    add[A[i]]--;
  }


  WaveletMatrix< int, 20 > mat(pos);

  UnionFindRange uf(N);
  vector< int > used(N);
  int64 ret = 0;
  for(int i = 1; i <= N; i++) {
    for(auto &j : belong[i]) {
      if(j && used[j - 1]) uf.unite(j, j - 1);
      if(j + 1 < N && used[j + 1]) uf.unite(j, j + 1);
      auto range = uf.range(j);
      int L = max(range.first, j - i + 1);
      int R = min(j, range.second - i + 1) + 1;
      if(L < R) ret += mat.rangefreq(L, R, i, N + 1);
      used[j] = true;
    }
  }

  cout << ret << endl;
}