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
#include <numeric>
#include <queue>
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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<int> a(m), b(m);
  REP(i, m) {
    cin >> a[i] >> b[i]; --a[i]; --b[i];
  }
  int mx = 1;
  REP(_, n) mx *= 6;
  int ans = 0;
  REP(i, mx) {
    vector<int> node(n);
    int tmp = i;
    REP(j, n) {
      node[j] = tmp % 6;
      tmp /= 6;
    }
    set<pair<int, int> > st;
    REP(j, m) {
      int u = node[a[j]], v = node[b[j]];
      if (u > v) swap(u, v);
      st.emplace(u, v);
    }
    ans = max(ans, (int)st.size());
  }
  cout << ans << '\n';
  return 0;
}