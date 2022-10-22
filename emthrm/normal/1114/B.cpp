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
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m, k; cin >> n >> m >> k;
  vector<pair<int, int>> a(n);
  REP(i, n) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(ALL(a), greater<pair<int, int>>());
  long long ans = 0;
  vector<bool> ireru(n, false);
  REP(i, m*k) {
    ans += a[i].first;
    ireru[a[i].second] = true;
  }
  cout << ans << '\n';
  vector<int> ans2;
  int cnt = 0;
  REP(i, n) {
    if (ireru[i]) ++cnt;
    if (cnt == m) {
      ans2.emplace_back(i+1);
      cnt = 0;
    }
  }
  REP(i, k-2) cout << ans2[i] << ' ';
  cout << ans2[k-2] << '\n';
  return 0;
}