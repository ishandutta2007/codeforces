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

  int n; cin >> n;
  vector<int> c(n), t(n);
  REP(i, n) cin >> c[i];
  REP(i, n) cin >> t[i];
  if (c.front() != t.front() || c.back() != t.back()) {
    cout << "No\n";
    return 0;
  }
  vector<int> c_sa(n-1), t_sa(n-1);
  REP(i, n-1) {
    c_sa[i] = c[i+1] - c[i];
    t_sa[i] = t[i+1] - t[i];
  }
  sort(ALL(c_sa));
  sort(ALL(t_sa));
  if (c_sa == t_sa) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}