#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
//const int mod = 1e9 + 7;
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

int S = 1225;
int dp1[51][2452][2];
int dp2[51][2452][2];

int N, P;

int rec(int, int, bool);

int pref_rec(int idx, int sa, bool lex) { // true
  if(sa + S < 0) {
    return 0;
  }
  if(~dp2[idx + 1][sa + S][lex]) {
    return dp2[idx + 1][sa + S][lex];
  }
  int ret = 0;
  ret += rec(idx, sa, lex);
  ret %= P;
  ret += pref_rec(idx, sa - 1, lex);
  ret %= P;
  return dp2[idx + 1][sa + S][lex] = ret;
}


int tap(int idx, int sa, bool lex) {

}

int rec(int idx, int sa, bool lex) {
  if(idx == -1) {
    return sa > 0 and lex;
  }
  if(~dp1[idx][sa + S][lex]) {
    return dp1[idx][sa + S][lex];
  }
  int range = (N - idx - 1);
  int ret = 0;
  for(int p_i = 0; p_i <= range; p_i++) {

    // [0, p_i)
    ret += pref_rec(idx - 1, sa - 1, true);
    ret %= P;
    ret += P - pref_rec(idx - 1, sa - p_i - 1, true);
    ret %= P;

    // p_i
    ret += rec(idx - 1, sa, lex);
    ret %= P;

    ret += pref_rec(idx - 1, sa + (range - p_i), false);
    ret %= P;
    ret += P - pref_rec(idx - 1, sa, false);
    ret %= P;
  }
  return dp1[idx][sa + S][lex] = ret;
}

int main() {
  cin >> N >> P;
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
  cout << rec(N - 1, 0, false) << "\n";
}