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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int f[]{0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

void solve() {
  int h, m; string time; cin >> h >> m >> time;
  auto is_valid = [&](int hour, int minute) {
    if (f[hour % 10] == -1 || f[hour / 10] == -1 || f[minute % 10] == -1 || f[minute / 10] == -1) return false;
    int ref_h = f[minute % 10] * 10 + f[minute / 10];
    int ref_m = f[hour % 10] * 10 + f[hour / 10];
    return ref_h < h && ref_m < m;
  };
  int hour = stoi(time.substr(0, 2)), minute = stoi(time.substr(3, 2));
  while (!is_valid(hour, minute)) {
    ++minute;
    if (minute == m) {
      minute = 0;
      hour = (hour + 1) % h;
    }
  }
  cout << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << minute << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}