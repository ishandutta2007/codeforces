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

long long nCk[20][20] = {};

void solve() {
  long long k; cin >> k;
  map<int, int> finger;
  int sum = 0;
  for (int i = 2; k > 0; ++i) {
    ++finger[k % i];
    ++sum;
    k /= i;
  }
  long long ans = 1;
  int used = 0;
  for (auto it = prev(finger.end()); ; --it) {
    ans *= nCk[min(sum + 1 - (*it).first, sum) - used][(*it).second];
    used += (*it).second;
    if (it == finger.begin()) break;
  }
  if (finger.count(0) > 0) {
    long long bad = 1;
    used = 0;
    --finger[0];
    for (auto it = prev(finger.end()); ; --it) {
      bad *= nCk[min(sum - (*it).first, sum - 1) - used][(*it).second];
      used += (*it).second;
      if (it == finger.begin()) break;
    }
    ans -= bad;
  }
  cout << ans - 1 << '\n';
}

int main() {
  REP(i, 20) {
    nCk[i][0] = 1;
    FOR(j, 1, i + 1) nCk[i][j] = nCk[i - 1][j - 1] + nCk[i - 1][j];
  }
  int t; cin >> t;
  while (t--) solve();
  return 0;
}