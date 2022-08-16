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
  int64 l, r;
  cin >> l >> r;

  auto dp = make_v< int64 >(32, 2, 2, 2, 2);
  fill_v(dp, -1);
  auto rec = MFP([&](auto rec, int idx, bool Alow, bool Ahigh, bool Blow, bool Bhigh) -> int64 {
    if(idx == -1) return 1;
    if(~dp[idx][Alow][Ahigh][Blow][Bhigh]) return dp[idx][Alow][Ahigh][Blow][Bhigh];

    bool x = ((l >> idx) & 1);
    bool y = ((r >> idx) & 1);
    int64 ret = 0;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        if(Alow && x > i) continue;
        if(Blow && x > j) continue;
        if(Ahigh && y < i) continue;
        if(Bhigh && y < j) continue;
        if(i == 1 && j == 1) continue;
        ret += rec(idx - 1, Alow && (x == i), Ahigh && (y == i), Blow && (x == j), Bhigh && (y == j));
      }
    }
    return dp[idx][Alow][Ahigh][Blow][Bhigh] = ret;
  });

  cout << rec(31, true, true, true, true) << endl;
}

int main() {
  int T;
  cin >> T;
  while(T--) beet();
}