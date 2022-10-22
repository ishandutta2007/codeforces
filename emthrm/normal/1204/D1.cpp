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

  string s; cin >> s;
  char now = s[0];
  int cnt = 1;
  vector<pair<char, int> > len;
  FOR(i, 1, s.length()) {
    if (s[i] != now) {
      len.emplace_back(now, cnt);
      cnt = 0;
    }
    now = s[i];
    ++cnt;
  }
  len.emplace_back(now, cnt);
  if (len[0].first == '1') len.insert(len.begin(), make_pair('0', 0));
  int n = len.size();
  // if (n == 1) {
  //   REP(_, s.length()) cout << '0';
  //   cout << '\n';
  //   return 0;
  // }
  vector<int> ori(n), ori0(n), ori1(n);
  for (int i = n - 1; i >= 0; --i) {
    ori1[i] += (i + 1 < n ? ori1[i + 1] : 0);
    if (len[i].first == '0') {
      FOR(j, i, n) ori0[j] += len[i].second;
    } else {
      ori1[i] += len[i].second;
    }
    ori[i] = ori0[i] + ori1[i];
  }
  vector<int> zero(n, 0), one(n, 0);
  for (int i = n - 1; i >= 0; --i) {
    one[i] += (i + 1 < n ? one[i + 1] : 0);
    if (len[i].first == '0') {
      FOR(j, i, n) zero[j] += len[i].second;
    } else {
      one[i] += len[i].second;
    }
    if (len[i].first == '1') {
      bool chance = true;
      FOR(j, i + 1, n) {
        if (zero[j] + one[j] > ori[i]) chance = false;
      }
      if (chance) {
        int plus = len[i].second;
        FOR(j, i + 1, n) plus = min(plus, ori[i] - (zero[j] + one[j]));
        FOR(j, i - 1, n) zero[j] += plus;
        one[i] -= plus;
      }
    }
  }
  string ans = "";
  REP(i, n) {
    // cout << zero[i] << ' ' << one[i] << '\n';
    if (len[i].first == '0') {
      int kaisu = zero[i] - (i - 1 > 0 ? zero[i - 1] : 0);
      REP(_, kaisu) ans += '0';
    } else {
      int kaisu = one[i] - (i + 1 < n ? one[i + 1] : 0);
      REP(_, kaisu) ans += '1';
    }
  }
  cout << ans << '\n';
  return 0;
}