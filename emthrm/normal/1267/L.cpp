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
  int n, l, k; cin >> n >> l >> k; --k;
  string s; cin >> s;
  sort(ALL(s));
  int idx = 0, same = 0;
  vector<string> ans(n);
  REP(j, l) {
    FOR(i, same, k + 1) ans[i] += s[idx++];
    for (; same < k; ++same) {
      if (ans[same][j] == ans[k][j]) break;
    }
    if (same == k) break;
  }
  while (ans[k].length() < l) ans[k] += s[idx++];
  REP(i, n) {
    while (ans[i].length() < l) ans[i] += s[idx++];
    cout << ans[i] << '\n';
  }
  return 0;
}