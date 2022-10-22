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
  vector<long long> cnt(n, 0);
  vector<vector<int> > rev(n);
  while (m--) {
    int a, b; cin >> a >> b; --a; --b;
    if (a > b) swap(a, b);
    ++cnt[b];
    rev[a].emplace_back(b);
  }
  vector<long long> middle(n);
  REP(i, n) middle[i] = cnt[i] * rev[i].size();
  long long ans = 0;
  REP(i, n) ans += middle[i];
  cout << ans << '\n';
  int q; cin >> q;
  while (q--) {
    int v; cin >> v; --v;
    ans -= middle[v];
    middle[v] = 0;
    for (int e : rev[v]) {
      ans -= middle[e];
      --cnt[e];
      rev[e].emplace_back(v);
      middle[e] = cnt[e] * rev[e].size();
      ans += middle[e];
    }
    cnt[v] += rev[v].size();
    rev[v].clear();
    cout << ans << '\n';
  }
  return 0;
}