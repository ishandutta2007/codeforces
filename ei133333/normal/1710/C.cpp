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
  for (T &in : v) is >> in;
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
  for (auto &e : t) fill_v(e, v);
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

int main() {
  string S;
  cin >> S;
  for(auto& c : S) c -= '0';
  vector< int > dp(512);
  for(int j = 0; j < 512; j++) {
    bool x_low = (j >> 8) & 1;
    bool y_low = (j >> 7) & 1;
    bool z_low = (j >> 6) & 1;
    bool ab_add = (j >> 5) & 1;
    bool ac_add = (j >> 4) & 1;
    bool bc_add = (j >> 3) & 1;
    bool ab_low = (j >> 2) & 1;
    bool ac_low = (j >> 1) & 1;
    bool bc_low = (j >> 0) & 1;

    // a+b <= c
    bool ab_low_nxt = ab_low;
    if(ab_add) ab_low_nxt = false;
    // a+c <= b
    bool ac_low_nxt = ac_low;
    if(ac_add) ac_low_nxt = false;
    // b+c <= a
    bool bc_low_nxt = bc_low;
    if(bc_add) bc_low_nxt = false;
    dp[j] = not ab_low_nxt and not ac_low_nxt and not bc_low_nxt and x_low and y_low and z_low;
  }
  vector< pair< int, int > > senni[2];
  for(int p = 0; p < 2; p++) {
    for(int j = 0; j < 512; j++) {
      bool x_low = (j >> 8) & 1;
      bool y_low = (j >> 7) & 1;
      bool z_low = (j >> 6) & 1;
      bool ab_add = (j >> 5) & 1;
      bool ac_add = (j >> 4) & 1;
      bool bc_add = (j >> 3) & 1;
      bool ab_low = (j >> 2) & 1;
      bool ac_low = (j >> 1) & 1;
      bool bc_low = (j >> 0) & 1;

      for(int x = 0; x <= 1; x++) {
        for(int y = 0; y <= 1; y++) {
          for(int z = 0; z <= 1; z++) {
            bool x_nxt = x_low;
            bool y_nxt = y_low;
            bool z_nxt = z_low;
            if(x != p) x_nxt = x < p;
            if(y != p) y_nxt = y < p;
            if(z != p) z_nxt = z < p;
            int a = x ^ y;
            int b = x ^ z;
            int c = y ^ z;
            // a+b <= c
            bool ab_nxt = (a + b + ab_add) >= 2;
            bool ab_cur = a ^ b ^ ab_add;
            bool ab_low_nxt = ab_low;
            if(c != ab_cur) ab_low_nxt = ab_cur < c;
            // a+c <= b
            bool ac_nxt = (a + c + ac_add) >= 2;
            bool ac_cur = a ^ c ^ ac_add;
            bool ac_low_nxt = ac_low;
            if(b != ac_cur) ac_low_nxt = ac_cur < b;
            // b+c <= a
            bool bc_nxt = (b + c + bc_add) >= 2;
            bool bc_cur = b ^ c ^ bc_add;
            bool bc_low_nxt = bc_low;
            if(a != bc_cur) bc_low_nxt = bc_cur < a;
            senni[p].emplace_back(x_nxt<<8|y_nxt<<7|z_nxt<<6|ab_nxt<<5|ac_nxt<<4|bc_nxt<<3|ab_low_nxt<<2|ac_low_nxt<<1|bc_low_nxt,j);
          }
        }
      }
    }
  }
  for(int idx = 0; idx < (int) S.size(); idx++) {
    vector< int > dp2(512);
    for(auto& [p,q] : senni[S[idx]]) {
      dp2[q] += dp[p];
      if(dp2[q] >= mod) dp2[q] -= mod;
    }
    dp = dp2;
  }
  cout << dp[1<<8|1<<7|1<<6|1<<2|1<<1|1]<<endl;
}