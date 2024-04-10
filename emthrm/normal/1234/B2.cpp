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
/*-------------------------------------------------*/
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, k; cin >> n >> k;
  deque<int> deq;
  map<int, bool> mp;
  while (n--) {
    int id; cin >> id;
    if (mp.count(id) == 1) continue;
    mp[id] = true;
    deq.emplace_front(id);
    if (deq.size() > k) {
      mp.erase(deq.back());
      deq.pop_back();
    }
  }
  int ans = deq.size();
  cout << ans << '\n';
  REP(i, ans) {
    cout << deq.front() << (i + 1 == ans ? '\n' : ' ');
    deq.pop_front();
  }
  return 0;
}