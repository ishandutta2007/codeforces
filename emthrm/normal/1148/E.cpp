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
  vector<pair<int, int> > s(n);
  REP(i, n) {
    cin >> s[i].first;
    s[i].second = i;
  }
  sort(ALL(s));
  vector<int> t(n); REP(i, n) cin >> t[i];
  sort(ALL(t));
  vector<int> l, r, ansi, ansj, d;
  REP(i, n) {
    if (s[i].first < t[i]) l.emplace_back(i);
    else if (t[i] < s[i].first) r.emplace_back(i);
  }
  int idx = 0;
  REP(i, l.size()) {
    for (; idx < r.size(); ++idx) {
      int dd = min(t[l[i]] - s[l[i]].first, s[r[idx]].first - t[r[idx]]);
      if (2 * dd > s[r[idx]].first - s[l[i]].first) dd = (s[r[idx]].first - s[l[i]].first) / 2;
      ansi.emplace_back(s[l[i]].second + 1);
      ansj.emplace_back(s[r[idx]].second + 1);
      d.emplace_back(dd);
      s[l[i]].first += dd;
      s[r[idx]].first -= dd;
      if (s[l[i]].first == t[l[i]]) {
        if (s[r[idx]].first == t[r[idx]]) ++idx;
        break;
      }
    }
    if (s[l[i]].first < t[l[i]]) {
      cout << "NO\n";
      return 0;
    }
  }
  if (idx < r.size()) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n" << ansi.size() << '\n';
  REP(i, ansi.size()) cout << ansi[i] << ' ' << ansj[i] << ' ' << d[i] << '\n';
  return 0;
}