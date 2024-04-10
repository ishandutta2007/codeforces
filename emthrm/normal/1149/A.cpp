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
vector<bool> sieve_of_eratosthenes(int num) {
  vector<bool> res(num + 1, true);
  if (num >= 0) {
    res[0] = false;
    if (num >= 1) res[1] = false;
  }
  for (int i = 2; i * i <= num; ++i) if (res[i]) {
    for (int j = i * i; j <= num; j += i) res[j] = false;
  }
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  int one = 0, two = 0;
  REP(i, n) {
    int a; cin >> a;
    if (a == 1) ++one;
    else ++two;
  }
  vector<bool> prime = sieve_of_eratosthenes(n * 2 + 2);
  int now = 0;
  vector<int> ans;
  REP(i, n) {
    if (prime[now + 1]) {
      if (one > 0) {
        --one;
        ans.emplace_back(1);
        ++now;
      } else if (two > 0) {
        --two;
        ans.emplace_back(2);
        now += 2;
      }
    } else {
      if (two > 0) {
        --two;
        ans.emplace_back(2);
        now += 2;
      } else if (one > 0) {
        --one;
        ans.emplace_back(1);
        ++now;
      }
    }
  }
  REP(i, n) cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  return 0;
}