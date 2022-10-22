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

  int n, k; cin >> n >> k;
  vector<int> s(n), rev(n);
  int sum = 0;
  REP(i, n) {
    char c; cin >> c;
    s[i] = c - '0';
    sum += s[i];
    rev[i] = s[i] ^ 1;
  }
  vector<int> rui(n + 1, 0);
  REP(i, n) rui[i + 1] = rui[i] + s[i];
  vector<int> one, rev_one;
  REP(i, n) {
    if (s[i] == 1) one.emplace_back(i);
    if (rev[i] == 1) rev_one.emplace_back(i);
  }
  bool quailty = true;
  REP(i, n - k + 1) {
    int cnt = rui[i + k] - rui[i];
    if (cnt == sum || sum - cnt == n - k) {
      cout << "tokitsukaze\n";
      return 0;
    }
    bool ok = true;
    // -> 0 / all 0
    int l = (one[0] < i ? 0 : lower_bound(ALL(one), i + k) - one.begin());
    int r = one.size() - 1;
    if (one.back() < i + k) {
      int left = 0, right = one.size() - 1;
      while (right - left > 1) {
        int mid = (left + right) / 2;
        (one[mid] >= i ? right : left) = mid;
      }
      r = left;
    }
    // cout << one[l] << ' ' << one[r] << '|';
    if (one[r] - one[l] + 1 > k) ok = false;
    // -> 1 / all 1
    l = (rev_one[0] < i ? 0 : lower_bound(ALL(rev_one), i + k) - rev_one.begin());
    r = rev_one.size() - 1;
    if (rev_one.back() < i + k) {
      int left = 0, right = rev_one.size() - 1;
      while (right - left > 1) {
        int mid = (left + right) / 2;
        (rev_one[mid] >= i ? right : left) = mid;
      }
      r = left;
    }
    // cout << rev_one[l] << ' ' << rev_one[r] << '\n';
    if (rev_one[r] - rev_one[l] + 1 > k) ok = false;
    quailty &= ok;
  }
  cout << (quailty ? "quailty\n" : "once again\n");
  return 0;
}