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
long long __lcm(long long a, long long b) { return a / __gcd(a, b) * b; }

bool is_prime(long long num) {
  if (num <= 1) return false;
  for (long long i = 2; i * i <= num; ++i) {
    if (num % i == 0) return false;
  }
  return true;
}

vector<long long> divisor(long long num) {
  vector<long long> res;
  for (long long i = 2; i * i <= num; ++i) {
    if (num % i == 0) {
      res.emplace_back(i);
      if (i * i != num) res.emplace_back(num / i);
    }
  }
  sort(ALL(res));
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> d(n); REP(i, n) cin >> d[i];
    sort(ALL(d));
    if (n == 1) {
      if (is_prime(d[0])) cout << (long long)d[0] * d[0] << '\n';
      else cout << -1 << '\n';
    } else {
      long long ans = (long long)d.front() * d.back();
      vector<long long> di = divisor(ans);
      if (n != di.size()) {
        cout << -1 << '\n';
        continue;
      }
      bool exist = true;
      REP(i, n) {
        if (d[i] != di[i]) {
          cout << -1 << '\n';
          exist = false;
          break;
        }
      }
      if (exist) cout << ans << '\n';
    }
  }
  return 0;
}