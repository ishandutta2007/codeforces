#include <bits/stdc++.h>

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
  for(T &in: v) is >> in;
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
  for(auto &e: t) fill_v(e, v);
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

void beet() {
  int n;
  cin >> n;
  auto ask = [&](int i, int j, int k) {
    cout << "? " << i << " " << j << " " << k << endl;
    int x;
    cin >> x;
    return x;
  };
  int s = -inf, id1 = -1;
  for(int i = 3; i <= n; i++) {
    int z = ask(1, 2, i);
    if(chmax(s, z)) id1 = i;
  }
  int t = s, id2 = 2;
  for(int i = 3; i <= n; i++) {
    if(id1 == i) continue;
    int z = ask(id1, 1, i);
    if(chmax(t, z)) id2 = i;
  }
  int id3 = -1;
  for(int i = 2; i <= n; i++) {
    if(id1 == i) continue;
    if(id2 == i) continue;
    id3 = i;
    break;
  }
  int X = ask(id1, id2, id3);
  int Y = ask(1, id2, id3);
  int Z = ask(id1, 1, id3);
  int P = max({X, Y, Z});
  if(Y == P) id1 = 1;
  else if(Z == P) id2 = 1;
  cout << "! " << id1 << " " << id2 << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    beet();
  }
}