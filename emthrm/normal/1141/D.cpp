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
  string a, b; cin >> a >> b;
  vector<vector<int> > col_a(26), col_b(26);
  vector<int> que_a, que_b;
  REP(i, n) {
    if (a[i] == '?') que_a.emplace_back(i + 1);
    else col_a[a[i] - 'a'].emplace_back(i + 1);
    if (b[i] == '?') que_b.emplace_back(i + 1);
    else col_b[b[i] - 'a'].emplace_back(i + 1);
  }
  vector<int> ans1, ans2, amari_a, amari_b;
  REP(i, 26) {
    int mn = min(col_a[i].size(), col_b[i].size());
    while (mn--) {
      ans1.emplace_back(col_a[i].back());
      col_a[i].pop_back();
      ans2.emplace_back(col_b[i].back());
      col_b[i].pop_back();
    }
    copy(ALL(col_a[i]), back_inserter(amari_a));
    copy(ALL(col_b[i]), back_inserter(amari_b));
  }
  int mn = min(que_a.size(), amari_b.size() + que_b.size());
  while (mn--) {
    ans1.emplace_back(que_a.back());
    que_a.pop_back();
    if (amari_b.size() > 0) {
      ans2.emplace_back(amari_b.back());
      amari_b.pop_back();
    } else {
      ans2.emplace_back(que_b.back());
      que_b.pop_back();
    }
  }
  mn = min(que_b.size(), amari_a.size() + que_a.size());
  while (mn--) {
    ans2.emplace_back(que_b.back());
    que_b.pop_back();
    if (amari_a.size() > 0) {
      ans1.emplace_back(amari_a.back());
      amari_a.pop_back();
    } else {
      ans1.emplace_back(que_a.back());
      que_a.pop_back();
    }
  }
  int sz = ans1.size();
  cout << sz << '\n';
  REP(i, sz) cout << ans1[i] << ' ' << ans2[i] << '\n';
  return 0;
}