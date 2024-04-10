#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
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
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/
vector<pair<long long, int> > prime_factorization(long long num) {
  vector<pair<long long, int> > res;
  for (long long i = 2; i * i <= num; ++i) {
    if (num % i != 0) continue;
    int exponent = 0;
    while (num % i == 0) {
      ++exponent;
      num /= i;
    }
    res.emplace_back(i, exponent);
  }
  if (num != 1) res.emplace_back(num, 1);
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  int sum = 0;
  vector<int> a(n);
  REP(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  sort(ALL(a));
  a.erase(unique(ALL(a)), a.end());
  int sz = a.size();
  if (sz == 1) {
    cout << sum << '\n';
    return 0;
  }
  int ans = sum;
  FOR(i, 2, 101) {
    for (int j = sz - 1; j >= 1; --j) {
      if (a[j] % i == 0) {
        int tmp = sum;
        tmp -= a[j];
        tmp += a[j] / i;
        tmp -= a.front();
        tmp += a.front() * i;
        ans = min(ans, tmp);
        // cout << i << ' ' << ans << '\n';
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}