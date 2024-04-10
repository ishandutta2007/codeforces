#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

constexpr int B = 17;

int stand(int b, int l, int r) {
  int ans = 0;
  FOR(i, l, r) ans += i >> b & 1;
  return ans;
}

void solve() {
  int l, r; cin >> l >> r;
  vector<int> a(r - l + 1); REP(i, r - l + 1) cin >> a[i];
  sort(ALL(a));
  auto stand2 = [&](int b, int l, int r) -> int {
    int ans = 0;
    FOR(i, l, r) ans += a[i] >> b & 1;
    return ans;
  };
  int x = 0, b = B - 1;
  for (; b >= 0 && (l >> b & 1) == (r >> b & 1); --b) {
    if ((a.front() >> b & 1) != (l >> b & 1)) x |= 1 << b;
  }
  if (b < 0) {
    cout << x << '\n';
    return;
  }
  auto f = [&](int x, int le1, int ri1, int le2, int ri2) -> bool {
    {
      int le = le1, ri = ri1;
      for (int b2 = b - 1; b2 >= 0; --b2) {
        if ((1 << (b2 + 1)) == ri - le) break;
        int flag = 0;
        FOR(i, le, ri) flag += a[i] >> b2 & 1;
        if (flag == 0) {
          x |= 1 << b2;
        } else if (flag == ri - le) {
          // do nothing
        } else if (flag > ri - le - flag) {
          ri = le + (ri - le - flag);
        } else {
          x |= 1 << b2;
          le = ri - flag;
        }
      }
    }
    {
      int le = le2, ri = ri2;
      for (int b2 = b - 1; b2 >= 0; --b2) {
        if ((1 << (b2 + 1)) == ri - le) break;
        int flag = 0;
        FOR(i, le, ri) flag += a[i] >> b2 & 1;
        if (flag == 0) {
          // do nothing
        } else if (flag == ri - le) {
          x |= 1 << b2;
        } else if (flag > ri - le - flag) {
          x |= 1 << b2;
          ri = le + (ri - le - flag);
        } else {
          le = ri - flag;
        }
      }
    }
    vector<int> b(r - l + 1);
    REP(i, r - l + 1) b[i] = a[i] ^ x;
    sort(ALL(b));
    if (b.front() == l && b.back() == r) {
      cout << x << '\n';
      return true;
    } else {
      return false;
    }
  };
  if (const int stand_b = stand(b, l, r + 1); stand_b * 2 == r - l + 1) {
    REP(which, 2) {
      if ((a[0] >> b & 1) ^ which) {
        if (f(x | (which << b), r - l + 1 - stand_b, r - l + 1, 0, r - l + 1 - stand_b)) return;
      } else {
        if (f(x | (which << b), 0, r - l + 1 - stand_b, r - l + 1 - stand_b, r - l + 1)) return;
      }
    }
    assert(false);
  } else if (const int two = stand2(b, 0, r - l + 1); two == stand_b) {
    assert(f(x, 0, r - l + 1 - stand_b, r - l + 1 - stand_b, r - l + 1));
  } else {
    assert(f(x | (1 << b), r - l + 1 - two, r - l + 1, 0, r - l + 1 - two));
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}