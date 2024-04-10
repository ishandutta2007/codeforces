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
vector<int> solve(vector<int> &a) {
  // for (int e : a) cout << e << ' ';
  // cout << '\n';
  int n = a.size(), start = a.front();
  vector<int> cnt;
  int now = a.front(), tmp = 1;
  FOR(i, 1, n) {
    if (now == a[i]) {
      ++tmp;
    } else {
      cnt.emplace_back(tmp);
      tmp = 1;
      now = a[i];
    }
  }
  cnt.emplace_back(tmp);
  int sz = cnt.size(), hajimari = 0, owari = 0, mx = 0;
  for (int i = 0; i < sz; ) {
    int j = i + 1, kokono = cnt[i];
    while (j < sz) {
      kokono += cnt[j];
      if (cnt[j] == 1) {
        ++j;
        break;
      }
      ++j;
    }
    if (kokono > mx) {
      mx = kokono;
      hajimari = i;
      owari = j;
    }
    if (j == sz) break;
    i = j - 1;
  }
  vector<int> res;
  FOR(i, hajimari, owari) {
    int now = start + i;
    res.emplace_back(now);
  }
  for (int i = owari - 1; i >= hajimari; --i) {
    int now = start + i;
    REP(j, cnt[i] - 1) res.emplace_back(now);
  }
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  sort(ALL(a));
  vector<int> tmp{a.front()}, ans{a.front()};
  FOR(i, 1, n) {
    if (a[i] - tmp.back() <= 1) {
      tmp.emplace_back(a[i]);
    } else {
      vector<int> cand = solve(tmp);
      if (cand.size() > ans.size()) ans = cand;
      tmp.assign(1, a[i]);
    }
  }
  vector<int> cand = solve(tmp);
  if (cand.size() > ans.size()) ans = cand;
  cout << ans.size() << '\n';
  REP(i, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  return 0;
}