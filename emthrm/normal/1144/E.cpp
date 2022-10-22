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

  int k; cin >> k;
  string s, t; cin >> s >> t;
  vector<int> ss(k), tt(k);
  REP(i, k) {
    ss[i] = s[i] - 'a';
    tt[i] = t[i] - 'a';
  }
  vector<int> mid(k, 0);
  for (int i = k - 1; i >= 0; --i) {
    mid[i] += ss[i] + tt[i];
    if (i > 0 && mid[i] >= 26) {
      mid[i - 1] += mid[i] / 26;
      mid[i] %= 26;
    }
  }
  string ans = "";
  REP(i, k) {
    if (mid[i] & 1) {
      mid[i + 1] += 26;
      --mid[i];
    }
    mid[i] /= 2;
    ans += 'a' + mid[i];
  }
  cout << ans << '\n';
  return 0;

  // string ans = "";
  // for (int i = k - 1; i >= 0; --i) {
  //   int mid = ss[i] + tt[i];
  //   if (mid >= 26) {
  //     ss[i + 1] += mid / 26;
  //     mid %= 26;
  //   }
  //   ans += 'a' + mid / 2;
  // }
  // reverse(ALL(ans));
  // cout << ans << '\n';
  // return 0;

  // long long sss = 0, ttt = 0;
  // REP(i, k) {
  //   sss *= 26;
  //   sss += ss[i];
  //   ttt *= 26;
  //   ttt += tt[i];
  // }
  // long long mid = (sss + ttt) / 2;
  // string ans = "";
  // while (mid > 0) {
  //   ans += 'a' + (mid % 26);
  //   mid /= 26;
  // }
  // while (ans.size() < k) ans += 'a';
  // reverse(ALL(ans));
  // cout << ans << '\n';

  // REP(i, k) cout << ss[i] << ' ';
  // cout << '\n';
  // REP(i, k) cout << tt[i] << ' ';
  // cout << '\n';
}