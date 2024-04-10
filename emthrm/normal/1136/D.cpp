#include <algorithm>
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
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-----------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<int> p(n);
  REP(i, n) {
    cin >> p[i];
    --p[i];
  }
  vector<vector<int> > pupil(n);
  REP(i, m) {
    int u, v; cin >> u >> v; --u; --v;
    pupil[u].emplace_back(v);
  }
  set<int> st;
  st.insert(p[n - 1]);
  int ans = 0, now = 1;
  for (int i = n - 2; i >= 0; --i) {
    int res = now;
    for (int e : pupil[p[i]]) {
      if (st.count(e) == 1) --res;
    }
    if (res == 0) {
      ++ans;
    } else {
      st.insert(p[i]);
      ++now;
    }
  }
  cout << ans << '\n';
  return 0;
}