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
  long long sum = 0;
  vector<int> a(n);
  REP(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum == 1) {
    cout << -1 << '\n';
    return 0;
  }
  vector<long long> tmp = divisor(sum);
  vector<long long> d;
  FOR(i, 1, tmp.size()) {
    bool is_prime = true;
    for (long long e : d) {
      if (tmp[i] % e == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) d.emplace_back(tmp[i]);
  }
  long long ans = LINF;
  for (long long dd : d) {
    long long cnt = 0, tmp = 0;
    vector<int> alice(a);
    for (int i = 0; i < n;) {
      if (alice[i] >= dd) {
        cnt += dd * (alice[i] / dd);
        if (cnt == sum) break;
        alice[i] %= dd;
      }
      if (alice[i] == 0) {
        ++i;
        continue;
      }
      vector<pair<int, long long> > choco;
      int j;
      long long want = dd;
      for (j = i; j < n;) {
        if (alice[j] > want) {
          alice[j] -= want;
          choco.emplace_back(j, want);
          want = 0;
        } else {
          if (alice[j] > 0) {
            want -= alice[j];
            choco.emplace_back(j, alice[j]);
            alice[j] = 0;
          }
          ++j;
        }
        if (want == 0) break;
      }
      int idx, sz = choco.size();
      want = (dd + 1) / 2;
      for (idx = 0; idx < sz; ++idx) {
        want -= choco[idx].second;
        if (want <= 0) break;
      }
      REP(j, idx) tmp += choco[j].second * (choco[idx].first - choco[j].first);
      FOR(j, idx + 1, sz) tmp += choco[j].second * (choco[j].first - choco[idx].first);
      if (tmp >= ans) break;
      cnt += dd;
      if (cnt == sum) break;
      i = j;
    }
    ans = min(ans, tmp);
  }
  cout << ans << '\n';
  return 0;
}