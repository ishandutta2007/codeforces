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

  int n; cin >> n;
  vector<int> u(n);
  REP(i, n) {
    cin >> u[i];
    --u[i];
  }
  int ans = 1, flag = u.front();
  FOR(i, 1, n) {
    if (u[i] == flag) ++ans;
    else break;
  }
  vector<int> cnt(100000, 0), sum(100001, 0);
  set<int> st;
  REP(i, n) {
    int bef = cnt[u[i]];
    --sum[bef];
    if (sum[bef] == 0) st.erase(bef);
    int aft = ++cnt[u[i]];
    ++sum[aft];
    st.insert(aft);
    if (st.size() == 1) {
      if (*st.begin() == 1) ans = max(ans, i + 1);
    } else if (st.size() == 2) {
      int tmp1 = *st.begin(), tmp2 = *(++st.begin());
      if (sum[tmp1] == 1) {
        if (tmp1 == 1) ans = max(ans, i + 1);
        if (tmp1 - tmp2 == 1) ans = max(ans, i + 1);
      }
      if (sum[tmp2] == 1) {
        if (tmp2 == 1) ans = max(ans, i + 1);
        if (tmp2 - tmp1 == 1) ans = max(ans, i + 1);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}