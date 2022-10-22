#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

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
  for (int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for (T &in: v) is >> in;
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
  for (auto &e: t) fill_v(e, v);
}

template< typename F >
struct FixPoint: F {
  explicit FixPoint(F &&f): F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

using pi = pair< int, int >;

void beet() {



  int n;
  cin >> n;
  vector< pi > ps(3);
  cin >> ps;
  int x, y;
  cin >> x >> y;
  int X_low = inf, Y_low = inf;
  for(auto& p : ps) chmin(X_low, p.first);
  for(auto& p : ps) chmin(Y_low, p.second);

  auto V = make_v< int >(2, 2);
  for(auto& p : ps) V[p.first - X_low][p.second - Y_low] = 1;

  bool f = false;
  if(X_low == 1 and Y_low == 1 and !V[1][1]) {
    f |= x == 1;
    f |= y == 1;
  } else if(X_low == n - 1 and Y_low == n - 1 and !V[0][0]) {
    f |= x == n;
    f |= y == n;
  } else if(X_low == 1 and Y_low == n - 1 and !V[1][0]) {
    f |= x == 1;
    f |= y == n;
  } else if(X_low == n - 1 and Y_low == 1 and !V[0][1]) {
    f |= x == n;
    f |= y == 1;
  } else {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if (!V[i][j]) {
          f = !(abs(x - X_low + i) % 2 == 0 and abs(y - Y_low + j) % 2 == 0);
        }
      }
    }
  }
  if (f) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    beet();
  }
}