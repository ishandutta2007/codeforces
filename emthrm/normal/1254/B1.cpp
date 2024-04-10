#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
vector<long long> divisor(long long val) {
  vector<long long> res;
  for (long long i = 1; i * i <= val; ++i) {
    if (val % i == 0) {
      res.emplace_back(i);
      if (i * i != val) res.emplace_back(val / i);
    }
  }
  sort(ALL(res));
  return res;
}

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int sum = 0;
  REP(i, n) sum += a[i];
  if (sum == 1) {
    cout << -1 << '\n';
    return 0;
  }
  vector<long long> d = divisor(sum);
  d.erase(d.begin());
  long long ans = LINF;
  for (long long dd : d) {
    int cnt = 0;
    long long tmp = 0;
    for (int i = 0; i < n;) {
      vector<int> choco;
      int j;
      for (j = i; j < n; ++j) {
        if (a[j] == 1) {
          choco.emplace_back(j);
          if (choco.size() == dd) break;
        }
      }
      int idx = choco[dd / 2];
      for (int e : choco) tmp += abs(e - idx);
      cnt += dd;
      if (cnt == sum) break;
      i = j + 1;
    }
    ans = min(ans, tmp);
  }
  cout << ans << '\n';
  return 0;
}