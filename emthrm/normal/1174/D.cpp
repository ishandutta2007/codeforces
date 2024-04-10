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
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, x; cin >> n >> x;
  if (n == 1 && x == 1) {
    cout << 0 << '\n';
    return 0;
  }
  set<int> st;
  int mx = 1;
  REP(i, n) mx *= 2;
  FOR(i, 1, mx) st.emplace(i);
  st.erase(x);
  vector<int> ruiseki{0};
  while (!st.empty()) {
    int now = *st.begin();
    ruiseki.emplace_back(now);
    st.erase(now);
    st.erase(now ^ x);
  }
  vector<int> ans;
  FOR(i, 1, ruiseki.size()) ans.emplace_back(ruiseki[i] ^ ruiseki[i - 1]);
  cout << ans.size() << '\n';
  REP(i, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  return 0;
}