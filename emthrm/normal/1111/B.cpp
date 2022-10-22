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
int main() {
  // freopen("input.txt", "r", stdin);

  int n, m;
  long long k;
  cin >> n >> k >> m;
  vector<int> a(n);
  double sum = 0;
  REP(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  sort(ALL(a));
  double ans = 0;
  REP(i, m+1) {
    ans = max(ans, (sum + min((long long)m-i, k*(n-i))) / (n-i));
    if (i == n-1) break;
    sum -= a[i];
  }
  printf("%.7f\n", ans);
  return 0;
}