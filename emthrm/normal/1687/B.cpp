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

int query(const string& s) {
  cout << "? " << s << endl;
  int r; cin >> r;
  return r;
}

int main() {
  int n, m; cin >> n >> m;
  vector<int> w(m);
  string s(m, '0');
  REP(i, m) {
    s[i] = '1';
    w[i] = query(s);
    s[i] = '0';
  }
  vector<int> ord(m);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](int l, int r) -> bool { return w[l] < w[r]; });
  int ans = 0, prv = 0;
  for (int i : ord) {
    s[i] = '1';
    const int r = query(s);
    if (r == prv + w[i]) {
      prv = r;
    } else {
      s[i] = '0';
    }
  }
  cout << "! " << prv << endl;
  return 0;
}