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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int query(int i, int j, int k) {
  cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
  int r; cin >> r;
  assert(r != -1);
  return r;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  iota(ALL(a), 0);
  while (a.size() > 2) {
    vector<int> b(4);
    REP(i, 4) {
      b[i] = a.back();
      a.pop_back();
    }
    vector<int> c(4);
    REP(i, 4) {
      vector<int> d = b;
      d.erase(d.begin() + i);
      c[i] = query(d[0], d[1], d[2]);
    }
    const int mx = *max_element(ALL(c));
    if (const int ct = count(ALL(c), mx); ct == 4) {
      // do nothing
    } else if (ct == 3) {
      REP(i, 4) {
        if (c[i] != mx) {
          a.emplace_back(b[i]);
          b.erase(b.begin() + i);
          break;
        }
      }
    } else {
      for (int i = int(c.size()) - 1; i >= 0; --i) {
        if (c[i] != mx) {
          a.emplace_back(b[i]);
          b.erase(b.begin() + i);
        }
      }
    }
    if (a.size() == 3) a.emplace_back(b.back());
  }
  cout << "! ";
  if (a.size() == 1) {
    cout << a.front() + 1 << ' ' << a.front() + 1 << endl;
  } else {
    cout << a[0] + 1 << ' ' << a[1] + 1 << endl;
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}