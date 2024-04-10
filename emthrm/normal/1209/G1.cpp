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

  int n, q; cin >> n >> q;
  const int M = 200000;
  vector<int> left(M, INF), right(M, -1), cnt(M, 0), a(n);
  REP(i, n) {
    cin >> a[i];
    left[a[i]] = min(left[a[i]], i);
    right[a[i]] = max(right[a[i]], i);
    ++cnt[a[i]];
  }
  int ans = 0, pos = 0;
  while (pos < n) {
    set<int> st{a[pos]};
    int r = right[a[pos]];
    FOR(i, pos, r + 1) {
      st.emplace(a[i]);
      r = max(r, right[a[i]]);
    }
    int len = r + 1 - pos, mn = len;
    for (int e : st) mn = min(mn, len - cnt[e]);
    ans += mn;
    pos = r + 1;
  }
  cout << ans << '\n';
  return 0;
}