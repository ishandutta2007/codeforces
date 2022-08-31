#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
//const int mod = 998244353;

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
inline bool chmin(T1 &a, T2 b) {
  if(b < 0)b *= -1;
  return a > b && (a = b, true);
}

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
 * @brief Slope-Trick
 * @docs docs/slope-trick.md
 * @see https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8
 */
template< typename T >
struct SlopeTrick {

  const T INF = numeric_limits< T >::max() / 3;

  T min_f;
  priority_queue< T, vector< T >, less<> > L;
  priority_queue< T, vector< T >, greater<> > R;
  T add_l, add_r;

private:
  void push_R(const T &a) {
    R.push(a - add_r);
  }

  T top_R() const {
    if(R.empty()) return INF;
    else return R.top() + add_r;
  }

  T pop_R() {
    T val = top_R();
    if(not R.empty()) R.pop();
    return val;
  }

  void push_L(const T &a) {
    L.push(a - add_l);
  }

  T top_L() const {
    if(L.empty()) return -INF;
    else return L.top() + add_l;
  }

  T pop_L() {
    T val = top_L();
    if(not L.empty()) L.pop();
    return val;
  }

  size_t size() {
    return L.size() + R.size();
  }

public:
  SlopeTrick() : min_f(0), add_l(0), add_r(0) {}

  struct Query {
    T lx, rx, min_f;
  };

  // return min f(x)
  Query query() const {
    return (Query) {top_L(), top_R(), min_f};
  }

  // f(x) += a
  void add_all(const T &a) {
    min_f += a;
  }

  // add \_
  // f(x) += max(a - x, 0)
  void add_a_minus_x(const T &a) {
    min_f += max(T(0), a - top_R());
    push_R(a);
    push_L(pop_R());
  }

  // add _/
  // f(x) += max(x - a, 0)
  void add_x_minus_a(const T &a) {
    min_f += max(T(0), top_L() - a);
    push_L(a);
    push_R(pop_L());
  }

  // add \/
  // f(x) += abs(x - a)
  void add_abs(const T &a) {
    add_a_minus_x(a);
    add_x_minus_a(a);
  }

  // \/ -> \_
  // f_{new} (x) = min f(y) (y <= x)
  void clear_right() {
    while(not R.empty()) R.pop();
  }

  // \/ -> _/
  // f_{new} (x) = min f(y) (y >= x)
  void clear_left() {
    while(not L.empty()) L.pop();
  }

  // \/ -> \_/
  // f_{new} (x) = min f(y) (x-b <= y <= x-a)
  void shift(const T &a, const T &b) {
    assert(a <= b);
    add_l += a;
    add_r += b;
  }

  // \/. -> .\/
  // f_{new} (x) = f(x - a)
  void shift(const T &a) {
    shift(a, a);
  }

  // L, R 
  T get(const T &x) {
    T ret = min_f;
    while(not L.empty()) {
      ret += max(T(0), pop_L() - x);
    }
    while(not R.empty()) {
      ret += max(T(0), x - pop_R());
    }
    return ret;
  }

  void merge(SlopeTrick &st) {
    if(st.size() > size()) {
      swap(st.L, L);
      swap(st.R, R);
      swap(st.add_l, add_l);
      swap(st.add_r, add_r);
      swap(st.min_f, min_f);
    }
    while(not st.R.empty()) {
      add_x_minus_a(st.pop_R());
    }
    while(not st.L.empty()) {
      add_a_minus_x(st.pop_L());
    }
    min_f += st.min_f;
  }
};

int main() {
  int N;
  cin >> N;
  vector< int64 > X(N + 1), Y(N + 1);
  for(int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    X[i] = x + y;
    Y[i] = x - y;
    Y[i] += X[i];
  }
  N += 1;
  vector< int > ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int a, int b) {
    return X[a] < X[b];
  });
  SlopeTrick< int64 > slope;
  for(int i = 0; i < 2 * N; i++) {
    slope.add_abs(0);
  }
  int ptr = 0, pre = 0;
  for(int i = 1; i < N; i++) {
    slope.shift(0, (X[ord[i]] - X[ord[i - 1]]) * 2);
    slope.add_abs(Y[ord[i]]);
  }
  cout << slope.query().min_f / 2 << "\n";
}