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
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
vector<pair<long long, int> > prime_factorization(long long val) {
  vector<pair<long long, int> > res;
  for (long long i = 2; i * i <= val; ++i) {
    if (val % i != 0) continue;
    int exponent = 0;
    while (val % i == 0) {
      ++exponent;
      val /= i;
    }
    res.emplace_back(i, exponent);
  }
  if (val != 1) res.emplace_back(val, 1);
  return res;
}

int main() {
  int n, k; cin >> n >> k;
  map<vector<pair<int, int> >, int> mp;
  long long ans = 0;
  while (n--) {
    int a; cin >> a;
    auto p = prime_factorization(a);
    vector<pair<int, int> > now;
    for (auto &pr : p) {
      pr.second %= k;
      if (pr.second > 0) now.emplace_back(pr);
    }
    vector<pair<int, int> > rev;
    for (auto &pr : now) rev.emplace_back(pr.first, k - pr.second);
    if (mp.count(rev) == 1) ans += mp[rev];
    ++mp[now];
  }
  cout << ans << '\n';
  return 0;
}