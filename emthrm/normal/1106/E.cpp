#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/
// http://kmjp.hatenablog.jp/entry/2019/02/01/0900
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m, k; cin >> n >> m >> k;
  vector<vector<pair<int, int>>> add(n+1), del(n+1);
  REP(i, k) {
    int s, t, d, w; cin >> s >> t >> d >> w;
    add[s].push_back({w, d});
    del[t].push_back({w, d});
  }
  vector<int> coin(n+1, 0), owaru(n+1);
  FOR(i, 1, n+1) owaru[i] = i+1;
  multiset<pair<int, int>> st;
  FOR(i, 1, n+1) {
    for (auto a : add[i]) st.insert(a);
    if (!st.empty()) {
      coin[i] = st.rbegin()->first;
      owaru[i] = st.rbegin()->second + 1;
    }
    for (auto d : del[i]) st.erase(st.find(d));
  }
  vector<vector<long long> > dp(n+2, vector<long long>(m+1, LINF));
  dp[1][0] = 0;
  FOR(i, 1, n+1) REP(j, m+1) {
    dp[owaru[i]][j] = min(dp[owaru[i]][j], dp[i][j] + coin[i]);
    if (j < m) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
  }
  long long ans = LINF;
  REP(j, m+1) ans = min(ans, dp[n+1][j]);
  cout << ans << '\n';
  return 0;
}