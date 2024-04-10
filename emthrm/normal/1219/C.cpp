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

  int l; string a; cin >> l >> a;
  int n = a.length();
  string ans = "";
  if (n % l == 0) {
    string check = "";
    while (check.size() < n) check += '9';
    if (a == check) {
      string base = "1";
      while (base.size() < l) base += '0';
      while (ans.size() <= n) ans += base;
    } else {
      string base = "";
      REP(i, l) base += a[i];
      bool big = false;
      for (int i = l; i < n; i += l) {
        bool end = false;
        REP(j, l) {
          if (a[i + j] > base[j]) {
            end = true;
            break;
          } else if (a[i + j] < base[j]) {
            big = true;
            end = true;
            break;
          }
        }
        if (end) break;
      }
      if (!big) {
        ++base.back();
        for (int i = l - 1; i >= 0; --i) {
          if (base[i] == '9' + 1) {
            base[i] = '0';
            ++base[i - 1];
          } else {
            break;
          }
        }
      }
      while (ans.size() < n) ans += base;
    }
  } else {
    string base = "1";
    while (base.size() < l) base += '0';
    while (ans.size() < n) ans += base;
  }
  cout << ans << '\n';
  return 0;
}