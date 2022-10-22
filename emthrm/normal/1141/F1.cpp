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

  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<long long> sum(n + 1, 0);
  REP(i, n) sum[i + 1] = sum[i] + a[i];
  multimap<long long, pair<int, int> > mp;
  set<long long> st;
  REP(i, n) FOR(j, i, n) {
    mp.insert({sum[j + 1] - sum[i], {j, i}});
    st.insert(sum[j + 1] - sum[i]);
  }
  vector<pair<int, int> > ans;
  for (long long ll : st) {
    auto p = mp.equal_range(ll);
    vector<pair<int, int> > vec;
    for (auto it = p.first; it != p.second; ++it) {
      vec.emplace_back(it->second);
    }
    sort(ALL(vec));
    vector<pair<int, int> > tmp;
    int now = -1;
    REP(i, vec.size()) {
      if (now < vec[i].second) {
        now = vec[i].first;
        tmp.emplace_back(vec[i].second + 1, vec[i].first + 1);
      }
    }
    if (tmp.size() > ans.size()) ans = tmp;
  }
  cout << ans.size() << '\n';
  for (auto e : ans) cout << e.first << ' ' << e.second << '\n';
  return 0;
}