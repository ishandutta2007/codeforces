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

  int n, q; cin >> n >> q;
  vector<vector<int> > fence(n + 1);
  REP(i, q) {
    int l, r; cin >> l >> r;
    FOR(j, l, r + 1) fence[j].emplace_back(i);
  }
  int nobody = 0;
  vector<int> one(q, 0);
  vector<vector<int> > two(q, vector<int>(q, 0));
  FOR(i, 1, n + 1) if (fence[i].size() <= 2) {
    if (fence[i].size() == 0) ++nobody;
    else if (fence[i].size() == 1) ++one[fence[i].front()];
    else {
      int ichi = fence[i][0], ni = fence[i][1];
      if (ichi > ni) swap(ichi, ni);
      ++two[ichi][ni];
    }
  }
  int ans = 0;
  REP(i, q) FOR(j, i + 1, q) {
    int painted = n - one[i] - one[j] - two[i][j] - nobody;
    if (painted > 0) ans = max(ans, painted);
  }
  cout << ans << '\n';
  return 0;
}