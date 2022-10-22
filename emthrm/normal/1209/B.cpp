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
#include <numeric>
#include <queue>
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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  string s; cin >> s;
  const int T = 100000;
  vector<int> imos(T, 0);
  REP(i, n) {
    int a, b; cin >> a >> b;
    if (s[i] == '1') {
      ++imos[0];
      --imos[b];
      for (int j = 1; b + j * a < T; j += 2) {
        ++imos[b + j * a];
        if (b + (j + 1) * a < T) --imos[b + (j + 1) * a];
      }
    } else {
      for (int j = 0; b + j * a < T; j += 2) {
        ++imos[b + j * a];
        if (b + (j + 1) * a < T) --imos[b + (j + 1) * a];
      }
    }
  }
  REP(i, T - 1) imos[i + 1] += imos[i];
  int ans = 0;
  REP(i, T) ans = max(ans, imos[i]);
  cout << ans << '\n';
  return 0;
}