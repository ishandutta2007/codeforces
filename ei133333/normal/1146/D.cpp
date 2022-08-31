#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

const int64 infll = 1LL << 60;

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


int64 sum(int64 a, int64 d, int64 n) {
  return (2 * a + (n - 1) * d) * n / 2;
}

int main() {
  int64 M, A, B;
  cin >> M >> A >> B;

  vector< int > dp(200005);
  dp[0] = 1;
  int64 all = 0, ret = 0;
  for(int i = 0; i <= min(200004LL, M); i++) {
    if(dp[i]) {
      queue< int > que;
      que.emplace(i);
      while(que.size()) {
        auto p = que.front();
        que.pop();
        ++all;
        if(p + A < dp.size() && !dp[p + A]) {
          dp[p + A] = true;
          if(p + A <= i) que.emplace(p + A);
        }
        if(p - B >= 0 && !dp[p - B]) {
          dp[p - B] = true;
          que.emplace(p - B);
        }
      }
    }
    ret += all;
  }

  if(M <= 200004) {
    cout << ret << endl;
    return 0;
  }

  int64 gcd = __gcd(A, B);

  ret += sum(1, 1, M / gcd) * gcd;
  ret += (M / gcd + 1) * (M % gcd + 1);
  ret -= sum(1, 1, 200004 / gcd) * gcd;
  ret -= (200004 / gcd + 1) * (200004 % gcd + 1);
  cout << ret << endl;
}