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

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename T, bool isMin >
struct ConvexHullTrick {
#define F first
#define S second
  using P = pair< T, T >;
  deque< P > H;

  bool empty() const { return H.empty(); }

  void clear() { H.clear(); }

  inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }

  using D = long double;

  inline bool check(const P &a, const P &b, const P &c) {
    if(b.S == a.S || c.S == b.S)
      return sgn(b.F - a.F) * sgn(c.S - b.S) >= sgn(c.F - b.F) * sgn(b.S - a.S);

    //return (b.F-a.F)*(c.S-b.S) >= (b.S-a.S)*(c.F-b.F);
    return
        D(b.F - a.F) * sgn(c.S - b.S) / D(abs(b.S - a.S)) >=
        D(c.F - b.F) * sgn(b.S - a.S) / D(abs(c.S - b.S));
  }

  void addLine(T m, T b) {
    if(!isMin) m *= -1, b *= -1;
    P line(m, b);
    if(empty()) {
      H.emplace_front(line);
      return;
    }
    if(H.front().F <= m) {
      if(H.front().F == m) {
        if(H.front().S <= b) return;
        H.pop_front();
      }
      while(H.size() >= 2 && check(line, H.front(), H[1])) H.pop_front();
      H.emplace_front(line);
    } else {
      assert(m <= H.back().F);
      if(H.back().F == m) {
        if(H.back().S <= b) return;
        H.pop_back();
      }
      while(H.size() >= 2 && check(H[H.size() - 2], H.back(), line)) H.pop_back();
      H.emplace_back(line);
    }
  }

  inline T getY(const P &a, const T &x) {
    return a.F * x + a.S;
  }

  T query(T x) {
    assert(!empty());
    int l = -1, r = H.size() - 1;
    while(l + 1 < r) {
      int m = (l + r) >> 1;
      if(getY(H[m], x) >= getY(H[m + 1], x)) l = m;
      else r = m;
    }
    if(isMin) return getY(H[r], x);
    return -getY(H[r], x);
  }

  T queryMonotoneInc(T x) {
    assert(!empty());
    while(H.size() >= 2 && getY(H.front(), x) >= getY(H[1], x)) H.pop_front();
    if(isMin) return getY(H.front(), x);
    return -getY(H.front(), x);
  }

  T queryMonotoneDec(T x) {
    assert(!empty());
    while(H.size() >= 2 && getY(H.back(), x) >= getY(H[H.size() - 2], x)) H.pop_back();
    if(isMin) return getY(H.back(), x);
    return -getY(H.back(), x);
  }

#undef F
#undef S
};

int main() {
  int N, K;
  cin >> N >> K;
  vector< int > A(N);
  cin >> A;


  auto dp = make_v< int >(K, N);
  fill_v(dp, inf);
  {
    int mx = 0;
    for(int i = 0; i < N; i++) {
      chmax(mx, A[i]);
      dp[0][i] = (i + 1) * mx;
    }
  }

  vector< int > mx(N);
  ConvexHullTrick< int64, true > cht;
  function< void(int, int) > rec = [&](int l, int r) {

    if(l >= r) return;

    int mid = (l + r) / 2;

    rec(l, mid);

    //[l,mid]->[mid+1,r]
    {
      int tap = 0;
      for(int i = mid; i >= l; i--) {
        mx[i] = tap;
        chmax(tap, A[i]);
      }
    }

    {
      int tap = 0;
      for(int i = mid + 1; i <= r; i++) {
        chmax(tap, A[i]);
        mx[i] = tap;
      }
    }

    for(int i = 1; i < K; i++) {
      int ptr = mid;
      for(int k = mid + 1; k <= r; k++) {
        while(ptr >= l && mx[ptr] <= mx[k]) {
          cht.addLine(-ptr, dp[i - 1][ptr]);
          --ptr;
        }
        if(ptr != mid) chmin(dp[i][k], cht.queryMonotoneInc(mx[k]) + k * mx[k]);
      }
      cht.clear();
    }


    for(int i = 1; i < K; i++) {
      int ptr = l;
      for(int k = r; k > mid; k--) {
        while(ptr <= mid && mx[ptr] > mx[k]) {
          cht.addLine(mx[ptr], dp[i - 1][ptr] - ptr * mx[ptr]);
          ++ptr;
        }
        if(ptr != l) chmin(dp[i][k], cht.queryMonotoneDec(k));
      }
      cht.clear();
    }


    rec(mid + 1, r);
  };
  rec(0, N - 1);
  cout << dp[K - 1][N - 1] << endl;
}