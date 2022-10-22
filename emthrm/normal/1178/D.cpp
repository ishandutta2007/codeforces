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
  vector<bool> prime = sieve_of_eratosthenes(n * n);
  vector<int> u, v;
  FOR(i, 1, n) {
    u.emplace_back(i);
    v.emplace_back(i + 1);
  }
  u.emplace_back(n);
  v.emplace_back(1);
  int edge = n, mae = 1, ush = n / 2 + 1;
  while (!prime[edge]) {
    ++edge;
    u.emplace_back(mae);
    v.emplace_back(ush);
    ++mae;
    ++ush;
    if (mae == n / 2 + 1) break;
  }
  if (!prime[edge]) {
    cout << -1 << '\n';
    return 0;
  }
  cout << u.size() << '\n';
  REP(i, u.size()) cout << u[i] << ' ' << v[i] << '\n';
  return 0;
}