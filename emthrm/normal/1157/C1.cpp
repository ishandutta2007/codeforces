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
  vector<int> a(n); REP(i, n) cin >> a[i];
  int l = 0, r = n - 1, now = 0;
  string ans = "";
  bool which = false;
  REP(i, n - 1) {
    if (a[l] < a[r]) {
      if (now < a[l]) {
        ans += 'L';
        now = a[l];
        ++l;
      } else if (now < a[r]) {
        ans += 'R';
        now = a[r];
        --r;
      } else {
        break;
      }
    } else if (a[l] == a[r]) {
      if (now < a[l]) {
        string left = "", right = "";
        int nownow = now;
        FOR(j, l, r) {
          if (nownow < a[j]) {
            left += 'L';
            nownow = a[j];
          } else {
            break;
          }
        }
        nownow = now;
        for (int j = r; j > l; --j) {
          if (nownow < a[j]) {
            right += 'R';
            nownow = a[j];
          } else {
            break;
          }
        }
        if (left.length() > right.length()) ans += left;
        else ans += right;
      }
      which = true;
      break;
    } else {
      if (now < a[r]) {
        ans += 'R';
        now = a[r];
        --r;
      } else if (now < a[l]) {
        ans += 'L';
        now = a[l];
        ++l;
      } else {
        break;
      }
    }
  }
  if (ans.length() == n - 1 && !which) {
    if (now < a[l]) ans += 'L';
  }
  cout << ans.length() << '\n' << ans << '\n';
  return 0;
}