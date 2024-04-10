#include<bits/stdc++.h>
using namespace std;

using ll = long long;
template <int MOD> struct modnum {
  int v;
  modnum() : v(0) {}
  modnum(ll v_) : v(v_%MOD) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& o, const modnum& n) { return o << n.v; }
  friend std::istream& operator >> (std::istream& i, modnum& n) { ll v; i >> v; n = modnum(v); return i; }
  
  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

  modnum& operator += (const modnum& o) { v += o.v; if (v >= MOD) v -= MOD; return *this; }
  modnum& operator -= (const modnum& o) { v -= o.v; if (v < 0) v += MOD; return *this; }
  modnum& operator *= (const modnum& o) { v = int(ll(v) * ll(o.v) % MOD); return *this; }
  modnum operator - () { modnum res; if (v) res.v = MOD-v; return res; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
};

using num = modnum<998244353>;
using arr = array<pair<num, num>, 1024>; // count, sum
int msk(ll v) {
  int r = 0;
  while(v) { r |= (1 << (v % 10)); v /= 10; }
  return r;
}
arr dfs(ll a, ll b) {
  arr res;
  assert(a < b);
  if (a / 10 < b / 10) {
    arr tmp = dfs(a / 10, b / 10);
    for (int m = 0; m < 1024; m++) {
      for (int d = 0; d < 10; d++) {
        int nm = m | (1 << d);
        res[nm].first += tmp[m].first;
        res[nm].second += 10 * tmp[m].second + tmp[m].first * d;
      }
    }
    for (ll i = a + 1; i < a / 10 * 10 + 10; i++) {
      int m = msk(i);
      res[m].first += 1;
      res[m].second += i;
    }
    for (ll i = b / 10 * 10; i < b; i++) {
      int m = msk(i);
      res[m].first += 1;
      res[m].second += i;
    }
  } else {
    for (ll i = a + 1; i < b; i++) {
      int m = msk(i);
      res[m].first += 1;
      res[m].second += i;
    }
  }
  return res;
}

int main() {
  ll L, R; cin >> L >> R;
  int K; cin >> K;
  arr res = dfs(L-1, R+1);
  num ans = 0;
  for (int m = 0; m < 1024; m++) {
    if (__builtin_popcount(m) <= K) ans += res[m].second;
  }
  cout << ans << '\n';
}