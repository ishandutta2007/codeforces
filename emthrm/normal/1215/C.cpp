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

  int n; cin >> n;
  string s, t; cin >> s >> t;
  int a = count(ALL(s), 'a') + count(ALL(t), 'a');
  if (a & 1) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> ab, ba;
  REP(i, n) {
    if (s[i] == 'a' && t[i] == 'b') {
      ab.emplace_back(i);
    } else if (s[i] == 'b' && t[i] == 'a') {
      ba.emplace_back(i);
    }
  }
  vector<int> ans_s, ans_t;
  while (ab.size() >= 2) {
    ans_s.emplace_back(ab.back());
    ab.pop_back();
    ans_t.emplace_back(ab.back());
    ab.pop_back();
  }
  while (ba.size() >= 2) {
    ans_s.emplace_back(ba.back());
    ba.pop_back();
    ans_t.emplace_back(ba.back());
    ba.pop_back();
  }
  if (!ab.empty()) {
    assert(!ba.empty());
    ans_s.emplace_back(ab.back());
    ans_t.emplace_back(ab.back());
    ans_s.emplace_back(ba.back());
    ans_t.emplace_back(ab.back());
  }
  int sz = ans_s.size();
  cout << sz << '\n';
  REP(i, sz) cout << ans_s[i] + 1 << ' ' << ans_t[i] + 1 << '\n';
  return 0;
}