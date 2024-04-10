#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
template <typename T, typename U>
inline void chmax(T &a, U b) { if (a < b) a = b; }
template <typename T, typename U>
inline void chmin(T &a, U b) { if (a > b) a = b; }

void solve() {
  int n, k, m; cin >> n >> k >> m;
  vector<bool> b(n, false);
  REP(_, m) {
    int bi; cin >> bi; --bi;
    b[bi] = true;
  }
  if ((n - m) % (k - 1) != 0) {
    cout << "NO\n";
    return;
  }
  int l = 0, r = n - 1;
  for (int cnt = 0; cnt < (k - 1) / 2; cnt += !b[l++]);
  for (int cnt = 0; cnt < (k - 1) / 2; cnt += !b[r--]);
  cout << (count(b.begin() + l, b.begin() + r + 1, true) == 0 ? "NO\n" : "YES\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}