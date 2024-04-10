#include <bits/stdc++.h>
using namespace std;

#define FOR(i,m,n) for(int i =(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
};

void solve() {
  int n; cin >> n;
  vector<int> c(n);
  REP(i, n) {
    int ci; cin >> ci; --ci;
    ++c[ci];
  }
  sort(ALL(c), greater<int>());
  while (c.back() == 0) c.pop_back();
  long long ans = n;
  for (int s = c.back() + 1; s >= 2; --s) {
    long long tmp = 0;
    bool ok = true;
    for (int e : c) {
      int now = e / (s - 1), rem = e % (s - 1);
      if (now < rem) {
        ok = false;
        break;
      }
      int full = rem;
      now -= rem;
      int lb = 0, ub = now;
      while (ub - lb > 1) {
        long long mid = (lb + ub) / 2;
        (mid * (s - 1) <= now - mid ? lb : ub) = mid;
      }
      tmp += full + now - lb;
      // cout << full << ' ' << now << ' ' << lb << '\n';
    }
    if (ok) ans = min(ans, tmp);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}