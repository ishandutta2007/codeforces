#include <bits/stdc++.h>

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
  explicit FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}

const string Q = "abc";

int main() {
  int N;
  cin >> N;
  string a, b;
  cin >> a >> b;

  if(b[0] == b[1]) swap(a, b);

  if(a[0] == a[1]) {
    if(b[0] == b[1]) {
      cout << "YES" << endl;
      for(int i = 0; i < 3 * N; i++) cout << "abc"[i % 3];
      cout << endl;
    } else {
      char pur = Q[0] ^Q[1] ^Q[2] ^b[0] ^b[1];
      cout << "YES" << endl;
      for(int i = 0; i < N; i++) {
        cout << pur << b[1] << b[0];
      }
      cout << endl;
    }
  } else {
    char pur = Q[0] ^Q[1] ^Q[2] ^a[0] ^a[1];
    if(a == b) {

      cout << "YES" << endl;
      for(int i = 0; i < N; i++) {
        cout << a[1] << a[0] << pur;
      }
      cout << endl;
    } else if(a[0] == b[1] && a[1] == b[0]) {
      cout << "YES" << endl;
      for(int i = 0; i < N; i++) cout << a[0];
      for(int i = 0; i < N; i++) cout << pur;
      for(int i = 0; i < N; i++) cout << a[1];
      cout << endl;
    } else if(a[1] == b[0]) {
      cout << "YES" << endl;
      for(int i = 0; i < N; i++) {
        if(i % 2) {
          cout << a[1] << a[0] << pur;
        } else {
          cout << a[0] << pur << a[1];
        }
      }
      cout << endl;
    } else if(b[1] == a[0]) {
      swap(a, b);
      cout << "YES" << endl;
      pur = Q[0] ^Q[1] ^Q[2] ^a[0] ^a[1];
      for(int i = 0; i < N; i++) {
        if(i % 2) {
          cout << a[1] << a[0] << pur;
        } else {
          cout << a[0] << pur << a[1];
        }
      }
      cout << endl;
    } else if(a[0] == b[0]) {
      cout << "YES" << endl;
      for(int i = 0; i < N; i++) cout << pur;
      for(int i = 0; i < N; i++) cout << a[1];
      for(int i = 0; i < N; i++) cout << a[0];
      cout << endl;
    } else {
      cout << "YES" << endl;
      for(int i = 0; i < N; i++) cout << a[1];
      for(int i = 0; i < N; i++) cout << pur;
      for(int i = 0; i < N; i++) cout << a[0];
      cout << endl;
    }
  }
}