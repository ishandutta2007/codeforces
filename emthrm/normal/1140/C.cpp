#include <algorithm>
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
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007; // 998244353
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, k; cin >> n >> k;
  vector<int> t(n);
  vector<pair<int, int> > b(n);
  REP(i, n) {
    cin >> t[i] >> b[i].first;
    b[i].second = i;
  }
  sort(ALL(b), greater<pair<int, int> >());
  long long sum = 0, ans = 0;
  priority_queue<int, vector<int>, greater<int> > que;
  REP(i, n) {
    int idx = b[i].second, beautiful = b[i].first;
    sum += t[idx];
    que.emplace(t[idx]);
    if (que.size() > k) {
      sum -= que.top();
      que.pop();
    }
    ans = max(ans, sum * beautiful);
  }
  cout << ans << '\n';
  return 0;
}