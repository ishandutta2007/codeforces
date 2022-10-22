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

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int> > a(m, vector<int>(n)); REP(i, m) REP(j, n) cin >> a[i][j];
  vector<int> ans(m);
  iota(ALL(ans), 0);
  REP(j, n - 1) {
    vector<pair<int, int> > diff(m);
    int sum = 0;
    REP(i, m) {
      diff[i] = {a[i][j] - a[i][n - 1], i};
      sum += diff[i].first;
    }
    sort(diff.rbegin(), diff.rend());
    vector<int> tmp;
    while (sum < 0) {
      sum -= diff.back().first;
      tmp.emplace_back(diff.back().second);
      diff.pop_back();
    }
    if (tmp.size() < ans.size()) ans = tmp;
  }
  sort(ALL(ans));
  cout << ans.size() << '\n';
  REP(i, ans.size()) cout << ans[i] + 1 << (i + 1 == ans.size() ? '\n' : ' ');
  return 0;
}