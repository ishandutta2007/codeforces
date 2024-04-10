#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> u(m), v(m);
    REP(i, m) {
      cin >> u[i] >> v[i]; --u[i]; --v[i];
    }
    vector<bool> used(3 * n, false);
    vector<int> ans;
    REP(i, m) {
      if (!used[u[i]] && !used[v[i]]) {
        ans.emplace_back(i + 1);
        used[u[i]] = true;
        used[v[i]] = true;
      }
    }
    if (ans.size() >= n) {
      ans.resize(n);
      cout << "Matching\n";
      REP(i, n) cout << ans[i] << (i == n - 1 ? '\n' : ' ');
      continue;
    }
    ans.clear();
    REP(i, 3 * n) {
      if (!used[i]) ans.emplace_back(i + 1);
    }
    ans.resize(n);
    cout << "IndSet\n";
    REP(i, n) cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}